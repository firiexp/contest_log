#include <iostream>
#include <queue>
using namespace std;

int main() {
    vector<string> v{"black","blue","lime","aqua","red","fuchsia","yellow","white"};
    string s;
    while(cin >> s, s != "0") cout << v[4*(s[1]>'7')+2*(s[3]>'7')+1*(s[5]>'7')] << "\n";
    return 0;
}