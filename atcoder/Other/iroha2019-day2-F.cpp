#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>


static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;
#include <chrono>
#include <unordered_map>
struct MyHash {
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t y = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x^(y >> 1));
    }
};



int main() {
    unordered_map<ll, int, MyHash> m;
    int a = 100000, b = 100000;
    int c = a*b;
    cout << c << "\n";
    return 0;
}