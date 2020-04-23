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

bool solve(vector<int> &v){

}

int main() {
    int n;
    cin >> n;
    vector<array<int, 4>> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &v[i][j]);
        }
    }

    return 0;
}