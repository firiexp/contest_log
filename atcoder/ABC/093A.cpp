#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a[300] = {};
    char x, y, z;
    scanf("%c%c%c", &x, &y, &z);
    a[x]++; a[y]++; a[z]++;
    if(a['a'] == a['b'] && a['b'] == a['c']) cout << "Yes";
    else cout << "No";
    return 0;
}