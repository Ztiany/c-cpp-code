cmake_minimum_required(VERSION 3.10)

# 获取当前项目目录名，存储到 ProjectId
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# 替换掉下划线
string(REPLACE " " "_" ProjectId ${ProjectId})

# 定义一个项目
project(${ProjectId})
message(ProjectId =  ${ProjectId})

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 获取当前项目目录下所有 .cpp 文件
set(CURRENT_CHAPTER ./)
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_CHAPTER}/*.cpp")

link_directories(D:/dev_tools/msys64/mingw64/lib)

# 将每个文件添加为可执行程序
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    message(add-executable: ${file})
    add_executable(${name} ${file})
    target_link_libraries(${name} zmq)
endforeach ()
