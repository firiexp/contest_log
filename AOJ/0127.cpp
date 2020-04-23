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
    map<string, int> m;
    for (int i = 0; i < 26; ++i) {
        m[string{char(i/5+'1'), char(i%5+'1')}] = 'a'+i;
    }
    m["62"] = '.';
    m["63"] = '?';
    m["64"] = '!';
    m["65"] = ' ';
    while(getline(cin, s)){
        if(s.size()&1){
            puts("NA");
            continue;
        }
        string ans;
        for (int i = 0; i < s.size(); i += 2) {
            if(m.count(s.substr(i, 2))){
                ans += m[s.substr(i, 2)];
            }else{
                ans.clear();
                break;
            }
        }
        if(ans.empty()) puts("NA");
        else cout << ans << "\n";
    }
    return 0;
}