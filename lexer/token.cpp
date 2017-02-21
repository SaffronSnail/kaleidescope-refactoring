#include "token.hpp"

#include <cassert>

namespace Kaleidoscope
{
namespace Lexer
{
bool Token::equal(const Token *other) const
{
  assert(type == other->type);
  return true;
}

bool equivalent_tokens(const Token *lhs, const Token *rhs) {
  if (lhs->type != rhs->type)
    return false;
  else
    return lhs->equal(rhs);
}

String to_string(Token::Type t)
{
#define CASE(tok_name) case Token::Type::tok_name: return #tok_name;
  switch (t)
  {
  CASE(eof);
  CASE(def);
  CASE(ext);
  CASE(identifier);
  CASE(number);
  CASE(comment);

  default:
    return String(1, static_cast<char>(t));
  }
}

} // namespace Lexer
} // namespace Kaleidoscope

