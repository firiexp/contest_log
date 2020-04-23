#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[x-1]++;
    }
    int ans = 0;
    cout << v << "\n";
    for (int i = 0; i < n-1; ++i) {
        if(v[i]+2 <= v[i+1] && v[i]){
            ans++; v[i+1] -= 3;
        }else if(v[i] >= v[i+1]+2 && v[i+1]){
            ans++; v[i] -= 3;
        }
    }
    cout << v << "\n";
    for (int i = 0; i < m-2; ++i) {
        while(v[i-1]&& v[i] && v[i+1]){
            ans++, v[i-1]--, v[i]--, v[i+1]--;
        }
    }
    cout << v << "\n";
    cout << ans << "\n";
    return 0;
}
