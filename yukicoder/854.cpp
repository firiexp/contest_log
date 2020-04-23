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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

using u32 = uint32_t;

template<typename T>
struct ExactDiv {
    T t, i, val;
    ExactDiv() {}
    ExactDiv(T n) : t(T(-1) / n), i(mul_inv(n)) , val(n) {};
    T mul_inv(T n) {
        T x = n;
        for (int i = 0; i < 5; ++i) x *= 2 - n * x;
        return x;
    }
    bool divide(T n) const {
        if(val == 2) return !(n & 1);
        return n * this->i <= this->t;
    }
};

vector<ExactDiv<u32>> get_prime(int n){
    if(n <= 1) return vector<ExactDiv<u32>>();
    vector<bool> is_prime(n+1, true);
    vector<ExactDiv<u32>> prime;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]) prime.emplace_back(i);
        for (auto &&j : prime){
            if(i*j.val > n) break;
            is_prime[i*j.val] = false;
            if(j.divide(i)) break;
        }
    }
    return prime;
}
const auto primes = get_prime(2000);

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int M = primes.size();
    int n;
    cin >> n;
    vector<int> zeros(n+1);
    auto v = make_v(n+1, M, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        zeros[i+1] = zeros[i] + (x == 0);
        if(x){
            for (int j = 0; j < M; ++j) {
                v[i+1][j] = v[i][j];
                while(primes[j].divide(x)){
                    v[i+1][j]++;
                    x /= primes[j].val;
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int p, l, r;
        scanf("%d %d %d", &p, &l, &r);
        l--;
        if(zeros[l] != zeros[r]) puts("Yes");
        else {
            int ok = 1;
            for (int j = 0; j < M && ok; ++j) {
                int cnt = v[r][j] - v[l][j];
                while(primes[j].divide(p)){
                    if(cnt == 0) {
                        ok = 0;
                        break;
                    }
                    p /= primes[j].val;
                    cnt--;
                }
            }
            puts(ok && p == 1 ? "Yes" : "NO");
        }
    }
    return 0;
}