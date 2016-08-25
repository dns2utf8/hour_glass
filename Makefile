
CC = clang
CXX = clang++

#CC = gcc
#CXX = g++



ifeq ($(shell uname),Darwin)
    LDFLAGS := -Wl,-dead_strip
else
    LDFLAGS := -Wl,--gc-sections -lpthread
endif

all: target/hgc target/hgcpp
	######## Testing from C
	target/hgc

	######## Testing from C++
	target/hgcpp

target:
	mkdir -p $@

target/hgc: target/main_c.o target/debug/libintsorter.a
	$(CC) -o $@ $^ $(LDFLAGS)

target/hgcpp: target/main_cpp.o target/debug/libintsorter.a
	$(CXX) -o $@ $^ $(LDFLAGS)

target/hgcpp_debug: target/main_cpp.o target/debug/libintsorter.a
	$(CXX) -fsanitize=undefined -fsanitize=leak -fsanitize=memory -fno-omit-frame-pointer -o $@ $^ $(LDFLAGS)

target/debug/libintsorter.a: src/lib.rs Cargo.toml
	cargo build

target/main_c.o: src/main.c | target
	$(CC) -std=c11 -o $@ -c $<

target/main_cpp.o: src/main.cpp | target
	$(CXX) -std=c++11 -o $@ -c $<

clean:
	rm -rf target
