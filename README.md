# PythoniC

The fluidity of python, in C++.

## Building

```bash
mkdir build && cd build
cmake ..
make
```

## Usage

Link the pythonic library in build/ and `#include <PythoniC/PythoniC.hpp>`

## Features

* Python 3's `range()`
```cpp
for(auto i : py::range(10))
{
	//...i = 0, 1, 2, 3, ... 9 
}
```
* `map()`, `filter()`, and `reduce()`
```cpp
//0, 1, 2, 3, 4, ... 9
py::range list(10);
//0, 2, 4, 6, ... 18
list = py::map([](int x) { return x * 2; }, list);
//Output: 90
std::cout << py::reduce([](int x, int y) { return x + y; }, list);
```
* Python-based list splicing.
```cpp
//0, 1, 2, ... 19
py::range list(20);
 //Output: [19, 18, 17 ... 0]
std::cout << list["::-1"];
```

## Documentation

Run `doxygen` in the main source directory.

## Speed

Probably about the least optimized code on github, but it's readable!

## Never Asked Questions (N.A.Q)
---
**Q** - Why can't I just use the `<algorithm>` header for like, everything?

**A**: `std::transform(__INPUT____PREDICATE___BEGIN__ITERATOR_GCC_WHATEVER VALUE)`
vs
`py::map()`

Let me enjoy my python beauty in peace, OK? Not having to type BS like, `std::convoluted_semihemisphere_concavity_iterator` feels awfully nice.

---
**Q** - Who is this aimed at?

**A** - I made this for fun, and maybe one day a beginner programmer will come from python to C++, and maybe, just *maybe*, this library will help <3

---

**Q** - Why is the src/ dir so empty?

**A** - Most of this library is just composed of template classes & template free functions, so not much can go in the sources.