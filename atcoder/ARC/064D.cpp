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
    u32 n;
    string s;
    cin >> n >> s;
    vector<int> v(n, 0);
    int p = 1;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') for (int j = max(p, i); j < n; ++j) {
            if(s[j] == ')') {
                v[i] = v[j] = 1;
                p = j+1;
                break;
            }
        }
    }
    u32 a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if(!v[i]){
            (s[i] == '(' ? a : b)++;
        }
    }
    cout << string(b, '(') << s << string(a, ')') << "\n";
    return 0;
}
