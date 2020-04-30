#include <iostream>
#include <algorithm>
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
    int n, m;
    cin >> n >> m;
    vector<string> A(n), Arev(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        A[i] = s;
        reverse(s.begin(),s.end());
        Arev[i] = s;
    }
    sort(A.begin(),A.end());
    sort(Arev.begin(),Arev.end());
    A.emplace_back("{");
    Arev.emplace_back("{");
    for (int _ = 0; _ < m; ++_) {
        string s;
        cin >> s;
        int ans = 0;
        if(s.back() == '*'){
            s.pop_back();
            int cur = -1;
            for (int i = 0; i < s.size(); ++i) {
                if(s[i] == '?') cur = i;
            }
            if(~cur){
                for (char i = 'a'; i <= 'z'; ++i) {
                    s[cur] = i;
                    ans -= lower_bound(A.begin(),A.end(), s) - A.begin();
                    s.push_back('}');
                    ans += lower_bound(A.begin(),A.end(), s) - A.begin();
                    s.pop_back();
                }
            }else {
                ans -= lower_bound(A.begin(),A.end(), s) - A.begin();
                s.push_back('}');
                ans += lower_bound(A.begin(),A.end(), s) - A.begin();
                s.pop_back();
            }
        }else if(s.front() == '*') {
            reverse(s.begin(),s.end());
            s.pop_back();
            int cur = -1;
            for (int i = 0; i < s.size(); ++i) {
                if(s[i] == '?') cur = i;
            }
            if(~cur){
                for (char i = 'a'; i <= 'z'; ++i) {
                    s[cur] = i;
                    ans -= lower_bound(Arev.begin(),Arev.end(), s) - Arev.begin();
                    s.push_back('}');
                    ans += lower_bound(Arev.begin(),Arev.end(), s) - Arev.begin();
                    s.pop_back();
                }
            }else {
                ans -= lower_bound(Arev.begin(),Arev.end(), s) - Arev.begin();
                s.push_back('}');
                ans += lower_bound(Arev.begin(),Arev.end(), s) - Arev.begin();
                s.pop_back();
            }
        }else {
            int cur = -1;
            for (int i = 0; i < s.size(); ++i) {
                if(s[i] == '?') cur = i;
            }
            if(~cur){
                for (char i = 'a'; i <= 'z'; ++i) {
                    s[cur] = i;
                    ans += *(lower_bound(A.begin(),A.end(), s)) == s;
                }
            }else {
                ans += *(lower_bound(A.begin(),A.end(), s)) == s;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}