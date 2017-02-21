add_library(lexer identifier.hpp
                  lex.cpp lex.hpp
                  number.hpp
                  source_iterator.hpp
                  token.hpp token.cpp
           )

add_subdirectory(test)

