#include <iostream>
#include <sstream>
#include <bitset>

using ll = long long;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;

    if(n == 0){
        cout << 0 << "\n";
        return 0;
    }
    while (n){
        if (n & 1) {s.insert(0, "1"); n = (n-1)/-2;}
        else {s.insert(0, "0"); n /= -2;}
    }
    cout << s << "\n";
    return 0;
}
