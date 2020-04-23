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
    string t;
    for (int i = 0; i < 4; ++i) {
        t += "WBWBWWBWBWBW";
    }
    string ss[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
    int p = 0;
    for (int i = 0; i < 12; ++i) {
        if(t[i] != 'W') continue;
        if(t.substr(static_cast<unsigned long long int>(i), 20) == s){
            cout << ss[p] << "\n";
        };
        p++;
    }
    return 0;
}
