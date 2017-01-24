#pragma once

#include "expression.hpp"

#include "prototype.hpp"
#include "string.hpp"

namespace Kaleidoscope
{
namespace Parse
{

class Function
{
public:
  Function(std::unique_ptr<Prototype> prototype,
           std::unique_ptr<Expression> body)
    : prototype(prototype), body(body)
  {}

private:
  std::unique_ptr<Prototype> prototype;
  std::unique_ptr<Expression> body;
};

} // namespace Parse
} // namespace Kaleidoscope


