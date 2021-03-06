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
    string s;
    cin >> s;
    if(s.length()%2){
        cout << "NO\n";
        return 0;
    }else if(s.substr(0, s.length()/2) == s.substr(s.length()/2, s.length()/2)){
        cout << "YES\n";
        return 0;
    }else {
        cout << "NO\n";
    }
    return 0;
}
