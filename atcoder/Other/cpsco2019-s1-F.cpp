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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n;
    cin >> n;
    using tup = array<int, 3>;
    vector<tup> v(n);
    int y = INF<int>;
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        v[i] = {t, a, b};
        y = min(y, a);
    }
    ll ok = -INF<ll>/10, ng = y+1;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        vector<pair<ll, ll>> k(n+1);
        k[n] = {INF<ll>, INF<ll>};
        int good = 1;
        for (int i = 0; i < n; ++i) {
            int t = v[i][0], a = v[i][1], b = v[i][2];
            k[i].first = t-(a-mid)/b;
            k[i].second = t+(a-mid)/b;
            if(k[i].first > k[i].second) good = 0;
        }

        sort(k.begin(),k.end());
        int cur = 0;
        GPQ<ll> pq;
        for (int i = 1; i <= n; ++i) {
            while(k[cur].first <= i){
                pq.emplace(k[cur].second);
                cur++;
            }
            if(!pq.empty() && pq.top() < i) {
                good = 0;
                break;
            }
            if(!pq.empty()) {
                pq.pop();
            }
            else good = 0;
        }
        (good ? ok : ng) = mid;
    }
    cout << ok << "\n";
    return 0;
}