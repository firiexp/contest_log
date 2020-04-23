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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    string s;
    cin >> s;
    int p = 0, q = 0;
    for (char i : s) {
        if(i == 'S') p++;
        else {
            if(p > 0) {
                p--;
                q++;
            }
        }
    }
    cout << s.length()-q*2 << "\n";
    return 0;
}
