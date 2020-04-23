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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n;
    cin >> n;
    vector<int> v(1<<n);
    for (auto &&k : v) scanf("%d", &k);
    multiset<int, greater<>> s;
    s.insert(v.begin(),v.end());
    vector<int> u(1<<n);
    u[0] = *s.begin();
    s.erase(s.begin());
    for (int i = 1; i < (1 << n); i *= 2) {
        for (int j = 0; j < i; ++j) {
            auto x = s.upper_bound(u[j]);
            if(x == s.end()){
                puts("No");
                return 0;
            }
            u[j+i] = *x;
            s.erase(x);
        }
    }
    puts("Yes");
    return 0;
}

