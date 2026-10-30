# Cpp_Program

一个以 **C++ 学习与练习** 为主的个人代码仓库：内容涵盖数据结构手写实现、经典排序/查找算法、LeetCode 题解（按算法专题分类）、STL 综合小案例以及若干课程实验与控制台管理系统小程序。

## 技术栈

| 类别 | 内容 |
| --- | --- |
| 语言 | C++（使用 `auto`、范围 for、`nullptr`、类内成员初始化等 C++11 及以上特性）；另有 1 个 C 源文件 `test.c` |
| 标准库 | C++ STL：`vector`、`stack`、`queue`、`deque`、`map`/`multimap`、`algorithm`、`fstream`、`string`、`ctime` |
| 编程范式 | 面向过程 + 面向对象（类封装、继承与多态、模板函数） |
| 构建工具 | 仓库内**没有** CMake / Makefile / Visual Studio 工程文件，均为单文件直接编译；git 记录中曾有 `.vscode/tasks.json`（VS Code 编译任务配置），但当前工作区已被删除，内容无法读取 |
| 数据库 | 无。职工管理系统使用 `fstream` 读写本地文本文件 `stafffile.txt` 做持久化 |
| 开发环境 | Visual Studio Code（仓库内保留了 `.vscode` 相关记录）与 Windows 平台（目录中大量 `*.exe` 编译产物） |

规模参考：`*.cpp` 82 个、`*.h` 8 个、`*.c` 1 个（其中 LeetCode 题解 45 个）。

## 目录结构

```text
Cpp_Program/
├── Contact/                      # 通讯录（单链表实现，增删改查）
├── Data_Structure/               # 数据结构基础实现（顺序表/链表/栈/队列/树/图）
├── Experiment_1/                 # 课程实验一（顺序表、链表、有序合并）
├── Experiment_4/                 # 课程实验四（共享栈、队列逆置）
├── LeetCode/                     # 力扣题解，按算法专题分类
│   ├── STL妙用/                  # 栈/队列/矩阵等 STL 技巧题
│   ├── 二分查找/
│   ├── 双指针/
│   ├── 树/
│   ├── 贪心/
│   └── 链表/
├── Practice/                     # 练习代码
│   └── 选择排序int、char数组/     # 函数模板 + 选择排序
├── Search/                       # 查找算法（二分查找、二叉排序树）
├── Sort/                         # 排序算法（冒泡/插入/选择/希尔/堆/快速）
│   └── 快速排序/                  # 快排单文件版本 + 三数取中头文件
├── STL实例/                      # STL 综合小案例
│   ├── STL_员工分组/
│   ├── STL_评委打分/
│   └── 基于STL的演讲比赛流程管理系统/
├── 停车场管理系统/                # 栈 + 队列模拟停车场（含候车场与计费）
├── 基于多态的职工管理系统/         # 继承/多态 + 文件读写
├── test.c                       # 根目录下的 C 语言 Hello World
└── .gitignore                   # 忽略编译产物（*.o/*.exe/*.out/*.dll 等）
```

## 主要功能 / 模块说明

