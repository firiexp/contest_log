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
    int n;
    map<string, int> v;
    cin >> n;
    string t;
    cin >> t;
    char x = t[t.length()-1];
    v[t]++;
    for (int i = 0; i < n-1; ++i) {
        string s;
        cin >> s;

        if(v[s] || (s[0] != x)) {
            cout << "No" << "\n";
            return 0;
        }else {
            v[s]++;
            x = s[s.length()-1];
        }
    }
    cout << "Yes" << "\n";
    return 0;
}
