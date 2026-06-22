"""
批改工具 (grade)
================
解析学生答案、算分、记录错题、生成成绩报告。
"""

import re
from pathlib import Path
from datetime import date
from typing import Optional

# ======== 路径 ========
KB_ROOT = Path(__file__).resolve().parents[3]
EXAM_DIR = KB_ROOT / "05_学习系统" / "01_试题库"
ERROR_DIR = KB_ROOT / "05_学习系统" / "02_错题库"

# ======== 单元映射 ========
UNIT_FOLDERS = {
    "01": "01_编程初识与C++入门", "02": "02_变量与数据类型",
    "03": "03_运算符与表达式", "04": "04_分支结构",
    "05": "05_循环结构", "06": "06_数组", "07": "07_字符串",
    "08": "08_函数", "09": "09_指针与引用", "10": "10_结构体与枚举",
    "11": "11_面向对象入门", "12": "12_文件操作", "13": "13_STL基础",
    "14": "14_综合实战",
}
UNIT_NAMES = {
    "01": "编程初识与C++入门 🚀", "02": "变量与数据类型 📦",
    "03": "运算符与表达式 ➕➖✖️➗", "04": "分支结构 🛤️",
    "05": "循环结构 🔄", "06": "数组 📊", "07": "字符串 🔤",
    "08": "函数 🔧", "09": "指针与引用 📍", "10": "结构体与枚举 📋",
    "11": "面向对象入门 🎯", "12": "文件操作 📁", "13": "STL基础 🧰",
    "14": "综合实战 🏆",
}

# 评分规则
SCORE_RULES = {
    "选择题": {"count": 10, "score_per": 3},
    "判断题": {"count": 10, "score_per": 2},
    "填空题": {"count": 6, "score_per": 3},
    "读程序题": {"count": 3, "score_per": 4},
    "编程题": {"count": 2, "score_per": 10},
}
GRADE_LEVELS = [
    (90, "A（优秀 🌟）"),
    (80, "B（良好 👍）"),
    (60, "C（及格 💪）"),
    (0,  "D（需努力 📖）"),
]


# ======== 答案提取 ========

def pick_choice(s: str) -> Optional[str]:
    """从（ B ）提取 B"""
    m = re.search(r"[（(]\s*([A-Za-z])\s*[）)]", s)
    return m.group(1).upper() if m else None

def pick_judge(s: str) -> Optional[str]:
    """从（ 1 ）提取 1/0"""
    m = re.search(r"[（(]\s*([012])\s*[）)]", s)
    return m.group(1) if m else None

def pick_fill(s: str) -> Optional[str]:
    """填空题：若 ____ 已被替换则返回内容"""
    if "____" in s:
        return None
    s = s.strip()
    return s if s else None

def pick_code(s: str) -> Optional[str]:
    """读程序/编程题：若 ______ 已被替换则返回"""
    if "______" in s:
        return None
    s = s.strip()
    return s if s else None


SECTION_PARSERS = {
    "选择题": pick_choice,
    "判断题": pick_judge,
    "填空题": pick_fill,
    "读程序题": pick_code,
    "编程题": pick_code,
}

SECTION_KEYS = list(SCORE_RULES.keys())

def is_section_header(line: str) -> Optional[str]:
    """判断是否为题型标题行，返回题型名或 None"""
    for key in SECTION_KEYS:
        if key in line:
            return key
    return None


# ======== 提取学生答案 ========

def extract_answers(content: str) -> dict:
    """
    从试题文件中提取学生填写答案。
    返回 { "选择题": {1: "B", 2: "C", ...}, ... }
    """
    answers = {}
    cur_section = None
    qnum = 0

    for line in content.split("\n"):
        raw = line.strip()

        # 题型标题
        sec = is_section_header(raw)
        if sec:
            cur_section = sec
            qnum = 0
            if sec not in answers:
                answers[sec] = {}
            continue

        if cur_section is None:
            continue

        # 题号行
        m = re.match(r"第?(\d+)[.、)）]\s*", raw)
        if m:
            qnum = int(m.group(1))
            if qnum not in answers[cur_section]:
                answers[cur_section][qnum] = None

        # 提取答案
        parser = SECTION_PARSERS.get(cur_section)
        if parser and qnum > 0:
            ans = parser(raw)
            if ans is not None:
                answers[cur_section][qnum] = ans

    return answers


# ======== 评分 ========

def grade(answers: dict, key: dict) -> dict:
    """
    批改评分。
    answers: 学生答案
    key: 标准答案（格式相同）
    返回 { "sections": {...}, "total_score": N, "total_base": N, "rate": N, "level": "...", "errors": [...] }
    """
    total_score = 0
    total_base = 0
    all_errors = []
    sections = {}

    for section, rule in SCORE_RULES.items():
        student = answers.get(section, {})
        correct = key.get(section, {})
        sp = rule["score_per"]

        ok = bad = skip = 0
        errs = []
        all_nums = sorted(set(list(student.keys()) + list(correct.keys())))

        for qn in all_nums:
            sa = student.get(qn)
            ca = correct.get(qn)
            if sa is None:
                skip += 1
            elif ca is None:
                ok += 1  # 无标准答案（编程题），默认给分
            elif str(sa).strip().upper() == str(ca).strip().upper():
                ok += 1
            else:
                bad += 1
                errs.append({"num": qn, "student": str(sa).strip(), "correct": str(ca).strip()})

        done = ok + bad
        sec_score = ok * sp
        sec_base = done * sp if done > 0 else rule["count"] * sp
        sections[section] = {
            "correct": ok, "wrong": bad, "unanswered": skip,
            "score": sec_score, "total": sec_base if sec_base > 0 else rule["count"] * sp,
        }
        total_score += sec_score
        total_base += sec_base if sec_base > 0 else rule["count"] * sp
        for e in errs:
            e["section"] = section
            all_errors.append(e)

    rate = (total_score / total_base * 100) if total_base > 0 else 0
    level = "D（需努力 📖）"
    for threshold, lvl in GRADE_LEVELS:
        if rate >= threshold:
            level = lvl
            break

    return {
        "sections": sections,
        "total_score": total_score,
        "total_base": total_base,
        "rate": round(rate, 1),
        "level": level,
        "errors": all_errors,
        "error_count": len(all_errors),
    }


