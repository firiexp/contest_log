#include <iostream>
#include <locale>
using ll = long long;
using namespace std;

int main() {
    char a[20], b[20], c[20];
    cin >> a >> b >> c;
    char d[3]= {a[0], b[0], c[0]};
    for (char i : d) cout << toupper(i, locale::classic());
    cout << "\n";
    return 0;
}