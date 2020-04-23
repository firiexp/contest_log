#include <iostream>
#include <map>

using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> l;
    for (char &a : s) {
        l[a]++;
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        if(!l[i]){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "None" << "\n";
    return 0;
}
