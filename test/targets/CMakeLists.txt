add_executable(run_endlessly run_endlessly.cpp)
add_executable(end_immediately end_immediately.cpp)
add_executable(reg_write reg_write.s)
add_executable(reg_read reg_read.s)
add_executable(hello_kdebugger hello_kdebugger.cpp)

target_compile_options(reg_write PRIVATE -pie)
target_compile_options(reg_read PRIVATE -pie)
