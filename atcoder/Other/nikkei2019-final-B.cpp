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
    int n, m, l;
    cin >> n >> m >> l;
    array<int, 100000> v{}, v2{};
    for (int i = 0; i < n; ++i) {
        cin >> v[100000-n+i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> v2[100000-m+j];
    }
    if(v < v2){
        cout << "X\n";
    }else if(v == v2){
        cout << "Same\n";
    }else {
        cout << "Y\n";
    }
    return 0;
}
