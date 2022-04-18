cmake_minimum_required(VERSION 3.15)
project(xealous)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DMY_DEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMY_DEBUG")

add_executable(xealous main.cpp SingletonLazy/SingletonLazy.cpp SingletonLazy/SingletonLazy.h 03_FindDuplicate/FindDuplicate.cpp 03_FindDuplicate/FindDuplicate.h 04_FindNum/FindNum.cpp 04_FindNum/FindNum.h 05_ReplaceBlank/ReplaceBlank.cpp 05_ReplaceBlank/ReplaceBlank.h 06_PrintListReversingly/PrintListReversingly.cpp 06_PrintListReversingly/PrintListReversingly.h 07_Tree/Tree.cpp 07_Tree/Tree.h 09_StackToQueue/StackToQueue.cpp 09_StackToQueue/StackToQueue.h 10_Fibonacci/Fibonacci.cpp 10_Fibonacci/Fibonacci.h)
