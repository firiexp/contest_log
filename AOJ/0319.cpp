#include <iostream>
#include <algorithm>
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
    int ok = 0, ng = n+1;
    while(ng-ok > 1){
        int mid = (ok+ng)/2, cnt = 0;
        for (auto &&i : v) if(i >= mid) cnt++;
        if(cnt >= mid) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}