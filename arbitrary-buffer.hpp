// Note that this file is in the style of llvm code to make it consistent
// with the MemoryBuffer interface

#include <MemoryBuffer.h>

template <typename Element>
class ArbitraryBuffer
{
public:
  const Element *getBufferStart()
  {
    return reinterpret_cast<Element *>(delegate.getBufferStart());
  }

  explicit operator MemoryBuffer()
  {
    return delegate;
  }

private:
  MemoryBuffer delegate;
};