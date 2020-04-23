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

    vector<int> v(n+2);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i+1]);
    }
    vector<int> z = v;
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    auto f = [&](int x){ return lower_bound(z.begin(), z.end(), x) - z.begin(); };
    vector<int> s(z.size()+1, 0);
    for (int i = 0; i < n+1; ++i) {
        int a = f(min(v[i], v[i+1])), b = f(max(v[i], v[i+1]));
        s[a]++; s[b]--;
    }
    for (int i = 0; i < z.size(); ++i) {
        s[i+1] += s[i];
    }
    cout << *max_element(s.begin(), s.end()) /2 << "\n";
    return 0;
}
