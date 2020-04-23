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
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < (1<<n); ++i) {
        string s;
        int ok = 1, cnt = 0;
        for (int j = 0; j < n; ++j) {
            s += ((i >> j) & 1) + '(';
            if(s.back() == '(') cnt++;
            else cnt--;
            if(cnt < 0) ok = 0;
        }
        if(ok && !cnt) {
            cout << s << "\n";
            stack<int> t;
            vector<int> ls, rs;
            for (int j = 0; j < n; ++j) {
                if(s[j] == '(') t.push(j);
                else {
                    ls.emplace_back(t.top()); rs.emplace_back(j);
                    t.pop();
                }
            }
            for (int x = 0; x < (1 << n); ++x) {
                for (int j = 0; j < (1 << (ls.size())); ++j) {
                    string ans(n, '0');
                    for (int k = 0; k < (ls.size()); ++k) {
                        ans[ls[k]] = ((x & (1 << ls[k])) ? 'C' : 'A' + ((j >> k) & 1));
                        ans[rs[k]] = ((x & (1 << rs[k])) ? 'C' : 'A' + ((j >> k) & 1));
                    }
                    v.emplace_back(ans);
                }
            }

        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << "\n";
    return 0;
}