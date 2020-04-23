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

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int g = v[0];
    for (int i = 0; i < n; ++i) {
        g = __gcd(g, v[i]);
    }
    for (int i = 0; i < n; ++i) {
        v[i] /= g;
    }
    map<int, int> x;
    for (int i = 0; i < n; ++i) {
        x[v[i]]++;
    }
    map<int, int> m;
    for (auto &&j : x) {
        auto w = divisor(j.first);
        for (auto &&k : w) {
            m[k] += j.second;
        }
    }
    int ans = 0;
    for (auto &&k : m) {
        if(k.second >= n-1){
            ans = max(ans, k.first);
        }
    }
    cout << ans*g << "\n";
    return 0;
}