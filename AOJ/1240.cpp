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
    int q;
    cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        int m = t.size();
        reverse(s.begin(),s.end());
        for (auto &&i : s) {
            string tt(t);
            if(i == 'J'){
                for (int j = 0; j < m; ++j) {
                    tt[j] = t[(j+m-1)%m];
                }
            }else if(i == 'C'){
                for (int j = 0; j < m; ++j) {
                    tt[j] = t[(j+1)%m];
                }
            }else if(i == 'E'){
                for (int j = 0; j < m/2; ++j) {
                    tt[j+(m+1)/2] = t[j];
                    tt[j] = t[j+(m+1)/2];
                }
            }else if(i == 'A'){
                reverse(tt.begin(),tt.end());
            }else if(i == 'P') {
                for (int j = 0; j < m; ++j) {
                    if('0' <= tt[j] && tt[j] <= '9'){
                        tt[j] = '0' + (tt[j]-'0'+9)%10;
                    }
                }

            }else {
                for (int j = 0; j < m; ++j) {
                    if('0' <= tt[j] && tt[j] <= '9'){
                        tt[j] = '0' + (tt[j]-'0'+1)%10;
                    }
                }
            }
            t = tt;
        }
        cout << t << "\n";
    }
    return 0;
}