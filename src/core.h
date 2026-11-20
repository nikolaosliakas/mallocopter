#ifndef MYAPP_CORE_H
#define MYAPP_CORE_H
#include <expected>
#include <cstddef>
#include <concepts>
#include <bit>
#include <array>
#include <memory_resource>
#include <cstdint>
#include <span>
#include <utility>

namespace mallocsim {
enum class AllocError { out_of_memory, bad_alignment};

// maybe use something else than generic pointer for exprected result
using Result = std::expected<void *, AllocError>;
constexpr std::size_t kDefaultAlign = alignof(std::max_align_t);

constexpr std::size_t align_up(std::size_t n, std::size_t a) noexcept {
  return (n + a - 1) & ~(a - 1); // test for a power of two
}


template <class A>
concept Allocator = requires(A a, std::size_t n, std::align_val_t al, void *p)
{ {a.allocate(n, al)} -> std::same_as<Result>;
  {a.deallocate(p, n)} -> std::same_as<void>;
  // make a non-modifiable from the caller to then call .owns(p) to see pointer within allocated memory
  {std::as_const(a).owns(p)} -> std::convertible_to<bool>;
};

}

#endif // MYAPP_CORE_H
