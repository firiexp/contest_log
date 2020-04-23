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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 1; i < n; ++i) {
        if(v[i-1] == v[i]){
            puts("stay");
        }else if(v[i-1] < v[i]){
            printf("up %d\n", v[i]-v[i-1]);
        }else {
            printf("down %d\n", v[i-1]-v[i]);
        }
    }
    return 0;
}