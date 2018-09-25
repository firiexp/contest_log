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
    vector<int> v2;
    map<int,int> v;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        v[a] = i+1;
        v2.emplace_back(a);
    }
    sort(v2.begin(), v2.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        printf("%d\n", v[v2[i]]);
    }
    return 0;
}
