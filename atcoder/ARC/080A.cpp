#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    int p = 0, q = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d",&k);
        if(k%4 == 0){
            p++;
        }else if(k%2 == 0){
            q++;
        }else r++;
    }
    if(q == 0){
        cout << (r <= p+1 ? "Yes" : "No") << "\n";
    }else {
        cout << (r <= p ? "Yes" : "No") << "\n";
    }

    return 0;
}
