#pragma once

#include "source_iterator.hpp"
#include "token.hpp"

namespace Kaleidoscope
{
namespace Lexer
{

Token *lex(SourceIterator *begin, SourceIterator *end);

} // namespace Lexer
} // namespace Kaleidoscope

