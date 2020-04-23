#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int l, r, a;
    cin >> l >> r >> a;
    if(l > r){
        int v = min(l-r, a);
        r += v;
        a -= v;
    }else if (l < r){
        int v = min(r-l, a);
        a -= v;
        l += v;

    }
    if(a > 0){
        l += a/2; r += a/2;
    }
    cout << min(l, r)*2 << "\n";
    return 0;
}
