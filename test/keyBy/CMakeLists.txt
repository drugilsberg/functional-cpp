add_executable(keyBy_test main.cpp)

add_test(NAME keyBy_test COMMAND keyBy_test) # this is the command that will be executed to run the test
target_link_libraries(keyBy_test)
