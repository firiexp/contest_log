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
    int n;
    cin >> n;
    int M = 100001;
    vector<int> v(n), A(M), val(M);
    for (auto &&i : v) scanf("%d", &i), A[i] = 1;
    ll ans = *max_element(v.begin(),v.end());
    vector<int> isprime(M, 1);
    for (int i = 2; i < M; ++i) {
        if(isprime[i]){
            for (int j = (M-1)/i; j != 0; --j) {
                if(j != 1) isprime[j*i] = 0;
                A[j] |= A[j * i];
            }
        }
    }
    vector<vector<int>> div(M);
    for (int i = 2; i < M; ++i) {
        if(A[i] && isprime[i]) {
            for (int j = i; j < M; j += i) {
                if(A[j]) div[j].emplace_back(i);
            }
        }
    }
    vector<int> st;
    auto f = [&](int x) -> int {
        int sz = div[x].size(), ret = 0;
        for (int i = 0; i < 1 << sz; ++i) {
            int y = 1, sign = 1;
            for (int j = 0; j < sz; ++j) {
                if(i & (1 << j)) y *= div[x][j], sign = -sign;
            }
            ret += val[y]*sign;
        }
        return ret;
    };
    auto update = [&](int x, bool p){
        int sz = div[x].size();
        for (int i = 1; i < 1 << sz; ++i) {
            int y = 1;
            for (int j = 0; j < sz; ++j) {
                if(i & (1 << j)) y *= div[x][j];
            }
            if(p) val[y]++;
            else val[y]--;
        }
        if(p) val[1]++;
        else val[1]--;
    };
    for (int i = M-1; i > 0; --i) {
        if(!A[i]) continue;
        while(f(i)){
            ans = max(ans, (ll)i*st.back());
            update(st.back(), false);
            st.pop_back();
        }
        update(i, true);
        st.emplace_back(i);
    }
    cout << ans << "\n";
    return 0;
}