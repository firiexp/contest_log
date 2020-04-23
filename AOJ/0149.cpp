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
    double l, r;
    vector<int> a(4), b(4);
    while(cin >> l >> r){
        if(l >= 1.1) a[0]++;
        else if(l >= 0.6) a[1]++;
        else if(l >= 0.2) a[2]++;
        else a[3]++;
        if(r >= 1.1) b[0]++;
        else if(r >= 0.6) b[1]++;
        else if(r >= 0.2) b[2]++;
        else b[3]++;
    }
    for (int i = 0; i < 4; ++i) {
        printf("%d %d\n", a[i], b[i]);
    }
    return 0;
}