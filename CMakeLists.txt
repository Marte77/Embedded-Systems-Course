cmake_minimum_required(VERSION 3.26)
project(a1)

set(CMAKE_CXX_STANDARD 17)

set(SYSTEMC_HOME "/opt/homebrew/opt/systemc")

include_directories(${SYSTEMC_HOME}/include)
link_directories(${SYSTEMC_HOME}/lib)

include_directories("/Users/marte/Library/CloudStorage/OneDrive-Aarhusuniversitet/1 ano/2 semestre/Embedded Real Time Systems/systemc.visualizer-master/src")

add_executable(a1 main.cpp
                nonassignment_exs/simple_process_ex.cpp
                nonassignment_exs/simple_process_ex.h
        ex1lec4slides/top.h
        ex1lec4slides/monitor.h
        ex1lec4slides/stimulus.h
        ex1lec4slides/stimulus.cpp
        ex1lec4slides/mac.h
        ex1lec4slides/mac.cpp
        assignmentcode/31/ModuleSingle.h
        assignmentcode/32/ModuleDouble.h
        assignmentcode/33/ModuleTCP.h
        assignmentcode/33/TopTCP.h
        assignmentcode/34/AvalonSTTop.h
        assignmentcode/34/ModuleMaster.h
        assignmentcode/34/conf.h
        assignmentcode/34/ModuleSlave.h
        assignmentcode/35/InAdapter.h
)
target_link_libraries(a1 systemc)