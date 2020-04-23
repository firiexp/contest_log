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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int sum = accumulate(v.begin(), v.end(), 0), a = 0;
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        a += v[i];
        if(a*2 > sum){
            cout << i+1 << "\n";
            return 0;
        }
    }
    return 0;
}
