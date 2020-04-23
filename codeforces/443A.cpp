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
    getline(cin, s);
    string t;
    for (auto &&i : s) if(isalpha(i)) t += i;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    cout << t.size() << "\n";
    return 0;
}