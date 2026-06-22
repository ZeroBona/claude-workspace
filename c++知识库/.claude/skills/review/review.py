"""
复习工具 (review)
=================
读取错题库、分析薄弱点、生成复习建议。
"""

import re
from pathlib import Path
from datetime import date
from collections import Counter
from typing import Optional

# ======== 路径 ========
KB_ROOT = Path(__file__).resolve().parents[3]
ERROR_DIR = KB_ROOT / "05_学习系统" / "02_错题库"
REVIEW_DIR = KB_ROOT / "05_学习系统" / "03_复习卷"

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


def read_file(path: Path) -> str:
    try:
        return path.read_text(encoding="utf-8")
    except Exception:
        return ""


# ======== 解析错题 ========

def parse_errors(content: str) -> list:
    """解析错题文件内容为结构化列表"""
    errors = []
    blocks = re.split(r"### 错题 \d+", content)
    blocks = [b.strip() for b in blocks if b.strip()]

    for block in blocks:
        err = {}
        for field, key in [
            ("学生", "student"), ("日期", "date"), ("题型", "section"),
            ("题号", "qnum"), ("我的答案", "student_answer"),
            ("正确答案", "correct_answer"), ("知识点", "knowledge"),
        ]:
            m = re.search(rf"\*\*{field}\*\*：(.+)", block)
            if m:
                val = m.group(1).strip()
                if key == "qnum":
                    try:
                        val = int(val.replace("第","").replace("题",""))
                    except ValueError:
                        pass
                err[key] = val
        if err:
            errors.append(err)
    return errors


def read_errors(num: str) -> list:
    """读取指定单元的错题列表"""
    f = ERROR_DIR / f"{UNIT_FOLDERS.get(num, num)}.md"
    if not f.exists():
        return []
    return parse_errors(f.read_text(encoding="utf-8"))


def read_all_errors() -> dict:
    """读取所有单元的错题"""
    result = {}
    for num in sorted(UNIT_FOLDERS):
        errs = read_errors(num)
        if errs:
            result[num] = errs
    return result


# ======== 统计分析 ========

def analyze(errors: list) -> dict:
    """分析错题数据"""
    if not errors:
        return {"total": 0, "by_section": {}, "by_knowledge": {}, "summary": "暂无错题 🎉"}

    sections = Counter()
    knowledge = Counter()
    for e in errors:
        sections[e.get("section", "未知")] += 1
        kw = e.get("knowledge", "待补充")
        if kw and kw != "待补充":
            knowledge[kw] += 1

    top_sec = sections.most_common(5)
    top_kw = knowledge.most_common(5)

    # 生成文字摘要
    parts = [f"共 {len(errors)} 道错题。"]
    if top_sec:
        parts.append(f"薄弱题型：{'、'.join(f'{s[0]}（错{s[1]}次）' for s in top_sec[:3])}。")
    if top_kw:
        parts.append(f"薄弱知识点：{'、'.join(f'{k[0]}⚠️' if k[1]>=2 else k[0] for k in top_kw[:3])}。")

    return {
        "total": len(errors),
        "by_section": dict(sections),
        "by_knowledge": dict(knowledge),
        "top_sections": top_sec,
        "top_knowledge": top_kw,
        "summary": " ".join(parts),
    }


def get_analysis(num: Optional[str] = None) -> dict:
    """获取错题分析结果"""
    if num:
        errs = read_errors(num)
        result = analyze(errs)
        result["unit_num"] = num
        result["unit_name"] = UNIT_NAMES.get(num, f"单元{num}")
        return result

    all_data = read_all_errors()
    all_errs = []
    unit_stats = {}
    for unum, errs in all_data.items():
        unit_stats[unum] = {"count": len(errs), "name": UNIT_NAMES.get(unum, f"单元{unum}")}
        all_errs.extend(errs)

    result = analyze(all_errs)
    result["by_unit"] = unit_stats
    result["unit_count"] = len(unit_stats)
    return result


# ======== 复习卷管理 ========

def ensure_review_dir():
    REVIEW_DIR.mkdir(parents=True, exist_ok=True)


def review_filename(num: Optional[str] = None) -> str:
    if num:
        return f"复习_{UNIT_FOLDERS.get(num, num)}.md"
    return f"复习_综合_{date.today().isoformat()}.md"


def save_review(filename: str, content: str) -> Path:
    ensure_review_dir()
    p = REVIEW_DIR / filename
    p.write_text(content, encoding="utf-8")
    return p


# ======== CLI ========
if __name__ == "__main__":
    import sys
    if "--all" in sys.argv or len(sys.argv) < 2:
        a = get_analysis()
        print(f"📊 错题分析报告（全部）")
        print(f"总错题数：{a['total']}")
        if a.get("by_unit"):
            print("按单元：")
            for unum, st in a["by_unit"].items():
                print(f"  {st['name']}: {st['count']}道")
        print(a.get("summary", ""))
    else:
        num = sys.argv[1].zfill(2)
        a = get_analysis(num)
        print(f"📊 错题分析 - {a.get('unit_name', '')}")
        print(a.get("summary", ""))
