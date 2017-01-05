#include "get-token.hpp"

#include <stdio.h>
#include <cctype>
#include <cstdlib>

namespace KaleidescopeLang
{

template <typename Predicate>
static char slurp(String &buffer, Predicate p)
{
  char next;
  for (next = getchar();
       p(next);
       buffer += next
      );
  return next;
}


Token *get_token()
{
  static char last_character = ' ';

  // skip any whitespace
  while (isspace(last_character))
    last_character = getchar();

  if (isalpha(last_character)) // identifier: [a-zA-z][a-zA-Z0-9]*
  {
    String identifier(last_character);
    last_character = slurp(identifier, isalnum);

    if (identifier == "def")
      return new Token(Token::tok_def);
    else if (identifier == "extern")
      return new Token(Token::tok_extern);
    else
      return new Identifier(identifier);
  }
  else if (isdigit(last_character) || last_character == '.') // Number: [0-9.]+
  {
    String num_str(last_character);
#   warning 1.23.45 will be improperly read as the numerals .123 and .45

    auto predicate = [] (char c) { return isdigit(c) || c == '.'; };
    last_character = slurp(num_str, predicate);
    return new Numeral(strtod(num_str.c_str(), 0));
  }
  else
  {
    if (last_character == '#')
    {
      // comment until end of line
      do
        last_character = getchar();
      while (last_character != EOF && last_character != '\n' &&
                                      last_character != '\r'
            );

      if (last_character != EOF)
        return get_token();
    }

    // Check for end of file. Don't eat the EOF
    if (last_character == EOF)
      return new Token(Token::tok_eof);

    char this_character = last_character;
    last_character = getchar();
    return new Token((Token::Tag)this_character);
  }
}

} // namespace KaleidescopeLang

