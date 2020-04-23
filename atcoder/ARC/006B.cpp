#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, l;
    cin >> n >> l;
    string s;
    vector<int> v(n), v2(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    getline(cin, s);
    for (int i = 0; i < l; ++i) {
        getline(cin, s);
        for (int j = 0; j < n-1; ++j) {
            if(s[2*j+1] == '-') swap(v[j], v[j+1]);
        }
    }
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
        if(s[2*i] == 'o') {
            cout << v[i]+1 << "\n";
        }
    }
    return 0;
}
