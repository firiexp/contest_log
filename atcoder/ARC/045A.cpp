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
    int i = 0;
    while(cin >> s){
        if(i) cout << " ";
        if(s[0] == 'L') cout << '<';
        else if (s[0] == 'R') cout << '>';
        else cout << 'A';
        i++;
    }
    cout << "\n";
    return 0;
}