| 模块 | 内容说明 |
| --- | --- |
| `Data_Structure/` | 手写数据结构：`SeqList`（顺序表：插入、删除、按位查找、按值定位）、`LinkList` / `DoubleLinkList`（单链表、双向链表）、`SeqStack` / `LinkStack`（顺序栈、链栈）、`SeqQueue` / `LinkQueue`（顺序队列、链队列）、`BTree`（二叉树的创建、前中后序与层序遍历）、`Graph`（邻接表 + 邻接矩阵，DFS/BFS 遍历）、`AlgoDesign`（交换左右子树、判断二叉排序树等算法设计题） |
| `Sort/` | 六种排序算法各自独立实现：冒泡（带标志位提前退出）、插入、选择、希尔、堆排序、快速排序（含三数取中优化）；`Sort/test.cpp` 通过函数指针统一驱动，并统计各算法在随机数组上的耗时 |
| `Search/` | `Binary.cpp`：二分查找的迭代与递归实现；`BST.cpp`：二叉排序树的插入、查找与遍历 |
| `LeetCode/` | 45 道题解，按专题分目录：STL妙用（有效括号、最小栈、用栈实现队列、合并 K 个有序链表、旋转图像、每日温度等）、二分查找、双指针（滑动窗口最小覆盖子串、两数之和 II 等）、树（对称二叉树、最大深度、平衡二叉树、路径总和 III、二叉树直径）、贪心、链表（反转、合并、环形链表、排序链表等）。文件以 `T<题号>_<英文题名>.cpp` 命名 |
| `STL实例/` | 三个 STL 综合案例：`STL_员工分组`（`vector` + `multimap` 按薪资随机分组）、`STL_评委打分`（`deque` + `sort` 去掉最高最低分求平均）、`基于STL的演讲比赛流程管理系统`（`SpeechManager` 类 + `vector`/`map` 管理选手与比赛轮次） |
| `基于多态的职工管理系统` | `Staff` 基类与 `Employee`/`Manager`/`Boss` 派生类构成多态体系，`StaffManager` 负责菜单交互、增删改查、排序，并通过 `fstream` 把数据保存到 `stafffile.txt`（文件不存在/为空时会给出提示） |
| `停车场管理系统` | 用顺序栈模拟停车场（容量 3）、链队列模拟候车场（容量 4），单价 5 元；实现车辆进出、让路（临时栈中转）、候车车辆自动入场与计费 |
| `Contact/` | 带头结点的单链表通讯录：初始化、显示、按姓名插入/删除/查找、销毁与菜单 |
| `Experiment_1/` | 实验一的三道题：`T_1`（顺序表插入排序建表）、`T_5`（链表相关操作）、`T_6`（两个有序顺序表合并）；目录内附有 `T_1.png` |
| `Experiment_4/` | 实验四：`test4`（两个栈共享同一存储空间、栈顶相向增长的双栈实现）、`STL_test5`（仅用队列和栈把队列元素逆置） |
| `Practice/` | 函数模板练习：用模板化 `Swap` 与 `selectionSort` 对 `int`、`char` 数组排序 |
| `test.c` | 根目录下的独立 C 文件，仅输出 `Hello World!` |

## 运行 / 构建方式

仓库没有统一的构建脚本，各文件基本是"一个 `.cpp` 一个 `main`"的独立小程序，直接用编译器单独编译运行即可：

```bash
# 以 g++（MinGW / MSYS2）为例，编译单个文件
g++ -std=c++11 Data_Structure/SeqList.cpp -o SeqList.exe
./SeqList.exe

# 若使用 MSVC
cl /EHsc /std:c++14 Sort\test.cpp
```

需要特别注意的两个"聚合"入口（它们通过 `#include` 直接包含同目录下的其他 `.cpp`，只需编译入口文件本身）：

```bash
g++ -std=c++11 Sort/test.cpp -o SortTest.exe          # 汇总六种排序并统计耗时
g++ -std=c++11 Data_Structure/AlgoDesign.cpp -o Algo.exe   # 内部 include 了 BTree.cpp
```

其他说明：

- `基于多态的职工管理系统` 需要编译 `StaffManagementSystem.cpp` 与 `staffmanager.cpp`、`employee.cpp`、`manager.cpp`、`boss.cpp` 一起链接（多文件工程），首次运行会在工作目录生成 `stafffile.txt`。
- `STL实例/基于STL的演讲比赛流程管理系统` 同理，需 `SpeechContestManagementSystem.cpp` + `speechManager.cpp` 一起编译。
- 仓库未提供 `CMakeLists.txt`、`Makefile` 或 VS 工程文件，若需要统一构建方式：**待补充**。

## 备注

- 本仓库是**个人学习/练习仓库**，以数据结构课程、C++ 教程（如 STL 案例、职工管理系统、演讲比赛系统）和 LeetCode 刷题记录为主，代码风格偏教学示例，部分函数保留了注释掉的调试代码。
- 目录中散落大量 `*.exe` 编译产物（共 73 个）和 `test.exe`，它们已被 `.gitignore` 的 `*.exe` 规则排除，**未纳入版本控制**。
- 源码文件**编码不统一**：部分文件为 UTF-8（如 `staffmanager.cpp`），部分为 GBK（如 `Data_Structure/SeqList.cpp`），中文注释在编辑器/编译时可能出现乱码，建议统一转码后再使用。
- 当前工作区存在未提交改动（`git status` 显示 `.vscode/tasks.json` 与 `HelloWorld/helloworld.txt` 被删除，`test.c` 未跟踪），本次仅新增本 README，未改动任何其他文件。
- 仓库远程地址为 `https://github.com/A-lioth/Cpp_Program.git`（分支 `main`），代码均为仓库所有者自行编写，未发现第三方库源码。
