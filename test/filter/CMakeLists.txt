add_executable(filter_test main.cpp)

add_test(NAME filter_test COMMAND filter_test) # this is the command that will be executed to run the test
target_link_libraries(filter_test)
