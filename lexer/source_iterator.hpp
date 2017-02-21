#pragma once

namespace Kaleidoscope
{
namespace Lexer
{

/**
 * @brief Source Iterators allow the lexer to accept text from arbitrary
 * sources (file, terminal, etc>), so long as the interface specified in this
 * class is implemented.
 */
class SourceIterator
{
public:
  /**
   * @brief Returns the character that this is pointing it.
   *
   * @return The character this is pointing at
   */
  virtual char operator*() const = 0;

  /**
   * @brief Modifies the state of the iterator to point to the next character in
   * the source; if it is already pointing to the last character, it should
   * point to '\0' instead; if it is already pointing to '\0', the state should
   * not be modified
   *
   * @return this
   */
  virtual SourceIterator *next() = 0;

  /**
   * @brief Modifies the state of the iterator to point to the previous
   * character in the source; if it is already pointing to the frist character,
   * then the state should not be modified
   *
   * @return this
   */
  virtual SourceIterator *previous() = 0;

  virtual SourceIterator *copy() const = 0;

  virtual bool equal(const SourceIterator *) const = 0;
};

} // namespace Lexer
} // namespace Kaleidoscope

