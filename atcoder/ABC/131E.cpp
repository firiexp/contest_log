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

int main() {
    int n, k;
    cin >> n >> k;
    if(k > (n-1)*(n-2)/2){
        puts("-1");
        return 0;
    }
    using P = pair<int, int>;
    vector<P> v;
    for (int i = 1; i < n; ++i) {
        v.emplace_back(0, i);
    }
    int cnt = (n-1)*(n-2)/2-k;
    for (int len = 1; len < n; ++len) {
        for (int i = 1; i+len < n; ++i) {
            if(!cnt) continue;
            v.emplace_back(i, i+len);
            cnt--;
        }
    }
    cout << v.size() << "\n";
    for (auto &&i : v) {
        cout << i.first+1 << " " << i.second+1 << "\n";
    }
    return 0;
}