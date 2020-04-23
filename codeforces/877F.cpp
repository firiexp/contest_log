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

const int B = 400;

struct Query {
    int l, r, no;
    Query(int l, int r, int no) : l(l), r(r), no(no) {}
    Query() : l(0), r(0), no(0) {}
    bool operator<(const Query &a) const {
        int ablock = this->l / B, bblock = a.l / B;
        if(ablock != bblock) return ablock < bblock;
        if(ablock & 1) return this->r < a.r;
        else return this->r > a.r;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    for (auto &&i : t) scanf("%d", &i);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(t[i] == 2) a[i] = -a[i];
    }
    vector<ll> S(n+1);
    for (int i = 0; i < n; ++i) {
        S[i+1] = S[i] + a[i];
    }

    auto z = S;
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    vector<int> P(z.size(), -1), P2(z.size(), -1);
    for (int i = 0; i < z.size(); ++i) {
        auto x = lower_bound(z.begin(),z.end(), z[i]-k) - z.begin();
        if(x != z.size() && z[x] == z[i]-k) P[i] = x;
    }
    for (int i = 0; i < z.size(); ++i) {
        auto x = lower_bound(z.begin(),z.end(), z[i]+k) - z.begin();
        if(x != z.size() && z[x] == z[i]+k) P2[i] = x;
    }

    for (int i = 0; i <= n; ++i) {
        S[i] = lower_bound(z.begin(),z.end(), S[i]) - z.begin();
    }
    ll val = 0;
    int q;
    cin >> q;
    vector<Query> query;
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r++;
        query.emplace_back(l, r, i);
    }
    vector<int> cnt(z.size());
    vector<ll> ans(n);
    sort(query.begin(),query.end());
    int l = 0, r = 0;
    for (auto &&i : query) {
        while(l > i.l){
            l--;
            if(P2[S[l]] != -1){
                val += cnt[P2[S[l]]];
            }
            cnt[S[l]]++;
        }
        while(r < i.r){
            if(P[S[r]] != -1){
                val += cnt[P[S[r]]];
            }
            cnt[S[r]]++;
            r++;
        }
        while(l < i.l){
            cnt[S[l]]--;
            if(P2[S[l]] != -1){
                val -= cnt[P2[S[l]]];
            }

            l++;
        }
        while(r > i.r){
            r--;
            cnt[S[r]]--;
            if(P[S[r]] != -1){
                val -= cnt[P[S[r]]];
            }

        }
        ans[i.no] = val;
    }
    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}