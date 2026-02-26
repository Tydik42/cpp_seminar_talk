#include <cstdio>

#define LOG_OK(fmt, ...) std::printf(fmt __VA_OPT__(,) __VA_ARGS__)

int main() {
    LOG_OK("hello");
    LOG_OK("x=%d", 42);
    return 0;
}
