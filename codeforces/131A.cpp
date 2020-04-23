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
    string s;
    cin >> s;
    if(s.size() == 1){
        for (auto &&i : s) {
            if(islower(i)) i = toupper(i);
            else i = tolower(i);
        }
    }else {
        int ok = 1;
        for (int i = 1; i < s.size(); ++i) {
            if(islower(s[i])) ok = 0;
        }
        if(ok){
            for (auto &&i : s) {
                if(islower(i)) i = toupper(i);
                else i = tolower(i);
            }
        }
    }
    cout << s << "\n";
    return 0;
}