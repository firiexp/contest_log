#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string a; int b = 0;
    cin >> a;
    for (auto &x: a) {
        if (x == '1') b++;
    }
    cout << b << "\n";
    return 0;
}