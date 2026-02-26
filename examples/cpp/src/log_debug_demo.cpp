#include <cstdio>

struct Logger {
    bool debug = false;
    bool is_debug() const { return debug; }
    void log(const char* fmt, int v) const { std::printf(fmt, v); }
};

#define LOG_DEBUG(logger, ...)                 \
    do {                                       \
        if ((logger).is_debug()) {             \
            (logger).log(__VA_ARGS__);         \
        }                                      \
    } while(false)

int main() {
    Logger logger{false};
    int x = 42;
    LOG_DEBUG(logger, "x=%d\n", x);
    return 0;
}
