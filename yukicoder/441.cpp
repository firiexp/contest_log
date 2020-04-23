#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s, t;
    cin >> s >> t;
    if(s.size() > 1 && t.size() > 1){
        puts("P");
    }else if(s.size() > 1) {
        if(t == "0" || t == "1") puts("S");
        else puts("P");
    }else if(t.size() > 1){
        if(s == "0" || s == "1") puts("S");
        else puts("P");
    }else {
        int a = stoi(s), b = stoi(t);
        if(a+b < a*b) puts("P");
        else if(a+b == a*b) puts("E");
        else puts("S");
    }

    return 0;
}
