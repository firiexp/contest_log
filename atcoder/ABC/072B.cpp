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
    for (int i = 0; i < (s.length()+1)/2; ++i) {
        cout << s[i*2];
    }
    cout << "\n";
    return 0;
}
