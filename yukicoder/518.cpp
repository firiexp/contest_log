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

int main() {
    vector<string> A{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                   B{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                   C{"", "C", "CC", "CCC", "CD", "D", "DC",  "DCC", "DCCC", "CM"},
                   D{"", "M", "MM", "MMM"};
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        for (int j = 1; j <= 3999; ++j) {
            int jj = j;
            string s;
            s += A[jj%10];
            jj /= 10;
            s = B[jj%10] + s;
            jj /= 10;
            s = D[jj/10] + C[jj%10] + s;
            if(s == t){
                x += j;
                break;
            }
        }
    }
    if(x > 3999) puts("ERROR");
    else {
        string s;
        s += A[x%10];
        x /= 10;
        s = B[x%10] + s;
        x /= 10;
        s = D[x/10] + C[x%10] + s;
        cout << s << "\n";
    }
    return 0;
}