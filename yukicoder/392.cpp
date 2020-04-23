#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a; a++;
        string s;
        while(a != 1){
            s.push_back(a%2 ? 'R' : 'L');
            a/=2;
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
    return 0;
}
