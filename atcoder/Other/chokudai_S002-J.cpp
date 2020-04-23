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

int main() {
    int n;
    cin >> n;
    using P = pair<int, int>;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(),v.end(), [](P a, P b){
        return a.first+a.second < b.first+b.second;
    });
    vector<int> ret;
    for(int i = 1; i * i <= v[0].first; i++) {
        if(v[0].first % i == 0) {
            ret.push_back(i);
            if(i * i != v[0].first) ret.push_back( v[0].first / i);
        }
    }
    for(int i = 1; i * i <= v[0].second; i++) {
        if(v[0].second % i == 0) {
            ret.push_back(i);
            if(i * i != v[0].second) ret.push_back( v[0].second / i);
        }
    }
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    int ans = 0;
    for (auto &&p : ret) {
        int ok = 1;
        for (int i = 0; i < n; ++i) {
            if(v[i].first%p && v[i].second%p) ok = 0;
        }
        if(ok){
            ans = max(ans, p);
        }
    }
    cout << ans << "\n";
    return 0;
}