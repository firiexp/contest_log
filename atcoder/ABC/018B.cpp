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
    int n;
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        reverse(s.begin()+l-1, s.begin()+r);
    }
    cout << s << "\n";
    return 0;
}
