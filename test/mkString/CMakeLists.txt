add_executable(mkString_test main.cpp)

add_test(NAME mkString_test COMMAND mkString_test) # this is the command that will be executed to run the test
target_link_libraries(mkString_test)
