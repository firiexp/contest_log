#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    vector<string> v = {".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
                        "wxyz"};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int cur = 0;
        string ans;
        while(cur < s.size()){
            while(s[cur] != '0'){
                int cur2 = cur;
                while(s[cur] == s[cur2+1]) cur2++;
                ans += v[s[cur]-'1'][(cur2-cur)%v[s[cur]-'1'].size()];
                cur = cur2+1;
            }
            cur++;
        }
        cout << ans << "\n";
    }
    return 0;
}
