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
    string s, t;
    cin >> s;
    int c = 1;
    for (int i = 0; i < s.length()-1; ++i) {
        if(s[i] == s[i+1]) c++;
        else {
            t += s[i] + to_string(c);
            c = 1;
        }
    }
    t += s[s.length()-1] + to_string(c);
    cout << t << "\n";
    return 0;
}
