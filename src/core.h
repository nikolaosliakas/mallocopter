#ifndef MYAPP_CORE_H
#define MYAPP_CORE_H
#include <expected>
#include <cstddef>
#include <span>

namespace mallocsim {
enum class AllocError { out_of_memory, bad_alignment};

// maybe use something else than generic pointer for exprected result
using Result = std::expected<void *, AllocError>;
constexpr std::size_t kDefaultAlign = alignof(std::max_align_t);

constexpr std::size_t align_up(std::size_t n, std::size_t a) noexcept {
  return (n + a - 1) & ~(a - 1); // test for a power of two
}

// TODO create concept here.

}

#endif // MYAPP_CORE_H
