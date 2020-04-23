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

vector<int> get_prime(int n){
    if(n <= 1) return vector<int>();
    vector<bool> is_prime(n+1, true);
    vector<int> prime;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]) prime.emplace_back(i);
        for (auto &&j : prime){
            if(i*j > n) break;
            is_prime[i*j] = false;
            if(i % j == 0) break;
        }
    }
    return prime;
}
template<class T>
T divisor(T n){
    T ret = 0;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret += i;
            if(i * i != n) ret += n / i;
        }
    }
    return ret-n;
}

int main() {
    int n;
    cin >> n;
    auto p = get_prime(n);
    vector<int> a{4, 9, 16, 25, 36, 49}, b{8, 27};
    if(!p.empty() && p.back() == n) puts("Sosu!");
    else if(any_of(a.begin(),a.end(), [n](int x){return x == n; })) puts("Heihosu!");
    else if(any_of(b.begin(),b.end(), [n](int x){return x == n; })) puts("Ripposu!");
    else if(n != 0 && divisor(n) == n) puts("Kanzensu!");
    else cout << n << "\n";

    return 0;
}