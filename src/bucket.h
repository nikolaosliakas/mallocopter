#ifndef MALLOCOPTER_BUCKET_H
#define MALLOCOPTER_BUCKET_H

#include "core.h"

namespace mallocsim {

class Bucketed {
  struct Node {Node* next;};
  // 1 KiB to 16 B of
  static constexpr std::size_t kClasses = static_cast<std::size_t>(10) - static_cast<std::size_t>(4) + 1;
  // boundary for largest shift.

  // Find method for sorting size request allocation into buckets using bit shifts
  // TODO: TWo functions size of each bucket/ find class and a size to send to backing to allocate.
  class Bump;
  Bump backing_;
public:
  explicit Bucketed(std::span<std::byte> mem) noexcept : backing_(mem){}

  // TODO: allocate, deallocate
  bool owns(const void *p) const noexcept  {return backing_.owns(p);}

};

}





#endif
