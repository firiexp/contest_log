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
    vector<int> v(4);
    for (int i = 0; i < 4; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(v[0] == 1 && v[1] == 4 && v[2] == 7 && v[3] == 9){
        puts("YES");
    }else puts("NO");
    return 0;
}
