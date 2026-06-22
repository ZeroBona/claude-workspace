"""
课程概览工具 (study)
=====================
读取单元 README、试题库状态、错题库数据，生成课程全景概览或单元详情。
"""

import re
from pathlib import Path
from datetime import date
from typing import Optional

# ======== 路径 ========
KB_ROOT = Path(__file__).resolve().parents[3]
CORE_DIR = KB_ROOT / "01_核心知识库"
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
STAGES = [
    ("第一阶段 · 基础篇", "把编程的地基打牢！", ["01", "02", "03"]),
    ("第二阶段 · 流程控制", "让程序学会思考和重复！", ["04", "05"]),
    ("第三阶段 · 数据组织", "学会处理一堆数据！", ["06", "07"]),
    ("第四阶段 · 进阶编程", "写出更强大的代码！", ["08", "09", "10"]),
    ("第五阶段 · 面向对象与工具", "接触编程界的主流思想！", ["11", "12", "13"]),
    ("第六阶段 · 综合实战", "大展身手的时候到了！", ["14"]),
]


def read_file(path: Path) -> str:
    try:
        return path.read_text(encoding="utf-8")
    except Exception:
        return ""


def get_exam_status() -> dict:
    """返回 { "01": True/False, ... }"""
    status = {}
    for num in UNIT_FOLDERS:
        f = EXAM_DIR / f"{UNIT_FOLDERS[num]}.md"
        status[num] = f.exists() and f.stat().st_size > 0
    return status


def get_error_counts() -> dict:
    """返回 { "01": N, ... }"""
    counts = {}
    for num in UNIT_FOLDERS:
        f = ERROR_DIR / f"{UNIT_FOLDERS[num]}.md"
        if f.exists():
            c = f.read_text(encoding="utf-8")
            counts[num] = len(re.findall(r"### 错题 \d+", c))
        else:
            counts[num] = 0
    return counts


def extract_goals(readme: str) -> list:
    return re.findall(r"✅\s*(.+)$", readme, re.MULTILINE)


# ======== 课程总览 ========

def get_course_overview() -> str:
    exam = get_exam_status()
    errors = get_error_counts()
    total = len(UNIT_FOLDERS)
    done = sum(1 for v in exam.values() if v)
    total_errors = sum(errors.values())
    not_started = sum(1 for n in UNIT_FOLDERS if not exam[n] and errors[n] == 0)

    lines = [
        "╔══════════════════════════════════════╗",
        "║   🎯 C++ 编程入门 · 课程概览          ║",
        "╚══════════════════════════════════════╝",
        "",
        f"📚 共 {total} 个单元 · 面向初一零基础同学",
        "", "🗺️ 学习路线图：", "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", "",
    ]

    for stage_name, stage_desc, nums in STAGES:
        lines.append(f"**{stage_name}**")
        lines.append(f"  *{stage_desc}*")
        for n in nums:
            name = UNIT_NAMES.get(n, "")
            if exam.get(n):
                s = f"  📖 {n}｜{name}    ✅ 已出题"
                if errors.get(n, 0) > 0:
                    s += f" ⚠️{errors[n]}错"
            else:
                s = f"  📖 {n}｜{name}    ⏳ 未开始"
            lines.append(s)
        lines.append("")

    lines += [
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", "",
        "📊 **当前学习进度**",
        f"  已完成：{done}/{total} 单元",
        f"  未开始：{not_started} 单元",
        f"  待复习错题：{total_errors} 道", "",
    ]

    # 找第一个未出题
    next_unit = None
    for n in sorted(UNIT_FOLDERS):
        if not exam[n]:
            next_unit = n
            break

    if next_unit:
        lines += [
            "💡 **下一步建议**",
            f"  从第{next_unit}单元「{UNIT_NAMES.get(next_unit, '')}」开始吧！",
            f'  说「学习{next_unit}」查看详情，或说「出题」生成试卷。', "",
        ]
    elif total_errors > 0:
        lines += [
            "💡 **下一步建议**",
            f"  所有单元已出题，但有 {total_errors} 道错题需要复习！",
            '  说「复习」生成针对性练习吧～', "",
        ]
    else:
        lines += [
            "💡 **下一步建议**", "  所有单元已完成，太棒了！🎉",
            '  可以说「复习」做综合练习巩固知识！', "",
        ]

    lines += ["🌈 学习愉快，加油！🎉", "",
              "💬 想看具体单元？说「学习01」~「学习14」即可～"]
    return "\n".join(lines)


# ======== 单元详情 ========

def get_unit_detail(num: str) -> str:
    folder = UNIT_FOLDERS.get(num)
    if not folder:
        return f"❌ 没有第{num}单元。"

    name = UNIT_NAMES.get(num, f"单元{num}")
    readme = read_file(CORE_DIR / folder / "README.md")
    if not readme:
        return f"❌ 第{num}单元 README.md 不存在。"

    goals = extract_goals(readme)
    tm = re.search(r"\*\*约 (\d+~?\d*) 分钟\*\*", readme)
    est_time = tm.group(1) + " 分钟" if tm else "未知"
    pm = re.search(r"前置要求[：:]\s*(.+?)(?:\n|$)", readme)
    prereq = pm.group(1).strip() if pm else "无特殊要求"

    # 导航
    nav = ""
    nm = re.search(r"## 学习导航\s*\n(.*?)(?:\n## |$)", readme, re.DOTALL)
    if nm:
        nav = nm.group(1).strip()

    exam = get_exam_status()
    errors = get_error_counts()
    has_exam = exam.get(num, False)
    err_count = errors.get(num, 0)

    lines = [
        f"╔══════════════════════════════════════╗",
        f"║  第{num}单元：{name}",
        f"╚══════════════════════════════════════╝", "",
        f"⏱ 预计用时：{est_time}",
        f"📋 前置要求：{prereq}", "",
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", "",
        "🎯 **本单元你将学会：**",
    ]
    for g in goals:
        lines.append(f"  ✅ {g}")
    if not goals:
        lines.append("  （README 中未提取到具体目标）")

    if nav:
        lines += ["", "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", "", "🗺️ **学习路线：**"]
        for ln in nav.split("\n"):
            ln = ln.strip()
            if ln and not ln.startswith("#") and "```" not in ln:
                lines.append(f"  {ln}")

    exam_status = "✅ 已有试题" if has_exam else "⏳ 尚未出题"
    err_status = f" ⚠️ {err_count} 道错题待复习" if err_count > 0 else " ✅ 无错题记录"
    lines += [
        "", "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", "",
        "📊 **当前进度**",
        f"  📄 试题：{exam_status}",
        f"  📕 错题：{err_status}", "",
    ]

    if not has_exam:
        lines.append(f'💡 学完本单元后，说「出题{num}」做个小测试吧！')
    elif err_count > 0:
        lines.append(f'💡 本单元有 {err_count} 道错题，说「复习{num}」巩固一下吧！')
    else:
        lines.append('💡 本单元已掌握，继续学习下一单元吧！')

    lines += ["", "🌈 学习愉快，加油！🎉"]
    return "\n".join(lines)


# ======== CLI ========
if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1:
        print(get_unit_detail(sys.argv[1].zfill(2)))
    else:
        print(get_course_overview())
