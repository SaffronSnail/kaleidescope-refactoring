#pragma once

#include "lexer/lex.hpp"
using namespace Kaleidoscope::Lexer;

#include "lexer/identifier.hpp"
#include "lexer/number.hpp"

#include "gtest/gtest.h"
#include <string>

std::ostream &operator<<(std::ostream &os, const Token &tok)
{
  os << "Token of type " << tok.type;
  return os;
}

typedef std::string String;

class StringSource : public SourceIterator
{
public:
  StringSource(String str) : source(str), pos(0)
  {}

  virtual char operator*() const
  {
    return source[pos];
  }

  virtual SourceIterator *next()
  {
    if (pos < source.length())
      ++pos;
    return this;
  }

  virtual SourceIterator *previous()
  {
    if (pos > 0)
      --pos;
    return this;
  }

  virtual SourceIterator *copy() const
  {
    return new StringSource(source);
  }

  StringSource end() const
  {
    StringSource other(source);
    other.pos = source.length();
    return other;
  }

  virtual bool equal(const SourceIterator *other_as_parent) const
  {
    const StringSource *other =
      dynamic_cast<const StringSource *>(other_as_parent);

    if (other == nullptr)
      return false;
    else
      return source == other->source &&
             pos == other->pos;
  }

private:
  const String source;
  size_t pos;
};

#define TEST_SAME_TOKEN(testtype, expected, result) testtype##_TRUE(equivalent_tokens(expected, result)) << "expected is " << to_string((expected)->type) << ", actual is " << to_string((result)->type) << "\n";
#define EXPECT_SAME_TOKEN(expected, result) TEST_SAME_TOKEN(EXPECT, expected, result)
#define ASSERT_SAME_TOKEN(expected, result) TEST_SAME_TOKEN(ASSERT, expected, result)
// this is useful when you have a string that you want to parse one token
// out of; it creates the test, lexes once, and expects it to be the specified
// token
#define SIMPLE_TOKEN_TEST(test_name, string_to_parse, expected_token)\
  TEST(lexer, test_name)\
  {\
    StringSource test_target(string_to_parse);\
    StringSource end = test_target.end();\
    Token *result = lex(&test_target, &end);\
    auto expected = expected_token;\
    EXPECT_SAME_TOKEN(&expected, result);\
  }

static const Token end_tok = Token(Token::Type::eof);
SIMPLE_TOKEN_TEST(finds_end, "", end_tok);
SIMPLE_TOKEN_TEST(ignore_whitespace,
           "        \t\t\t\t\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n",
           end_tok
)
SIMPLE_TOKEN_TEST(ignore_comment, "# this is a comment", end_tok)

SIMPLE_TOKEN_TEST(parse_integer, "500", Number(500))
SIMPLE_TOKEN_TEST(parse_rational, "123.456", Number(123.456))

SIMPLE_TOKEN_TEST(pase_keyword_def, "def", Token(Token::Type::def))
SIMPLE_TOKEN_TEST(parse_keyword_ext, "extern", Token(Token::Type::ext))

SIMPLE_TOKEN_TEST(parse_alpha_identifier, "foobar", Identifier("foobar"))
SIMPLE_TOKEN_TEST(parse_alnum_identifier, "f00b4r", Identifier("f00b4r"))

SIMPLE_TOKEN_TEST(parse_unregistered_character, "<",
                  Token(static_cast<Token::Type>('<'))
)

TEST(lexer, parses_multiple_tokens)
{
  StringSource test_target("  500 anIdentifier another1dent1f1er          # end with a comment");
  StringSource end = test_target.end();
  Token *results[] = { new Number(500), new Identifier("anIdentifier"), new Identifier("another1dent1f1er"), new Token(Token::Type::eof) };
  for (Token *correct_value : results)
  {
    Token *received_value = lex(&test_target, &end);
    EXPECT_SAME_TOKEN(correct_value, received_value);
  }
}

