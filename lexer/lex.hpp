#pragma once

#include "source_iterator.hpp"
#include "token.hpp"

#include <utility>

namespace Kaleidoscope
{
namespace Lexer
{
  /**
   * @brief Lexes the next token from the source pointed to by begin
   *
   * @param begin the current position in the source to lex
   * @param one past the last valid position to lex; normally, it points
   * to a marker at the end of the source (pointing to the NULL at the
   * end of a c-style string, for instance)
   *
   * @return a token lexed from the position begin, stopping at position
   * end
   */
  Token *lex(SourceIterator *begin, SourceIterator *end);

} // namespace Lexer
} // namespace Kaleidoscope

