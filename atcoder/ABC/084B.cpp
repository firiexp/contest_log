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
    int a, b;
    string s;
    cin >> a >> b >> s;
    for (int i = 0; i < a; ++i) {
        if('0' > s[i] || s[i] > '9') {
            cout << "No" << "\n";
            return 0;
        }
    }
    if(s[a] != '-'){
        cout << "No" << "\n";
        return 0;
    }
    for (int j = a+1; j < a+b+1; ++j) {
        if('0' > s[j] || s[j] > '9') {
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}
