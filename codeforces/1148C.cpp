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

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> x(n);
    for (auto &&i : v) scanf("%d", &i), i--;
    for (int i = 0; i < n; ++i) {
        x[v[i]] = i;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if(x[i] == i) continue;
        int idx1 = i, idx2 = x[i];
        if(i > v[i]) swap(idx1, idx2);
        swap(x[v[idx1]], x[v[idx2]]);
        swap(v[idx1], v[idx2]);
        if(idx2-idx1 >= n/2){
          ans.emplace_back(idx1, idx2);
        } else if(idx1 < n/2 && idx2 >= n/2){
            ans.emplace_back(0, idx2);
            ans.emplace_back(idx1, n-1);
            ans.emplace_back(0, n-1);
            ans.emplace_back(0, idx2);
            ans.emplace_back(idx1, n-1);
        }else if(idx1 < n/2 && idx2 < n/2){
            ans.emplace_back(idx1, n-1);
            ans.emplace_back(idx2, n-1);
            ans.emplace_back(idx1, n-1);
        }else if(idx1 >= n/2 && idx2 >= n/2){
            ans.emplace_back(0, idx1);
            ans.emplace_back(0, idx2);
            ans.emplace_back(0, idx1);
        }
    }
    cout << ans.size() << "\n";
    for (auto &&j : ans) {
        printf("%d %d\n", j.first+1, j.second+1);
    }
    return 0;
}