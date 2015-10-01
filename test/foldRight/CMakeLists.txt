add_executable(foldRight_test main.cpp)

add_test(NAME foldRight_test COMMAND foldRight_test) # this is the command that will be executed to run the test
target_link_libraries(foldRight_test)
