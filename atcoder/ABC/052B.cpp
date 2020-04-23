#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int m = 0, n = 0, N;
    string s;
    cin >> N >> s;
    for (char &a : s) {
        if (a == 'I') n++;
        else n--;
        m = max(m, n);
    }
    cout << m << "\n";
    return 0;
}
