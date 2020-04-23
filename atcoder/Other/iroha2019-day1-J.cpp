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

bool is_parindrome(const string &s, char c = '?'){
    auto n = s.length();
    for (int i = 0; i < (n+1)/2; ++i) {
        if(s[i] == c || s[n-i-1] == c) continue;
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

int main() {
    for (int n = 1; n < 22; ++n) {
        printf("n = %d\n", n);
        map<int, int> m;
        for (int i = 0; i < (1<<n); ++i) {
            string s;
            for (int j = 0; j < n; ++j) {
                s += std::to_string((((i>>j)&1)));
            }
            if(!is_parindrome(s)) continue;
            int cnt = 0;
            int ans = 0;
            for (int j = 0; j < n; ++j) {
                if(s[j] == '1') cnt++;
                else ans += cnt;
            }
            m[ans]++;
        }
        for (auto &&k : m) {
            printf("%d, ", k.first);
        }
        puts("");
        for (auto &&k : m) {
            printf("%d, ", k.second);
        }
        puts("");
    }

    return 0;
}