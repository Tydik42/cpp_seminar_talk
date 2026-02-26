#if __has_include(<optional>)
  #include <optional>
  #include <cstdio>
  int main() {
      std::optional<int> v = 7;
      std::printf("optional=%d\n", *v);
      return 0;
  }
#else
  #include <cstdio>
  int main() {
      std::printf("fallback path\n");
      return 0;
  }
#endif
