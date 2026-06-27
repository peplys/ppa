
template <typename... Args>
struct s_v;


template <typename T, typename... Args>
struct s_v<T> : std::true_type {};

template <typename T, typename T2, typename... Args>
struct s_v<T, T2> : std::true_type {};

template <typename T, typename T2, typename T3, typename... Args>
struct s_v<T, T2> : std::true_type {};



int main() {
    static_assert(s_v<1, 3, 5, 7, 9, 11>);
    static_assert(s_v<11, 9, 7, 5, 3, 1>);
    static_assert(s_v<11, 1>);
    static_assert(s_v<11>);
    static_assert(!s_v<>);
    static_assert(!s_v<1, 2, 4>);
}