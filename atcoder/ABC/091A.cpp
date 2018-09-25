#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a[3];
    for (auto &&item : a) cin >> item;
    if (a[0] + a[1] >= a[2]) cout << "Yes";
    else cout << "No";
    return 0;
}