#pragma once

#include "base.hpp"

bool KaleidescopeLang::AST::Base::Compare(const Base * lhs, const Base * rhs)
{
  return lhs->get_unique_identifier() == rhs->get_unique_identifier();
}

KaleidescopeLang::AST::Base::UniqueIdentifier KaleidescopeLang::AST::Base::get_unique_identifier() const
{
  return this;
}
