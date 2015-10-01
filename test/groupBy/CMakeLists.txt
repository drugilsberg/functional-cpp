add_executable(groupBy_test main.cpp)

add_test(NAME groupBy_test COMMAND groupBy_test) # this is the command that will be executed to run the test
target_link_libraries(groupBy_test)
