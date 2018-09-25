#include <iostream>
using ll = long long;
using namespace std;
static const int M = 1000000007;
int main() {
    string s;
    ll a[100050][3];
    cin >> s;
    for (auto &j : a) {
        for (ll i : j) {
            i == 0;
        }
    }
    if(s[0] == 'A'){
        a[0][0]++;
    }
    for (int i = 1; i < s.length(); ++i) {
        if(s[i] == 'A'){
            a[i][0] = (a[i-1][0]+1) %M;
            a[i][1] = a[i-1][1];
            a[i][2] = a[i-1][2];
        }
        if(s[i] == 'B'){
            a[i][0] = a[i-1][0];
            a[i][1] = (a[i-1][1]+a[i-1][0])%M;
            a[i][2] = a[i-1][2];
        }
        if(s[i] == 'C'){
            a[i][0] = a[i-1][0];
            a[i][1] = a[i-1][1];
            a[i][2] = (a[i-1][2]+a[i-1][1])%M;
        }
        if(s[i] == '?'){
            a[i][0] = a[i-1][0];

        }
    }
    return 0;
}
