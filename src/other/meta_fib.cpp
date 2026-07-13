#include <iostream>

using namespace std;

template <int N>
struct fib {
    static constexpr long long value = fib<N - 1>::value + fib<N - 2>::value;
};

template <>
struct fib<0> {
    static constexpr long long value = 0;
};

template <>
struct fib<1> {
    static constexpr long long value = 1;
};

int main() {
    cout << "第10个斐波那契数: " << fib<10>::value << endl;
    return 0;
}