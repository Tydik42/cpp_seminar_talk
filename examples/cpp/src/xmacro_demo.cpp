#include <cstdio>

#define FOR_EACH_STATE(X) \
    X(Idle)               \
    X(Running)            \
    X(Failed)

enum class State {
    #define X(s) s,
    FOR_EACH_STATE(X)
    #undef X
};

constexpr const char* to_string(State s) {
    switch (s) {
        #define X(s) case State::s: return #s;
        FOR_EACH_STATE(X)
        #undef X
    }
    return "Unknown";
}

int main() {
    std::printf("%s\n", to_string(State::Running));
    return 0;
}
