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
    string s;
    cin >> s;
    auto f = [&](string &s, auto &&f) -> void {
        if(s.size() >= 21) return;
        string t = to_string(2);
        for (int j = 0; j < s.size(); ++j) {
            if(s[j] == '0') t += s.back();
            else t += (s.back() == '0' ? '2' : '0');
        }
        cout << t << "\n";
        f(t, f);
    };
    f(s, f);
    return 0;
}