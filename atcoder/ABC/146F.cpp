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
    int n, m; string s;
    cin >> n >> m >> s;
    vector<pair<int, int>> dp(n+1, {INF<int>, -1});
    dp.back() = {0, 0};
    set<pair<int, int>> S;
    S.emplace(0, n);
    for (int i = n-1; i >= 0; --i) {
        if(s[i] != '1' && !S.empty()){
            auto val = *S.begin();
            dp[i] = {val.first+1, val.second};
            S.emplace(val.first+1, i);
        }
        if(n-i >= m){
            S.erase(make_pair(dp[i+m].first, i+m));
        }
    }
    if(dp.front().first == INF<int>){
        puts("-1");
    }else {
        for (int i = 0; i < n; i = dp[i].second) {
            if(i) printf(" ");
            printf("%d", dp[i].second-i);
        }
        puts("");
    }
    return 0;
}