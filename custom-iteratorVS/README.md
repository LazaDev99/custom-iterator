# 🌀 Custom C++ Iterator with Performance Comparison

This repository demonstrates a custom implementation of bidirectional iterators (`Iterator` and `ReverseIterator`) 
for a user-defined container class `MyContainer`, using pointer arithmetic and CRTP (Curiously Recurring Template Pattern).  

It also includes a **performance test** comparing this implementation to standard STL iterators (`std::vector::iterator`) using one million elements.

---

## ✨ Features

- ✅ Custom forward and reverse iterators  
- ✅ Shared logic through `IteratorBase` using CRTP  
- ✅ Clean API: `begin()`, `end()`, `rbegin()`, `rend()`  
- ✅ Supports range-style iteration  
- ✅ Efficient memory usage (no memory leaks, no unnecessary copies)  
- ✅ Performance tests

---

## 🧪 Performance Output (example)

```bash
Custom-made Iterator need: 26 milliseconds
STL iterator need: 109 milliseconds
2 3 4 5 6
6 5 4 3 2
