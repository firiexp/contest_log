#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length()-1; ++i) {
        if(s[i] == 'A' && s[i+1] == 'C'){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
