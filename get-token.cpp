#include "get-token.hpp"

#include <cassert>
#include <cctype>

namespace KaleidescopeLang
{

template <typename Predicate>
static size_t slurp(const char *buffer, Predicate p)
{
  size_t end = 0;

  for (char current = *(buffer + end);
       current != '\0' && p(current);
       ++end
      );
  
  return end;
}

Token *get_token(const char *buffer, size_t *tok_end)
{
  // skip any whitespace
  while (isspace(*buffer))
    ++buffer;

  if (*buffer == '\0')
    return new Token(Token::eof);
  else if (isalpha(*buffer)) // identifier: [a-zA-z][a-zA-Z0-9]*
  {
    *tok_end = slurp(buffer, isalnum);
    String identifier(buffer, *tok_end);
    if (identifier == "def")
      return new Token(Token::def);
    else if (identifier == "extern")
      return new Token(Token::k_extern);
    else
      return new Identifier(identifier);
  }
  else if (isdigit(*buffer) || *buffer == '.') // Number: [0-9.]+
  {
#   warning parsing bug: 1.23.45 will be improperly read as the numerals 1.23 and .45
    auto predicate = [] (char c) { return isdigit(c) || c == '.'; };
    *tok_end = slurp(buffer, predicate);
    return new Numeral(strtod(String(buffer, *tok_end).c_str(),
                              0)
                      );
  }
  else if (*buffer == '#')
  {
    // comment until end of line
    auto predicate = [] (char c) { return c != EOF && c != '\n' && c != '\r'; };
    *tok_end = slurp(buffer, predicate);
    return new Comment(String(buffer, *tok_end));
  }
  else
  {
    *tok_end = 1;
    return new Token((Token::Tag)*buffer);
  }
}

} // namespace KaleidescopeLang

