add_executable(zip_test main.cpp)

add_test(NAME zip_test COMMAND zip_test) # this is the command that will be executed to run the test
target_link_libraries(zip_test)
