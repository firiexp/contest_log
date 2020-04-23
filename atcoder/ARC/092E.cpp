#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    int allneg = 1;
    for (auto &&i : v) {
        scanf("%li", &i);
        if(i > 0) allneg = 0;
    }
    if(allneg){
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if(v[i] > v[cur]) cur = i;
        }
        cout << v[cur] << "\n";
        cout << n-1 << "\n";
        for (int i = 0; i < cur; ++i) {
            cout << 1 << "\n";
        }
        for (int i = 0; i < n-1-cur; ++i) {
            cout << n-cur-i << "\n";
        }
        return 0;
    }
    ll sum1 = 0, sum2 = 0, summ;
    vector<int> v1, v2, v3;
    for (int i = 0; i < n; ++i) {
        if(v[i] >= 0) (i%2 ? sum1 : sum2) += v[i], (i%2 ? v1 : v2).emplace_back(i+1);
    }
    if(sum1 >= sum2 && !v1.empty()) summ = sum1, v3 = v1;
    else summ = sum2, v3 = v2;
    cout << summ << "\n";
    vector<int> ans;
    for (int j = n; j > v3.back(); --j) {
        ans.emplace_back(j);
    }
    for (int i = static_cast<int>(v3.size())-1; i > 0; --i) {
        int k = v3[i]-v3[i-1]-1;
        for (int j = 0; j < (k+1)/2; ++j) {
            ans.emplace_back(v3[i-1]+(k+1)/2-j);
        }
    }
    for (int i = 1; i < v3[0]; ++i) {
        ans.emplace_back(1);
    }
    cout << ans.size() << "\n";
    for (auto &&l : ans) cout << l << "\n";
    return 0;
}
