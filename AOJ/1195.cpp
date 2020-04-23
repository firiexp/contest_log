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

string s, t;
vector<string> ans;


void dfs(int T){
    if(s.size() == t.size()){
        ans.push_back(t);
        return;
    }
    char c = s[t.size()];
    if(T & (1 << (c -'a'))) {
        t.push_back(c);
        dfs(T);
        t.pop_back();
    }
    if(!(T & (1 << (c+1-'a'))) &&  c != 'z'){
        t.push_back(c+1);
        dfs(T|(1 << (c+1-'a')));
        t.pop_back();
    }
}

int main() {
    while(cin >> s, s != "#"){
        dfs(1);
        cout << ans.size() << "\n";
        if(ans.size() < 10){
            for(auto &&i: ans) cout << i << "\n";
        }else {
            for (int i = 0; i < 5; ++i) {
                cout << ans[i] << "\n";
            }
            for (int i = (int)ans.size()-5; i < ans.size(); ++i) {
                cout << ans[i] << "\n";
            }
        }
        ans.clear();
    }
    return 0;
}