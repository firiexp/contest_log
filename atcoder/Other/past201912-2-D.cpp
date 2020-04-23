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
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        cnt[x-1]++;
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if(!cnt[i]) l = i;
        if(cnt[i] == 2) r = i;
    }
    if(l == -1){
        puts("Correct");
    }else {
        cout << r+1 << " " << l+1 << "\n";
    }
    return 0;
}