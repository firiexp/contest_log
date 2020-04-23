#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string a;
    int c = 0;
    cin >> a;
    if (a[0] != 'A') {
        cout << "WA";
        return 0;
    }
    for (int i = 2; i < a.length()-1; ++i) {
        if('a'<= a[i] && a[i] <= 'z') continue;
        if(a[i] == 'C') c++;
    }
    if(a[1] < 'a'  || 'z' < a[1]) {c = 114514;}
    if(a[a.length()-1] < 'a'  || 'z' < a[a.length()-1]) {c = 114514;}
    if (c == 1) cout << "AC";
    else cout << "WA";
    return 0;
}
