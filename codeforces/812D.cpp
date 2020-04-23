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

int main() {
    int a, b;
    cin >> a >> b;
    map<tuple<int, int, int>, int> v;
    v[{0, 0, 0}] = 0;
    auto rec = [&](int a, int b, int c, auto &&f) -> int {
        if(v.count({a, b, c})) return v[{a, b, c}];
        vector<int> X;
        for (int i = 1; i <= a; ++i) {
            X.emplace_back(f(a-i, b+i, c, f));
            X.emplace_back(f(a-i, b, c+i, f));
        }
        for (int i = 1; i <= b; ++i) {
            X.emplace_back(f(a, b-i, c, f));
        }
        for (int i = 1; i <= c; ++i) {
            X.emplace_back(f(a, b, c-i, f));
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());
        for (int i = 0; i < X.size(); ++i) {
            if(i != X[i]) return v[{a, b, c}] = i;
        }
        return v[{a, b, c}] = X.size();
    };
    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                printf("%5d ", rec(k, i, j, rec));
            }
            puts("");
        }
    }
    return 0;
}