#pragma once

namespace KaleidescopeLang
{
namespace AST
{
  class Base
  {
  public:
    virtual ~Base() {}
    static bool Compare(const Base *lhs, const Base *rhs);

  protected:
    typedef const void *UniqueIdentifier;
    virtual UniqueIdentifier get_unique_identifier() const;
  };
}
}