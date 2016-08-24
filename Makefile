
ifeq ($(shell uname),Darwin)
    LDFLAGS := -Wl,-dead_strip
else
    LDFLAGS := -Wl,--gc-sections -lpthread
endif

all: target/hgc target/hgcpp
	target/hgc
	target/hgcpp

target:
	mkdir -p $@

target/hgc: target/main_c.o target/debug/libintsorter.a
	$(CC) -o $@ $^ $(LDFLAGS)

target/hgcpp: target/main_cpp.o target/debug/libintsorter.a
	$(CXX) -o $@ $^ $(LDFLAGS)

target/debug/libintsorter.a: src/lib.rs Cargo.toml
	cargo build

target/main_c.o: src/main.c | target
	$(CC) -o $@ -c $<

target/main_cpp.o: src/main.cpp | target
	$(CXX) -o $@ -c $<

clean:
	rm -rf target
