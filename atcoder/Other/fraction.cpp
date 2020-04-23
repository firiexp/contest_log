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

struct frac {
    int a, b;
    frac(int a, int b) : a(a), b(b) {};
    frac() = default;
    bool operator<(const frac &x) const { return x.a*b < x.b*a; }
};



int main() {
    priority_queue<frac> Q;
    int m, k;
    cin >> m >> k;
    for (int i = 2; i <= m; ++i) {
        Q.emplace(1, i);
    }
    int cnt = 0;
    while(!Q.empty()){
        cnt++;
        if(cnt == k) {
            cout << Q.top().a << " " << Q.top().b << "\n";
            return 0;
        }
        auto p = Q.top(); Q.pop();
        p.a++;
        while(__gcd(p.a, p.b) != 1) p.a++;
        if(p.a < p.b) Q.emplace(p);

    }
    puts("-1");
    return 0;
}