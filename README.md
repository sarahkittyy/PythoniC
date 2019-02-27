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

Let me enjoy my python beauty in peace ok not having to type BS like `std::convoluted_semihemisphere_concavity_iterator` feels really nice.

---
**Q** - Who is this aimed at?

**A** - I made this for fun, and maybe one day a beginner programmer will come from python to C++, and maybe, just *maybe*, this library will help <3

---

**Q** - Why is the src/ dir so empty?

**A** - Most of this library is just composed of template classes & template free functions, so not much can go in the sources.

I keep one source, pythonic.cpp, so that CMake builds the library anyway (for future compatibility).