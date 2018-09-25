#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string s;
    ll k;
    cin >> s >> k;
    for (int i = 0; i < min(k , (ll)s.length()); ++i) {
        char e = s[i];
        if(e != '1') {
            cout << e << "\n";
            return 0;
        }
    }
    cout << s[min(k-1 , (ll)s.length()-1)] << "\n";
    return 0;
}
