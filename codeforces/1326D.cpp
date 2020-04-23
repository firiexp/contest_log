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


vector<int> manacher(const string &s){
    vector<int> res(s.size());
    int i = 0, j = 0;
    while(i < s.size()){
        while(i >= j && i + j < s.size() && s[i-j] == s[i+j]) ++j;
        res[i] = j;
        int k = 1;
        while(i >= k && i + k < s.size() && k + res[i-k] < j) res[i+k] = res[i-k], ++k;
        i += k; j -= k;
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    string x;
    while(t--){
        string s;
        cin >> s;
        x.clear();
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if(i) x += '$';
            x += s[i];
        }
        auto p = manacher(x);
        vector<int> ok((n+1)/2+1);
        ok[0] = 1;
        for (int i = 0; i < (n+1)/2; ++i) {
            if(s[i] != s[n-i-1]) break;
            ok[i+1] = 1;
        }
        int ans = 0, val = 0;
        for (int i = 0; i < x.size(); ++i) {
            if(i&1){ // even
                if(p[i] == 1) continue;
                int l = i/2-p[i]/2+1, r = i/2+p[i]/2;
                int w = min(l, n-r-1);
                if(ok[w] && w*2+r-l+1 > ans){
                    val = i;
                    ans = w*2+r-l+1;
                }
            }else {
                int l = i/2-(p[i]-1)/2, r = i/2+(p[i]-1)/2;
                int w = min(l, n-r-1);
                if(ok[w] && w*2+r-l+1 > ans){
                    val = i;
                    ans = w*2+r-l+1;
                }
            }
        }

        if(val&1){
            int l = val/2-p[val]/2+1, r = val/2+p[val]/2;
            int w = min(l, n-r-1);
            cout << s.substr(0, w)+s.substr(l, r-l+1)+s.substr(n-w, n) << "\n";
        }else {
            int l = val/2-(p[val]-1)/2, r = val/2+(p[val]-1)/2;
            int w = min(l, n-r-1);
            cout << s.substr(0, w)+s.substr(l, r-l+1)+s.substr(n-w, n) << "\n";
        }
    }
    return 0;
}