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

struct Prime { // Wheel factorization
    static constexpr int wheel[] = {4, 2, 4, 2, 4, 6, 2, 6},
            wheel2[] = {7, 11, 13, 17, 19, 23, 29, 31},
            wheel_sum[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7};
    static inline int f(int n){ return (n-1)/30*8 + wheel_sum[(n-1)%30]; }
    static inline int g(int n){ return ((n-1) >> 3)*30 + wheel2[(n-1)&7]; }
    vector<int> primes;

    Prime(int M) {
        primes = {2, 3, 5};
        if(M < 7){
            while(!primes.empty() && M < primes.back()) primes.pop_back();
            return;
        }
        int n = f(M), m = g(n), k = f(int(floor(sqrt(M))));
        primes.reserve(3+max(0, (int)(n/(log(n)-1.12))));
        vector<bool> sieve(n+1, true);
        for (int i = 1; i <= k; ++i) {
            if(sieve[i]){
                ll p = g(i), q = p*p;
                int j = (i-1)&7;
                while(q <= m){
                    sieve[f(q)] = false;
                    q += wheel[j] * p;
                    j = (j+1)&7;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if(sieve[i]) primes.emplace_back(g(i));
        }
    }
};
constexpr int Prime::wheel[], Prime::wheel2[], Prime::wheel_sum[];


int main() {
    Prime x(10000001);
    vector<int> val;
    for (int i = 0; i+3 < x.primes.size(); ++i) {
        if(x.primes[i]+2 == x.primes[i+1]
        && x.primes[i+1]+4 == x.primes[i+2]
        && x.primes[i+2]+2 == x.primes[i+3]){
            val.emplace_back(x.primes[i+3]);
        }
    }
    int n;
    while(cin >> n, n){
        printf("%d\n", *--upper_bound(val.begin(),val.end(), n));
    }
    return 0;
}