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
    cout << 0 << endl;
    string s;
    cin >> s;
    if(s == "Vacant") return 0;
    int l = 0, r = n;
    int i = 18;
    while(--i){
        int mid = (l+r)/2;
        cout << mid << endl;
        string x;
        cin >> x;
        if(x == "Vacant") return 0;
        if(((mid-l)%2) ^(s == x)) l = mid, s = x;
        else r = mid;
    }
    return 0;
}
