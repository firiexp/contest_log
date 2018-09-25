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
    ll sum = 0, a = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d",&k);
        v.emplace_back(-k);
        sum -= k;
    }
    for (int j = 0; j < n; ++j) {
        int k;
        scanf("%d",&k);
        v[j] += k;
        sum += k;
    }
    for (int i = 0; i < n; ++i) if(v[i] > 0) a += (v[i]+1)/2;
    cout << (sum >= a ? "Yes\n" : "No\n");
    return 0;
}
