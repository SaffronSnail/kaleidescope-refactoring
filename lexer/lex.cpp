#include "lex.hpp"

#include "identifier.hpp"
#include "number.hpp"
#include "string.hpp"

#include <string>

namespace Kaleidoscope
{
namespace Lexer
{

Token *lex(const SourceIterator *begin, const SourceIterator *end)
{
  SourceIterator *current = begin->copy();

  while (isspace(**current))
    current->next();

  if (isalpha(**current))
  {
    String identifier;
    do
    {
      identifier += **current;
      current->next();
    } while (isalnum(**current));

    if (identifier == "def")
      return new Token(Token::Type::def);
    else if (identifier == "extern")
      return new Token(Token::Type::ext);
    else
      return new Identifier(identifier);
  }
  else if (isdigit(**current) || **current == '.')
  {
    String number_as_string;
    do
    {
      number_as_string += **current;
      current->next();
    } while (isdigit(**current) || **current == '.');
    return new Number(strtod(number_as_string.c_str(), nullptr));
  }
  else
  {
    if (**current == '#')
    {
      do
      {
        current->next();
      } while (current != end && **current != '\n' && **current != '\r');

      if (current != end)
        return lex(current, end);
    }

    if (current == end)
      return new Token(Token::Type::eof);
    else
      return new Token(static_cast<Token::Type>(**current));
  }
}

} // namespace Lexer
} // namespace Kaleidoscope

