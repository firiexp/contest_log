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

array<int, 150010> ar{};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if(v[i]+j > 0 && !ar[v[i]+j]) {
                ar[v[i]+j]++;
                break;
            }
        }
    }
    cout << accumulate(ar.begin(),ar.end(), 0) << "\n";
    return 0;
}