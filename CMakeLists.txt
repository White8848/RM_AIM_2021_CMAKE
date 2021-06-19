#声明要求的cmake最低版本
cmake_minimum_required( VERSION 3.14 )

# 添加c++11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11" )

# 声明一个cmake工程
PROJECT(RM_AIM_2021)

MESSAGE(STATUS "Project: SERVER") #打印相关消息消息

#查找opencv库文件
find_package( OpenCV REQUIRED )

# 头文件目录
include_directories(
${PROJECT_SOURCE_DIR}/include
include_directories( ${OpenCV_INCLUDE_DIRS} )
/../../../linuxSDK_V2.1.0.20/lib/x86
)

# 收集c/c++文件并赋值给变量SRC_LIST_CPP  ${PROJECT_SOURCE_DIR}代表区当前项目录
FILE(GLOB SRC_LIST_CPP ${PROJECT_SOURCE_DIR}/src/*.cpp)

# 创建共享库/静态库

# 设置路径（下面生成共享库的路径）
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
# 即生成的共享库在工程文件夹下的lib文件夹中
 
set(LIB_NAME aim_main_lib)
# 创建共享库（把工程内的cpp文件都创建成共享库文件，方便通过头文件来调用）
# 这时候只需要cpp，不需要有主函数
# ${PROJECT_NAME}是生成的库名 表示生成的共享库文件就叫做 lib工程名.so
# 也可以专门写cmakelists来编译一个没有主函数的程序来生成共享库，供其它程序使用
# SHARED为生成动态库，STATIC为生成静态库
add_library(${LIB_NAME} STATIC ${SRC_LIST_CPP} ${FORMS})
 
# 链接库文件
# 把刚刚生成的${LIB_NAME}库和所需的其它库链接起来
# 如果需要链接其他的动态库，-l后接去除lib前缀和.so后缀的名称，以链接
# libpthread.so 为例,-lpthread

target_link_libraries(${LIB_NAME} ${OpenCV_LIBS} )
target_link_libraries(${LIB_NAME} pthread dl)
target_link_libraries(${LIB_NAME} MVSDK dl)

# 编译主函数，生成可执行文件
# 先设置路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 可执行文件生成
set(CMAKE_DEBUG_POSTFIX "_d")

add_executable(RM_AIM_2021 ${SRC_LIST_CPP})

# 这个可执行文件所需的库（一般就是刚刚生成的工程的库咯）
target_link_libraries(${PROJECT_NAME} pthread dl ${LIB_NAME})
target_link_libraries(${PROJECT_NAME} opencv_core dl ${LIB_NAME})
target_link_libraries(${PROJECT_NAME} opencv_imgproc dl ${LIB_NAME})
target_link_libraries(${PROJECT_NAME} opencv_highgui dl ${LIB_NAME})
target_link_libraries(${PROJECT_NAME} opencv_calib3d dl ${LIB_NAME})
target_link_libraries(${PROJECT_NAME} opencv_core dl ${LIB_NAME})
