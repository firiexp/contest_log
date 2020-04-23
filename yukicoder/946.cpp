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

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> S(n+1);
    vector<int> ans(n+1);
    for (int i = n-1; i >= 0; --i) {
        vector<int> a;
        int x = 0;
        for (int j = i+1; j <= n; ++j) {
            x ^= v[j-1];
            a.emplace_back(ans[j]^x);
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int ok = 0;
        for (int j = 0; j < a.size(); ++j) {
            if(j != a[j] && !ok){
                ok = 1;
                ans[i] = j;
            }
        }
        if(!ok) ans[i] = a.size();

    }
    puts(ans[0] ? "Takahashi" : "Takanashi");
    return 0;
}