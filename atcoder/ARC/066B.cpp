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

string nisin(int n){
    string ret;
    while(n >= 2){
        ret += to_string(n%2);
        n /= 2;
    }
    ret += to_string(n%2);
    reverse(ret.begin(), ret.end());
    return ret;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> vv(n+1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            vv[j^(i-j)].emplace_back(i);
        }
    }
    for (int i = 0; i <= n; ++i) {
        vv[i].erase(unique(vv[i].begin(), vv[i].end()), vv[i].end());
    }
    for (int i = 0; i <= n; ++i) {
        printf("xor: %d , ", i);
        cout << vv[i].size() << "\n";
    }
    return 0;
}
