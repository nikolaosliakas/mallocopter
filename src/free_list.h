#ifndef MALLOCOPTER_FREE_LIST_H
#define MALLOCOPTER_FREE_LIST_H

#include "core.h"



namespace mallocsim {

  template <std::size_t BlockSize>
  class FreeListPool {
    struct Node {Node* next; };
    static constexpr std::size_t kBlock = align_up(
      std::max(BlockSize, sizeof(Node))
      , kDefaultAlign);
    Node* head_ = nullptr;
    class Bump; // forward declaration
    Bump backing_;
  public:
    explicit FreeListPool(std::span<std::byte> mem) noexcept : backing_(mem){}

    Result allocate(std::size_t n, std::align_val_t = std::align_val_t{kDefaultAlign}) {

      if (n > kBlock) return std::unexpected(AllocError::out_of_memory);
      if (head_) {
        auto* p = head_;
        head_ = p->next;
        return p;
      }
      return backing_.allocate(kBlock);
    }
    void deallocate(void* p, std::size_t) {
      auto* n = static_cast<Node*>(p); // default the size to uniform Node size
      // pop from list.
      n->next =head_;
      head_ = n;
    }
    bool owns(const void *p) const noexcept  {return backing_.owns(p);}

  };

}


#endif
