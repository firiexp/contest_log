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
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &&k : v) scanf("%d", &k);
    int a = (n+1)/2, b = n-a;
    map<int, vector<int>> m;
    for (int i = 0; i < (1 << b); ++i) {
        int x = 0;
        for (int j = 0; j < b; ++j) {
            if(i&(1 << j)) x += v[j+a];
        }
        m[x].emplace_back(i);
    }
    vector<vector<int>> anss;
    for (int i = 0; i < (1 << a); ++i) {
        int x = 0;
        for (int j = 0; j < a; ++j) {
            if(i&(1 << j)) x += v[j];
        }
        if(m.count(s-x)){
            for (auto &&j : m[s-x]) {
                vector<int> ans;
                for (int k = 0; k < a; ++k) {
                    if(i & (1 << k)) ans.emplace_back(k+1);
                }
                for (int k = 0; k < b; ++k) {
                    if(j & (1 << k)) ans.emplace_back(k+a+1);
                }
                anss.emplace_back(ans);
            }
        }
    }
    sort(anss.begin(),anss.end());
    for (auto &&ans : anss) {
        for (int k = 0; k < ans.size(); ++k) {
            if(k) printf(" ");
            printf("%d", ans[k]);
        }
        puts("");
    }
    return 0;
}