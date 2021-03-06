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
    int a;
    string s;
    cin >> a >> s;
    for (char i : s) {
        if(!a) {cout << "Yes" << "\n"; return 0;}
        if(i == '+') a++;
        else a--;
    }
    if(!a) {cout << "Yes" << "\n"; return 0;}
    cout << "No" << "\n";
    return 0;
}
