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
    for (auto &&i : v) scanf("%d", &i), i%=2;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        if(v[i]%2) a.emplace_back(i+1);
        else b.emplace_back(i+1);
    }
    cout << (a.size() == 1 ? a : b)[0] << "\n";
    return 0;
}
