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
    string s[] = {"I","II","III","IIII","V","VI","VII","VIII","IX","X","XI","XII"};
    string t;
    int x;
    cin >> t >> x;
    for (int i = 0; i < 12; ++i) {
        if(s[i] == t){
            cout << s[(i+x+120000)%12] << "\n";
        }
    }

    return 0;
}
