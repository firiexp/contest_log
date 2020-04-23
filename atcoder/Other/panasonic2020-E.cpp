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
    vector<string> v(3);
    for (auto &&i : v) cin >> i;
    vector<int> A[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(i == j) continue;
            for (int k = 0; k < v[i].size(); ++k) {
                int ok = 1;
                for (int l = 0; l + k < v[i].size() && l < v[j].size(); ++l) {
                    if(v[j][l] == '?' || v[i][l + k] == '?' || v[j][l] == v[i][l + k]) continue;
                    ok = 0;
                    break;
                }
                if(ok) A[i][j].emplace_back(k);
            }
            for (int m = v[i].size(); m <= 4000; ++m) A[i][j].emplace_back(m);
        }
    }
    vector<int> perm(3);
    iota(perm.begin(),perm.end(), 0);
    vector<int> sz(3);
    for (int i = 0; i < 3; ++i) sz[i] = v[i].size();
    int ans = sz[0]+sz[1]+sz[2];
    for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
            if(a == b) continue;
            for (int c = 0; c < 3; ++c) {
                if(a == c || b == c) continue;
                for (auto &&i : A[a][b]) {
                    for (auto &&j : A[b][c]) {
                        if(i+j >= sz[a]) ans = min(ans, max({sz[a], i+sz[b], i+j+sz[c]}));
                        else {
                            auto x = *lower_bound(A[a][c].begin(),A[a][c].end(), i+j);
                            if(x == i+j){
                                ans = min(ans, max({sz[a], i+sz[b], i+j+sz[c]}));
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}