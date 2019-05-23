
# In case the user uses a global build cache for rust
CARGO_TARGET_DIR = ./target/

CC = clang
CXX = clang++


#CC = gcc
#CXX = g++

CFLAGS := -std=c89 -Wall -Werror -pedantic
CXXFLAGS := -std=c++11 -Wall -Werror -pedantic

ifneq ($(findstring optimized,$(MAKECMDGOALS)),)
	CFLAGS := -O2 $(CFLAGS)
	CXXFLAGS := -O2 $(CXXFLAGS)
	RUST_LIB := target/release/libintsorter.a
else
	CFLAGS := -g $(CFLAGS)
	CXXFLAGS := -g $(CXXFLAGS)
	RUST_LIB := target/debug/libintsorter.a
endif

ifeq ($(shell uname),Darwin)
    LDFLAGS := -Wl,-dead_strip
else
    LDFLAGS := -Wl,--gc-sections -lpthread -ldl
endif

all: target/hgc target/hgcpp
	######## Testing from C
	target/hgc

	######## Testing from C++
	target/hgcpp

target:
	mkdir -p $@

target/hgc: target/main_c.o $(RUST_LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

target/hgcpp: target/main_cpp.o $(RUST_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

target/hgcpp_debug: target/main_cpp.o target/debug/libintsorter.a
	$(CXX) $(CXXFLAGS) -fsanitize=undefined -fsanitize=leak -fsanitize=memory -fno-omit-frame-pointer -o $@ $^ $(LDFLAGS)

target/debug/libintsorter.a: src/lib.rs Cargo.toml
	cargo build $(CARGOFLAGS)

target/release/libintsorter.a: src/lib.rs Cargo.toml
	cargo build --release

target/main_c.o: src/main.c | target
	$(CC) $(CFLAGS) -o $@ -c $<

target/main_cpp.o: src/main.cpp | target
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf target

optimized: all
	# enables optimization

help:
	# enable optimization by adding the optimized-target
	# clean target
	# all target compile and run tests
