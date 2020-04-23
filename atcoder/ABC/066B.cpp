#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    string s;
    cin >> s;
    for (u32 i = (s.length()-1)/2; i >= 0; i--) {
        if(s.substr(0, i) == s.substr(i, i)){
            cout << i*2 << "\n";
            return 0;
        }
    }
    return 0;
}
