#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string s;
    int C = 0;
    cin >> s;
    for(char &a: s){
        if(a == '+') C++;
        else C--;
    }
    cout << C << "\n";
    return 0;
}
