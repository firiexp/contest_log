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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b;
    cout << "0 0" << endl;
    cin >> a;
    if(a == 0) return 0;
    cout << "0 1000000000" << endl;
    cin >> b;
    if(b == 0) return 0;
    cout << (a+b-1000000000)/2 << " " << (1000000000+a-b)/2 << endl;
    return 0;
}
