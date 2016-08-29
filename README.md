# hour_glass

This is a PoC (Proof of Concept) using Rust as a Backend for C++.

This is based upon the work of [Alex's Rust FFI Examples](https://github.com/alexcrichton/rust-ffi-examples/).

## How it works

* The rust library is included as a static library.
* The C++ facade lives inside the `rust::` namespace.
* A C++ `std::unique_ptr` manages the pointer to the Rust `IntSorter` ensuring it will never pass a nullpointer to the Rust functions. This prevents undefined behavior.

![hg_pic.png](hg_pic.png)

# Contributions

If you would like to add/fix or change something, send a PR or open an issue.

# Running your self

Run:

```
make clean all optimized
```

For a debug build run:
```
make clean all
```

## Requirements

* `make`
* `clang` or `clang++` or `gcc` or `g++` with at least c89 and c++11. You may mix the compilers, please run `make clean` when switching.
* `cargo` and `rustc` >= 1.11.0

## Expected output:

```bash
$ make
mkdir -p target
clang -g -std=c89 -Wall -Werror -pedantic -o target/main_c.o -c src/main.c
cargo build 
   Compiling hour_glass v0.1.0 (file:///home/vp/tmp/hour_glass)
note: link against the following native artifacts when linking against this static library
note: the order and any duplication can be significant on some platforms, and so may need to be preserved
note: library: dl
note: library: pthread
note: library: gcc_s
note: library: c
note: library: m
note: library: rt
note: library: util
clang -g -std=c89 -Wall -Werror -pedantic -o target/hgc target/main_c.o target/debug/libintsorter.a -Wl,--gc-sections -lpthread
clang++ -g -std=c++11 -Wall -Werror -pedantic -o target/main_cpp.o -c src/main.cpp
clang++ -g -std=c++11 -Wall -Werror -pedantic -o target/hgcpp target/main_cpp.o target/debug/libintsorter.a -Wl,--gc-sections -lpthread
######## Testing from C
target/hgc
Hi C
0: 42
1: 23
2: 13
3: 12
4: 6
5: 0
6: 0
Destroy IntSorter Instance
Bye C
######## Testing from C++
target/hgcpp
Hi C++
0: 42
1: 23
2: 13
3: 12
4: 6
5: 0
6: 0
Bye C++
Destroy IntSorter Instance
```

Note the reverse order of rusts "Destroy IntSorter Instance" message.
The reason is in C we explicitily destroy the `IntSorter` and in C++ the end of the scope destroys the object.
