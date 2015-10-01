add_executable(map_test main.cpp)

add_test(NAME map_test COMMAND map_test) # this is the command that will be executed to run the test
target_link_libraries(map_test)
