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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> ls(n, INF<int>), rs(n, -INF<int>), cnt(n);
    for (int i = 0; i < k; ++i) {
        int r, c;
        scanf("%d %d", &r, &c);
        r--;
        ls[r] = min(ls[r], c);
        rs[r] = max(rs[r], c);
        cnt[r]++;
    }
    vector<int> safes(q);
    for (auto &&j : safes) scanf("%d", &j);
    sort(safes.begin(),safes.end());
    ll ans = 0, collected = 0;
    vector<pair<int, ll>> v, v2;
    v.emplace_back(1, 0);
    if(ls[0] > rs[0]){
        v[0] = {safes[0], safes[0]-1};
    }
    for (int i = 0; i < n; ++i) {
        if(ls[i] <= rs[i]){
            swap(v, v2);
            v.clear();
            ans += rs[i]-ls[i];
            auto it = upper_bound(safes.begin(),safes.end(), ls[i]);
            auto it2 = upper_bound(safes.begin(),safes.end(), rs[i]);
            if(it != safes.end()){
                ll val = INF<ll>;
                for (auto & j : v2) {
                    val = min(val, j.second
                    + min({abs(j.first-ls[i])+abs(*it-rs[i]),
                          abs(j.first-rs[i])+abs(*it-ls[i]),
                          abs(j.first-rs[i])+abs(*it-rs[i])+abs(ls[i]-rs[i]),
                          abs(j.first-ls[i])+abs(*it-ls[i])+abs(ls[i]-rs[i])
                    }));
                }
                v.emplace_back(*it, val);
                if(it+1 != safes.end()){
                    it++;
                    val = INF<ll>;
                    for (auto & j : v2) {
                        val = min(val, j.second
                                       + min({abs(j.first-ls[i])+abs(*it-rs[i]),
                                              abs(j.first-rs[i])+abs(*it-ls[i]),
                                              abs(j.first-rs[i])+abs(*it-rs[i])+abs(ls[i]-rs[i]),
                                              abs(j.first-ls[i])+abs(*it-ls[i])+abs(ls[i]-rs[i])
                                             }));
                    }
                    v.emplace_back(*it, val);
                    it--;
                }
            }
            if(it != safes.begin()){
                it--;
                ll val = INF<ll>;
                for (auto & j : v2) {
                    val = min(val, j.second
                                   + min({abs(j.first-ls[i])+abs(*it-rs[i]),
                                          abs(j.first-rs[i])+abs(*it-ls[i]),
                                          abs(j.first-rs[i])+abs(*it-rs[i])+abs(ls[i]-rs[i]),
                                          abs(j.first-ls[i])+abs(*it-ls[i])+abs(ls[i]-rs[i])
                                         }));
                }
                v.emplace_back(*it, val);
                it++;
            }

            if(it2 != safes.end()){
                ll val = INF<ll>;
                for (auto & j : v2) {
                    val = min(val, j.second
                                   + min({abs(j.first-ls[i])+abs(*it2-rs[i]),
                                          abs(j.first-rs[i])+abs(*it2-ls[i]),
                                          abs(j.first-rs[i])+abs(*it2-rs[i])+abs(ls[i]-rs[i]),
                                          abs(j.first-ls[i])+abs(*it2-ls[i])+abs(ls[i]-rs[i])
                                         }));
                }
                v.emplace_back(*it2, val);
                if(it2+1 != safes.end()){
                    it2++;
                    val = INF<ll>;
                    for (auto & j : v2) {
                        val = min(val, j.second
                                       + min({abs(j.first-ls[i])+abs(*it2-rs[i]),
                                              abs(j.first-rs[i])+abs(*it2-ls[i]),
                                              abs(j.first-rs[i])+abs(*it2-rs[i])+abs(ls[i]-rs[i]),
                                              abs(j.first-ls[i])+abs(*it2-ls[i])+abs(ls[i]-rs[i])
                                             }));
                    }
                    v.emplace_back(*it2, val);
                    it2--;
                }
            }
            if(it2 != safes.begin()){
                it2--;
                ll val = INF<ll>;
                for (auto & j : v2) {
                    val = min(val, j.second
                                   + min({abs(j.first-ls[i])+abs(*it2-rs[i]),
                                          abs(j.first-rs[i])+abs(*it2-ls[i]),
                                          abs(j.first-rs[i])+abs(*it2-rs[i])+abs(ls[i]-rs[i]),
                                          abs(j.first-ls[i])+abs(*it2-ls[i])+abs(ls[i]-rs[i])
                                         }));
                }
                v.emplace_back(*it2, val);
                it2++;

            }
        }
        collected += cnt[i];
        if(collected != k){
            ans++;
        }else {
            for (auto & j : v) {
                j.second -= min(abs(j.first-ls[i]), abs(j.first-rs[i]));
            }
            break;
        }
    }
    ll ans2 = INF<ll>;
    for (auto & i : v) {
        ans2 = min(ans2, i.second);
    }
    assert(ans2 >= 0 && ans2 < INF<ll>);
    cout << ans+ans2 << "\n";
    return 0;
}