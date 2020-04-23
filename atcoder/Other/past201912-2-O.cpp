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
    vector<array<int, 6>> v(n);
    vector<int> z;
    z.reserve(n*6);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            scanf("%d", &v[i][j]);
            z.emplace_back(v[i][j]);
        }
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    vector<int> val(n*6), used(n);
    vector<double> E(n), EE(n*6);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            v[i][j] = lower_bound(z.begin(),z.end(), v[i][j]) - z.begin();
            val[v[i][j]] = i;
        }
    }
    using P = pair<double, int>;
    set<P, greater<>> S;
    S.emplace(1, val.back());
    E[val.back()] = 1;
    EE.back() = 1;
    used[val.back()] = 1;
    for (int i = n*6-2; i >= 0; --i) {
        double x; int p; tie(x, p) = *S.begin();
        if(used[val[i]]){
            S.erase(S.find({E[val[i]], val[i]}));
        }
        E[val[i]] += x/6+1;
        used[val[i]] = 1;
        EE[i] = x/6+1;
        S.emplace(E[val[i]], val[i]);
    }
    printf("%.10lf\n", S.begin()->first/6+1);
    return 0;
}