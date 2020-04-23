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

vector<int> v{20104, 20063, 19892, 20011, 19874, 20199, 19898, 20163, 19956, 19841};



int main() {
    vector<int> cnt(10);
    string s;
    cin >> s;
    for (auto &&i : s) {
        if(isdigit(i)) v[i-'0']--;
    }
    for (int i = 0; i < 10; ++i) {
        if(v[i] < 0) printf("%d", i);
    }
    for (int i = 0; i < 10; ++i) {
        if(v[i] > 0) printf(" %d", i);
    }
    puts("");
    return 0;
}