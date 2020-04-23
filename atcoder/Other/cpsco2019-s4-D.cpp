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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    v.emplace_back(-1);
    int ok = n, ng = 0;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        int cur = 0, val = 0;
        while(cur < n){
            int cnt = 1;
            while(v[cur] == v[cur+1]) cur++, cnt++;
            cur++;
            val += cnt/(mid+1);
        }
        (val <= k ? ok : ng) = mid;
    }
    cout << ok << "\n";
    return 0;
}