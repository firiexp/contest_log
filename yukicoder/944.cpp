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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int solve(int x, vector<int> &v){
    int s = 0, ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        s += v[i];
        if(s > x) return 0;
        if(s == x) ans++, s = 0;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int s = 0;
    for (auto &&i : v) scanf("%d", &i), s += i;
    auto x = divisor(s);
    int ans = 0;
    for (auto &&i : x) {
        ans = max(ans, solve(i, v));
    }
    cout << ans << "\n";
    return 0;
}