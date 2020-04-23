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
    string A;
    auto f = [&](string &s){
        int a = 0, b = 0;
        for (int i = 1; i < s.size(); ++i) {
            if(s[i] == 'A') a++;
            else b++;
        }
        if(a < b) b++;
        else a++;
        cout << a << " " << b << "\n";
    };
    while(cin >> A, A != "0"){
        string B, C;
        cin >> B >> C;
        f(A); f(B); f(C);
    }
    return 0;
}