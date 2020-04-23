#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    map<int, int> m;
    int s;
    cin >> s;
    m[s] = 1;
    for (int i = 1; i < 1000000; ++i) {
        if(s%2) s = 3*s+1;
        else s = s/2;
        if(m[s]){
            cout << i+1 << "\n";
            break;
        }
        m[s] = i+1;
    }
    return 0;
}
