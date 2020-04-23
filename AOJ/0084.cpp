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
    string s;
    getline(cin, s);
    vector<string> v;
    string t;
    for (auto &&i : s) {
        if(i == ',' || i == ' ' || i == '.'){
            if(3 <= t.size() && t.size() <= 6) v.emplace_back(t);
            t.clear();
        }else t += i;
    }
    for (int i = 0; i < v.size(); ++i) {
        if(i) cout << " ";
        cout << v[i];
    }
    puts("");
    return 0;
}