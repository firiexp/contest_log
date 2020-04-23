#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    vector<int> v;
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if(i+j != 0) v.emplace_back(i+5*j);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto &&i : v) {
        printf("%d\n", i);
    }
    return 0;
}
