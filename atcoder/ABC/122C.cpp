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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n-1; ++i) {
        if(s[i] == 'A' && s[i+1] == 'C') v[i+1]++;
        v[i+1] += v[i];
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << v[b] - v[a] << "\n";
    }
    return 0;
}
