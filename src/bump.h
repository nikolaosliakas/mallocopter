#ifndef MALLOCOPTER_BUMP_H
#define MALLOCOPTER_BUMP_H
#include <cstddef>
#include <span>

class Bump {
  std::byte *begin_, *cur_, *end_;
public:
  explicit Bump(std::span<std::byte> mem) noexcept :
  begin_(mem.data()), cur_(begin_), end_(begin_ + mem.size()){}

};


#endif // MALLOCOPTER_BUMP_H
