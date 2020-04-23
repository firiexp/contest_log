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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> v(n);
    int S = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        S += v[i].second;
    }
    string s;
    cin >> s;
    int val = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i].first == s){
            cout << S - val - v[i].second << "\n";
            return 0;
        }
        val += v[i].second;
    }
    return 0;
}