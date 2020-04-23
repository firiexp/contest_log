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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> ok(n);
    for (int i = 0; i < n; ++i) {
        cout << "? " << n-1 << endl;
        for (int j = 0; j < n; ++j) {
            if(i != j) printf("%d ", j+1);
        }
        cout << endl;
        int ret;
        cin >> ret;
        ok[i] = 1-ret;
    }
    int ans = accumulate(ok.begin(),ok.end(), 0);
    cout << "! " << ans << endl;
    for (int i = 0; i < n; ++i) {
        if(ok[i]){
            cout << i+1 << " ";
        }
    }
    cout << endl;
    return 0;
}