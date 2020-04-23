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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < m; ++i) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if(cnt[p] == -1) continue;
        if(s == "AC"){
            ans1++; ans2 += cnt[p]; cnt[p] = -1;
        }else {
            cnt[p]++;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}