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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    string s;
    cin >> s;
    auto f = [&](int a, int b){ return v[a] < v[b]; };
    auto f2 = [&](int a, int b){ return v[a] > v[b]; };
    set<int, decltype(f)> S(f);
    for (int i = 0; i < n; ++i) {
        S.emplace(i);
    }
    set<int, decltype(f2)> S2(f2);
    vector<int> ans(2*n);
    for (int i = 0; i < 2*n; ++i) {
        if(s[i] == '0'){
            auto x = S.begin();
            ans[i] = *x;
            S2.emplace(*x);
            S.erase(x);
        }else {
            auto x = S2.begin();
            ans[i] = *x;
            S2.erase(x);
        }
    }
    for (int i = 0; i < 2*n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    puts("");
    return 0;
}