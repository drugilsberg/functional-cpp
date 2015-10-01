add_executable(foldLeft_test main.cpp)

add_test(NAME foldLeft_test COMMAND foldLeft_test) # this is the command that will be executed to run the test
target_link_libraries(foldLeft_test)
