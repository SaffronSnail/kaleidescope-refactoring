add_executable(lexer-test main.cpp)
target_link_libraries(lexer-test gtest_main lexer)
add_test(NAME lexer-test-tgt COMMAND lexer-test)

