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
    string t;
    cin >> t;
    auto f = [](char c){ return c == '4' || c == '7'; };
    string s = to_string(count_if(t.begin(),t.end(), f));
    puts(all_of(s.begin(),s.end(), f) ? "YES" : "NO");
    return 0;
}