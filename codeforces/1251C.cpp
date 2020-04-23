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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string A, B;
        for (char i : s) {
            if((i-'0')&1) A += i;
            else B += i;
        }
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        string ans;
        while(!A.empty() || !B.empty()){
            if(A.empty()) {
                ans.push_back(B.back());
                B.pop_back();
            }else if(B.empty()){
                ans.push_back(A.back());
                A.pop_back();
            }else if(A.back() < B.back()){
                ans.push_back(A.back());
                A.pop_back();
            }else {
                ans.push_back(B.back());
                B.pop_back();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}