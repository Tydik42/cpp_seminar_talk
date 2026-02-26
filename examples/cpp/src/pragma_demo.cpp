#include <cstdio>

[[deprecated("demo")]] int legacy_api() { return 1; }

int main() {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif
    std::printf("legacy=%d\n", legacy_api());
#if defined(__clang__) || defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
    return 0;
}
