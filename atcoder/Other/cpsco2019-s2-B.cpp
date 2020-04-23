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
    int n;
    cin >> n;
    vector<pair<char, int>> v;
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        char c; int x;
        cin >> c >> x;
        if(c == '+'){
            a += x;
        }else if(c == '*' && x != 0){
            b *= x;
        }
    }
    cout << a*b << "\n";
    return 0;
}