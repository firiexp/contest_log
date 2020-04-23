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
    string s;
    cin >> s;
    ll q = 0, qa = 0, qaq = 0;
    for (auto &&i : s) {
        if(i == 'Q') q++, qaq += qa;
        else if(i == 'A') qa += q;
    }
    cout << qaq << "\n";
    return 0;
}