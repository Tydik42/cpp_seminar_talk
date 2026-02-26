#include <cstdio>

#define LOG(fmt, ...) std::printf("[cpp] " fmt "\n" __VA_OPT__(,) __VA_ARGS__)

int main() {
    int x = 42;
    LOG("start");
    LOG("x=%d", x);
    return 0;
}
