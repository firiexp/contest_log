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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    string n;
    int m = 0;
    cin >> n;
    for (auto &&x : n) {
        m += x - '0';
    }
    if(m == (n.length()-1)*9+n[0]-'0'){
        cout << (n.length()-1)*9+n[0]-'0' << "\n";
    }else {
        cout << (n.length()-1)*9+n[0]-'0'-1 << "\n";
    }
    return 0;
}
