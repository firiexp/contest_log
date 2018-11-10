#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

int main() {
    int n;
    cin >> n;
    vector<int> v(3*n, 0);
    vector<ll> S(n+1, 0);
    for (auto &&i : v) scanf("%d", &i);
    ll s = 0;
    GPQ<int> Q;
    for (int i = 0; i < n; ++i) {
        Q.push(v[i]);
        s += v[i];
    }
    S[0] = s;
    for (int i = n; i < 2*n; ++i) {
        Q.push(v[i]);
        s = s + (v[i]-Q.top());
        Q.pop();
        S[i-n+1] = s;
    }
    s = 0;
    PQ<int> Q2;
    for (int i = 0; i < n; ++i) {
        Q2.push(v[n*2+i]);
        s += v[n*2+i];
    }
    S[n] -= s;
    for (int i = 2*n-1; i >= n; --i) {
        Q2.push(v[i]);
        s = s + (v[i]-Q2.top());
        Q2.pop();
        S[i-n] -= s;
    }
    cout << (*max_element(S.begin(), S.end())) << "\n";
    return 0;
}
