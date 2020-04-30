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
    int a[] = {0, 1867, 1911, 1925, 1988};
    string s = " MTSH";
    int p, q;
    cin >> p >> q;
    if(p){
        cout << a[p]+q << "\n";
    }else {
        for (int i = 4; i >= 1; --i) {
            if(a[i] < q) {
                cout << s[i] << q-a[i] << "\n";
                break;
            }
        }
    }

    return 0;
}