#include <iostream>
#include <map>

using ll = long long;
using namespace std;

int main() {
    int n;
    string s;
    map<char, int> m;
    cin >> n >> s;
    for (auto &&c : s) {
       m[c]++;
    }
    int a = 0, b = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if(m[i] == 0) continue;
        else if(m[i] == 1) a++;
        else b++;
    }
    if (a > 1 && b == 0) cout << "No" << "\n";
    else cout << "Yes" << "\n";
    return 0;
}
