"""
试题工具 (exam)
===============
检查试题状态、管理试题库索引、提取单元内容。
"""

import re
from pathlib import Path
from typing import Optional

# ======== 路径 ========
KB_ROOT = Path(__file__).resolve().parents[3]
CORE_DIR = KB_ROOT / "01_核心知识库"
EXAM_DIR = KB_ROOT / "05_学习系统" / "01_试题库"

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


# ======== 试题状态 ========

def exam_exists(num: str) -> bool:
    """检查指定单元的试题是否已存在"""
    folder = UNIT_FOLDERS.get(num)
    if not folder:
        return False
    f = EXAM_DIR / f"{folder}.md"
    return f.exists() and f.stat().st_size > 0


def all_exam_status() -> dict:
    """返回所有单元试题状态 { "01": True/False, ... }"""
    return {num: exam_exists(num) for num in sorted(UNIT_FOLDERS)}


def first_missing() -> Optional[str]:
    """找到第一个未出题的单元编号"""
    for num in sorted(UNIT_FOLDERS):
        if not exam_exists(num):
            return num
    return None


# ======== 单元内容 ========

def read_unit_content(num: str) -> dict:
    """读取单元的教学内容"""
    folder = UNIT_FOLDERS.get(num)
    if not folder:
        return {}
    base = CORE_DIR / folder
    return {
        "num": num,
        "name": UNIT_NAMES.get(num, f"单元{num}"),
        "readme": read_file(base / "README.md"),
        "lecture": read_file(base / "01_讲解.md"),
        "code": read_file(base / "02_代码示例.md"),
        "exercises": read_file(base / "03_练习题.md"),
    }


def extract_key_points(text: str) -> list:
    """从讲解文本提取知识点标题"""
    if not text:
        return []
    return [h.strip() for h in re.findall(r"^#{2,3}\s+(.+)$", text, re.MULTILINE) if h.strip()]


def extract_goals(readme: str) -> list:
    """从 README 提取学习目标"""
    return re.findall(r"✅\s*(.+)$", readme, re.MULTILINE)


# ======== 试题库索引 ========

def build_index() -> str:
    """生成试题库 README.md 的内容"""
    status = all_exam_status()
    lines = [
        "# 试题库 📝\n",
        "按核心知识库单元顺序出题，学完一个单元就做对应的试题。\n",
        "## 出题规则\n",
        "- 每单元题量：约 20~25 题",
        "- 题型：选择题 + 填空题 + 判断题 + 编程题",
        "- 难度分层：基础 60% + 进阶 30% + 挑战 10%\n",
        "## 试题列表\n",
        "| 单元 | 状态 |",
        "|------|------|",
    ]
    for num in sorted(UNIT_FOLDERS):
        mark = "✅ 已出" if status[num] else "⏳ 待出"
        lines.append(f"| {UNIT_NAMES.get(num, num)} | {mark} |")
    lines.append(f"\n> 说「出题」自动出下一套未出的试题，说「出题03」出指定单元的题。\n")
    return "\n".join(lines)


def save_index():
    """更新试题库索引文件"""
    (EXAM_DIR / "README.md").write_text(build_index(), encoding="utf-8")


# ======== CLI ========
if __name__ == "__main__":
    import sys
    if "--check-all" in sys.argv:
        for num, exists in all_exam_status().items():
            mark = "✅" if exists else "⏳"
            print(f"  {mark} {UNIT_NAMES.get(num, num)}")
    elif "--missing" in sys.argv:
        m = first_missing()
        print(f"第一个未出题单元：{UNIT_NAMES.get(m, '')}" if m else "🎉 全部已出题！")
    elif len(sys.argv) > 1:
        num = sys.argv[1].zfill(2)
        if exam_exists(num):
            print(f"✅ 第{num}单元「{UNIT_NAMES.get(num, '')}」已有试题，可说批改{num}批改。")
        else:
            name = UNIT_NAMES.get(num, f"单元{num}")
            content = read_unit_content(num)
            points = extract_key_points(content.get("lecture", ""))
            goals = extract_goals(content.get("readme", ""))
            print(f"📄 第{num}单元「{name}」尚未出题")
            if points:
                print(f"知识点：{'、'.join(points[:5])}")
            if goals:
                print(f"目标：{'、'.join(goals[:3])}")
    else:
        print(f"用法：python exam_utils.py <编号|--check-all|--missing>")
