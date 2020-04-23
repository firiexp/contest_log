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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        deque<char> Q;
        Q.emplace_back(s[0]);
        int cur = 0;
        for (int i = 3; i < s.size(); i += 3) {
            if(s[i-2] == '-'){
                cur++;
                if(Q.size() <= cur) Q.emplace_back(s[i]);
            }else {
                cur--;
                if(cur < 0) Q.emplace_front(s[i]), cur++;
            }
        }
        for (auto &&i : Q) cout << i;
        puts("");
    }
    return 0;
}