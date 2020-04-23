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

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; ++j) {
            int y;
            scanf("%d", &y);
            v.emplace_back(j, i, y);
        }
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); ++i) {
        if(i) printf(" ");
        printf("%d", get<2>(v[i]));
    }
    puts("");
    return 0;
}