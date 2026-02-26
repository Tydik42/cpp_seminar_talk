#include <array>
#include <cstdlib>
#include <iostream>
#include <source_location>

#ifndef USE_SOURCE_LOCATION
#define SMART_ASSERT(expr)                                                    \
    do {                                                                      \
        if (!(expr)) {                                                        \
            std::cerr << __FILE__ << ":" << __LINE__ << " assert: " << #expr \
                      << "\n";                                                \
            std::abort();                                                     \
        }                                                                     \
    } while (0)
#else
inline void smart_assert(
    bool expr,
    const char* expr_str,
    std::source_location loc = std::source_location::current()
) {
    if (!expr) {
        std::cerr << loc.file_name() << ":" << loc.line() << " assert: " << expr_str << "\n";
        std::abort();
    }
}
#define SMART_ASSERT(expr) smart_assert((expr), #expr)
#endif

#define ASSERT_GROUP(v, base)           \
    SMART_ASSERT((v) != ((base) + 0));  \
    SMART_ASSERT((v) != ((base) + 1));  \
    SMART_ASSERT((v) != ((base) + 2));  \
    SMART_ASSERT((v) != ((base) + 3));  \
    SMART_ASSERT((v) != ((base) + 4));  \
    SMART_ASSERT((v) != ((base) + 5));  \
    SMART_ASSERT((v) != ((base) + 6));  \
    SMART_ASSERT((v) != ((base) + 7));  \
    SMART_ASSERT((v) != ((base) + 8));  \
    SMART_ASSERT((v) != ((base) + 9));

int guarded_compute(int v) {
    ASSERT_GROUP(v, 100);
    ASSERT_GROUP(v, 200);
    ASSERT_GROUP(v, 300);
    ASSERT_GROUP(v, 400);
    ASSERT_GROUP(v, 500);
    ASSERT_GROUP(v, 600);
    ASSERT_GROUP(v, 700);
    ASSERT_GROUP(v, 800);
    ASSERT_GROUP(v, 900);
    ASSERT_GROUP(v, 1000);
    return v * 2;
}

int main() {
    std::array<int, 4> data{1, 2, 3, 4};
    int acc = 0;
    for (int v : data) acc += guarded_compute(v);
    std::cout << acc << "\n";
    return 0;
}
