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
    vector<int> v(4);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    for (int i = 0; i < 3; ++i) {
        if(v[i+1]-v[i] != 1){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}