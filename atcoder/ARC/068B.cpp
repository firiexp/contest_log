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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n;
    cin >> n;
    map<int, int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d",&k);
        v[k]++;
    }
    int a = 0, b = 0;
    for (auto &&x : v) {
        if(x.second%2)a++;
        else if(x.second%2 == 0 && x.second > 0) b++;
    }
    cout << a + b/2*2 << "\n";
    return 0;
}
