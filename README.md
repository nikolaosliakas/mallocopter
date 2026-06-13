# mallocopter
Memory allocator for learning!

## Table of Contents
1. [Background](#Background)
2. [Project Structure](#Project-Structure)

## Background

### What is a Memory Allocator?
Memory is provided to programs via a **user-space memory allocator**. Memory is generally split into two spaces. Kernel-space is reserved for the operating system's kernel, kernel processes and most device drivers. User-space is where other applications and processes interact with the memory of their programs. The interactions with this space are mediated by a memory allocator. 

    A memory allocator is a group of a os tools used to manage computer memory. 
    It provides ways to 'dynamically allocate portions of memory to programs at their request, and free it for reuse when no longer needed'.

Each operating system provides a default allocator to user-programs. 

| Opsys   | Default Alloc Name             |
|---------|--------------------------------|
| Linux   | `ptmalloc` inside `glibc`      |
| MacOS   | `libmalloc` inside `libSystem` |
| Windows | `HeapAlloc`                    |

### Why create this repo?

As my journey into C++ progressed, understanding of memory allocation became fundamental. I believed I needed to create a project that could function as an emulator for my conceptual understanding of memory allocation. So, `mallocopter` started from watching Dave Plummer's [video][1] on the memory allocator system tool `malloc` available to programs in an operating system.

This repository will begin with a simple memory allocator and then review some of the strategies used after bump-allocation to manage memory. 

### Project Plan
1. Bump allocator
2. Strategies review (Fit allocations, free lists, coalescing and bucketing)
3. Doug Lea [A Memory Allocator][2] review!
## Implementation

A RAM memory emulator operated on by commands written in C++.

## Repository Structure

    /include # interfaces
    /src # source for apps
    /tests # main.cpp

<!--------Links--->
[1]:https://www.youtube.com/watch?v=mYBxnojY-JA
[2]:https://gee.cs.oswego.edu/dl/html/malloc.html