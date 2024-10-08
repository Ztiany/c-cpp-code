#[[
CMake 命令：

    1. CMake 程序完全由命令调用构成。CMake 程序中的 if 条件分支、for 循环等程序结构统一采用命令调用形式。
    2. CMake 的命令名称不区分大小写，一般使用小写。

CMake 命令的参数：

    ● 如果有多个参数，不同于其他编程语言常用逗号分隔参数，在 CMake 中应当使用空格或换行符等空白符将它们分隔开。

CMake 命令参数的类型：

    ● 引号参数 (quoted argument)；
    ● 非引号参数 (unquoted argument)；
    ● 括号参数 (bracket argument)。
]]

# 输出：abc
message(a b c)


#[[ 引号参数：引号参数是用引号包裹在内的参数，而且 CMake 规定它必须使用双引号。]]
message("
我是引号参数，
可以自由换行。
")


# 在引号参数中，代码行末的反斜杠 \ 可以避免参数内容中出现换行。换句话说，反斜杠后的换行符将被忽略。
message("
我是引号参数，\
可以自由换行。\
")


#[[
非引号参数：
    1. 非引号参数自然指未被引号包裹的参数。这种参数中不能包含任何空白符，也不能包含圆括号、#符号、双引号和反斜杠，除非经过转义。
    2. 非引号参数也支持变量引用和转义字符。
    3. 实际上，非引号参数在被传递前，会被当作 CMake 列表来处理，而列表中的每一个元素都会作为一个单独的参数传递给命令。
    4. CMake 中，使用 ; 好来分割列表的各个元素。
]]


message("x;y;z") # 这是引号参数
message(x y z) # 这是多个非引号参数
# 对于非引号参数 x;y;z 来说，虽然它在语法上是一个非引号参数，但在实际传递给命令时，由于列表语法的存在，其中的每个元素都会作为独立的参数来传递。
message(x;y;z) # 这是一个非引号参数


#[[
括号参数：

    - CMake 的括号参数也会作为一个整体传递给命令。括号参数类似 C++11 中的原始字符串字面量(raw string literal)，
      通过自定义的特殊括号将原始文本包括在其中。它不处理文本中的任何特殊字符（包括转义字符）或变量引用语法，直接保留原始文本。
    - 括号参数的语法结构与括号注释十分相近，唯一的区别就是括号参数的起始标记没有 #.
]]
message([===[
abc
def
]===])

message([===[abc
def
]===])

message([===[
随便写终止方括号并不会导致文本结束，
因此右边这两个括号]]也会包括在原始文本中。
下一行中最后的括号也是原始文本的一部分，
因为等号的数量与起始括号不匹配。]==]
]===])
