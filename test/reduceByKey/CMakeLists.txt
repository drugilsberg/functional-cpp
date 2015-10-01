add_executable(reduceByKey_test main.cpp)

add_test(NAME reduceByKey_test COMMAND reduceByKey_test) # this is the command that will be executed to run the test
target_link_libraries(reduceByKey_test)
