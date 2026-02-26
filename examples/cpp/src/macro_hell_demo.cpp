#include <cstdlib>

// Intentionally deep macro chain for "macro expansion hell" diagnostics.
#define FATAL_WRAP(expr)          \
    do {                          \
        if (!(expr)) std::abort(); \
    } while (0)

#define CHECK_1(expr) FATAL_WRAP(expr)
#define CHECK_2(expr) CHECK_1(expr)
#define CHECK_3(expr) CHECK_2(expr)
#define CHECK_4(expr) CHECK_3(expr)
#define CHECK_5(expr) CHECK_4(expr)
#define CHECK_6(expr) CHECK_5(expr)
#define CHECK_7(expr) CHECK_6(expr)
#define CHECK_8(expr) CHECK_7(expr)
#define CHECK_9(expr) CHECK_8(expr)
#define CHECK_10(expr) CHECK_9(expr)
#define CHECK_11(expr) CHECK_10(expr)
#define CHECK_12(expr) CHECK_11(expr)
#define CHECK_13(expr) CHECK_12(expr)
#define CHECK_14(expr) CHECK_13(expr)
#define CHECK_15(expr) CHECK_14(expr)
#define CHECK_16(expr) CHECK_15(expr)
#define SMART_ASSERT(expr) CHECK_16(expr)

int main() {
    // Expected compilation failure: <string> is intentionally not included.
    SMART_ASSERT(std::string("x") == "x");
    return 0;
}
