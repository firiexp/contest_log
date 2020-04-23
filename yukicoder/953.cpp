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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

using P = pair<int, int>;
using P2 = pair<ll, int>;


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
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> v(n);
    if(k1 < k2){
        int l = k1-1, r = k2-1, c = 0;
        while(0 <= l || r < n){
            if(0 <= l) v[l--] = c++;
            if(r < n) v[r++] = c++;
        }
    }else {
        int l = k2-1, r = k1-1, c = 0;
        while(0 <= l || r < n){
            if(r < n) v[r++] = c++;
            if(0 <= l) v[l--] = c++;

        }
    }
    auto cmp = [&](P x, P y){
        if(x.first != y.first) return x.first < y.first;
        else return v[x.second] < v[y.second];
    };
    set<P, decltype(cmp)> s(cmp);
    for (int i = 0; i < n; ++i) {
        s.emplace(0, i); // 0 : empty 1 : adjacent 2 : not empty
    }
    vector<int> data(n, 0);
    int q;
    cin >> q;

    auto update = [&](int i, int j){
        if(j == 0){
            if(i != 0 && data[i-1] == 2) j = 1;
            if(i != n-1 && data[i+1] == 2) j = 1;
        }
        if(data[i] == j) return;
        s.erase({data[i], i});
        s.emplace(j, i);
        data[i] = j;
        if(j == 2){
            if(i != 0 && !data[i-1]){
                s.erase({data[i-1], i-1});
                s.emplace(1, i-1);
                data[i-1] = 1;
            }
            if(i != n-1 && !data[i+1]){
                s.erase({data[i+1], i+1});
                s.emplace(1, i+1);
                data[i+1] = 1;
            }
        }else {
            if(i && data[i-1] == 1 && (i == 1 || data[i-2] <= 1)){
                s.erase({data[i-1], i-1});
                s.emplace(0, i-1);
                data[i-1] = 0;
            }
            if(i != n-1 && data[i+1] == 1 && (i == n-2 || data[i+2] <= 1)){
                s.erase({data[i+1], i+1});
                s.emplace(0, i+1);
                data[i+1] = 0;
            }
        }
    };
    ll cnt = 0, time = 0;
    GPQ<P2> Q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        while(!Q.empty() && (Q.top().first <= max<ll>(a, time) || cnt == n)){
            time = max(time, Q.top().first);
            update(Q.top().second, 0);
            cnt--;
            Q.pop();
        }
        auto x = *s.begin();
        printf("%d\n", x.second + 1);
        Q.emplace(max<ll>(a, time)+b, x.second);
        update(x.second, 2);
        cnt++;
    }
    return 0;
}