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
    cin >> s;
    int n = s.size();
    vector<array<int, 26>> nxt(n+1);
    vector<array<int, 26>> nxtr(n+1);
    fill(nxt.back().begin(),nxt.back().end(), n+1);
    fill(nxtr[0].begin(),nxtr[0].end(), -1);
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = nxt[i+1];
        nxt[i][s[i]-'a'] = i+1;
    }
    for (int i = 0; i < n; ++i) {
        nxtr[i+1] = nxtr[i];
        nxtr[i+1][s[i]-'a'] = i;
    }
    int q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        int l = nxt[0][t[0]-'a']+1;
        int scur = nxt[0][t[0]-'a'], tcur = 1;
        while(scur < s.size() && tcur < t.size()){
            scur = nxt[scur][t[tcur]-'a'];
            tcur++;
        }
        if(scur > s.size() || tcur != t.size()) {
            puts("-1");
            continue;
        }
        int r = scur; tcur = t.size()-1;
        while(scur >= 0 && tcur >= 0){
            scur = nxtr[scur][t[tcur]-'a'];
            tcur--;
        }
        printf("%d %d\n", scur+1, r);
    }
    return 0;
}