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
    int n; string s;
    cin >> n >> s;
    vector<pair<char, int>> c;
    c.emplace_back(s[0], 1);
    for (int i = 1; i < n; ++i) {
        if(s[i] == c.back().first){
            c.back().second++;
        }else {
            c.emplace_back(s[i], 1);
        }
    }
    cout << c.size() << "\n";
    return 0;
}