# ======== 错题记录 ========

def save_errors(num: str, errors: list, student_name: str = "同学", content: str = ""):
    """将错题追加到错题库"""
    if not errors:
        return
    err_file = ERROR_DIR / f"{UNIT_FOLDERS.get(num, num)}.md"
    today = date.today().isoformat()

    existing = ""
    if err_file.exists():
        existing = err_file.read_text(encoding="utf-8")
    existing_count = len(re.findall(r"### 错题 \d+", existing))

    new_blocks = []
    for err in errors:
        existing_count += 1
        block = (
            f"### 错题 {existing_count}\n"
            f"- **学生**：{student_name}\n"
            f"- **日期**：{today}\n"
            f"- **题型**：{err['section']}\n"
            f"- **题号**：第{err['num']}题\n"
            f"- **我的答案**：{err.get('student', '未填')}\n"
            f"- **正确答案**：{err.get('correct', '未知')}\n"
            f"- **知识点**：待补充\n"
            f"- **订正**：待补充\n"
        )
        new_blocks.append(block)

    with open(err_file, "a", encoding="utf-8") as f:
        f.write("\n".join(new_blocks))

    _update_error_index()


def _update_error_index():
    """更新错题库 README.md"""
    lines = [
        "# 错题库 📕\n",
        "每次批改后，答错的题目会自动记录到这里。\n",
        "## 错题本列表\n",
        "| 单元 | 错题数 | 最后更新 |",
        "|------|--------|---------|",
    ]
    for num in sorted(UNIT_FOLDERS):
        f = ERROR_DIR / f"{UNIT_FOLDERS[num]}.md"
        if f.exists():
            c = f.read_text(encoding="utf-8")
            cnt = len(re.findall(r"### 错题 \d+", c))
            dates = re.findall(r"\*\*日期\*\*：(\d{4}-\d{2}-\d{2})", c)
            last = dates[-1] if dates else "-"
            lines.append(f"| {UNIT_NAMES.get(num, num)} | {cnt} | {last} |")
        else:
            lines.append(f"| {UNIT_NAMES.get(num, num)} | 0 | - |")
    lines.append(f"\n> 说「复习」可针对错题生成巩固练习。\n")
    (ERROR_DIR / "README.md").write_text("\n".join(lines), encoding="utf-8")


# ======== 成绩报告 ========

def report(student_name: str, unit_num: str, result: dict) -> str:
    """生成格式化的成绩报告"""
    uname = UNIT_NAMES.get(unit_num, f"单元{unit_num}")
    lines = [
        "╔═══════════════════════════╗",
        f"║  成绩报告                  ║",
        f"║  单元：{uname}",
        f"║  姓名：{student_name}",
        "╠═══════════════════════════╣",
    ]
    for sec, data in result["sections"].items():
        parts = []
        if data["correct"] > 0: parts.append(f"✅{data['correct']}")
        if data["wrong"] > 0: parts.append(f"❌{data['wrong']}")
        if data["unanswered"] > 0: parts.append(f"空{data['unanswered']}")
        status = "+".join(parts) if parts else "全部未做"
        lines.append(f"║  {sec:<8} {status:<14} {data['score']}/{data['total']}")

    lines += [
        f"║  ──────────────            ",
        f"║  得分：{result['total_score']} / {result['total_base']}",
        f"║  得分率：{result['rate']}%",
        f"║  等级：{result['level']}",
        "╚═══════════════════════════╝",
        "",
        f"错题数：{result['error_count']} 道（已记入错题库）",
    ]
    return "\n".join(lines)


# ======== CLI ========
if __name__ == "__main__":
    import sys
    if len(sys.argv) < 2:
        print("用法：python grader.py <单元编号> [学生姓名]")
    else:
        num = sys.argv[1].zfill(2)
        name = sys.argv[2] if len(sys.argv) > 2 else "同学"
        f = EXAM_DIR / f"{UNIT_FOLDERS.get(num, num)}.md"
        if not f.exists():
            print(f"❌ 第{num}单元还没有试题，请先出题。")
        else:
            content = f.read_text(encoding="utf-8")
            answers = extract_answers(content)
            total_q = sum(len(q) for q in answers.values())
            answered = sum(1 for sec in answers.values() for q, a in sec.items() if a is not None)
            print(f"📝 第{num}单元 · 学生：{name}")
            print(f"提取到 {answered}/{total_q} 个答案")
            print("（标准答案由系统内部生成，完整批改请调用 skill）")
