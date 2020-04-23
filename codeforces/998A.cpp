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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    if(n == 1 || (n == 2 && v[0] == v[1])){
        puts("-1");
        return 0;
    }
    int x = min_element(v.begin(),v.end()) - v.begin();
    cout << n-1 << "\n";
    for (int i = 0; i < n; ++i) {
        if(x != i) {
            cout << i+1 << " ";
        }
    }
    puts("");
    return 0;
}