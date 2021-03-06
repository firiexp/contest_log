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
    vector<int> v(26);
    for (char i : s) {
        v[i-'a']++;
    }
    int valid = 1;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if(v[i] && v[j] && v[i] != v[j]) valid = 0;
        }
    }
    puts(valid ? "Yes" : "No");
    return 0;
}