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
    string s, A, B;
    cin >> s;
    int q, f = 0;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            f ^= 1;
        }else {
            int a; char c;
            cin >> a >> c;
            a--; a ^= f;
            if(a){
                B += c;
            }else {
                A += c;
            }
        }
    }
    if(f){
        reverse(B.begin(),B.end());
        reverse(s.begin(),s.end());
        cout << B << s << A << "\n";
    }else {

        reverse(A.begin(),A.end());
        cout << A << s << B << "\n";
    }
    return 0;
}