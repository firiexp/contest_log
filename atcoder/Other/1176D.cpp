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

constexpr int M = 2750131;

array<int, M+1> ar{};

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= M; ++i) {
        if(!ar[i]){
            for (int j = i<<1; j <= M; j += i) {
                ar[j] = i;
            }
        }
    }
    int cnt = 1;
    for (int i = 2; i <= M; ++i) {
        if(!ar[i]) ar[i] = cnt++;
        else ar[i] = i/ar[i];
    }
    multiset<int, greater<>> s;
    for (int i = 0; i < 2*n; ++i) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    vector<int> ans(n);
    auto cur = s.begin();
    for (int i = 0; i < n; ++i) {
        int X = ar[*cur];
        ans[i] = X;
        s.erase(s.find(X));
        cur = s.erase(cur);
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}