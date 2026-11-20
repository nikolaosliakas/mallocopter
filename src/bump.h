#ifndef MALLOCOPTER_BUMP_H
#define MALLOCOPTER_BUMP_H

#include "core.h"


namespace mallocsim {
class Bump {
  std::byte *begin_, *cur_, *end_;
public:
  explicit Bump(std::span<std::byte> mem) noexcept :
  // initialise with pointer ---> calc end from initial span pointer
  begin_(mem.data()), cur_(begin_), end_(begin_ + mem.size()){}

  Result allocate(std::size_t n,
                  std::align_val_t al = std::align_val_t{kDefaultAlign}) {
    // get byte value for one type of al
    auto a = static_cast<std::size_t>(al);

    // if not a power of 2
    if (!std::has_single_bit(a)) return std::unexpected(AllocError::bad_alignment);

    // find current place in span
    auto addr = reinterpret_cast<std::uintptr_t>(cur_);
    auto pad = align_up(addr, a) - addr;
    auto room = static_cast<std::size_t>(end_ - cur_);
    if (pad > room || n > room - pad) return std::unexpected(AllocError::out_of_memory);

    // pointer to byte block for user to store values at out
    std::byte *out = cur_ + pad;
    cur_ = out + n;
    return out;
  }
  // not used this strategy is just the fast mechanism.
  void deallocate(void*, std::size_t) noexcept{}
  // check if pointer is within the memory already allocated.
  bool owns(const void *p) const noexcept {return p >= begin_ && p < cur_;}
  void reset() noexcept {cur_ = begin_; } // this is the only reclaim method for allocated memory
  // how many of size_t have been allocated.
  std::size_t used() const noexcept {return cur_ - begin_;}

};
}


#endif // MALLOCOPTER_BUMP_H
