#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a[2];
    for (auto &x : a) {
        cin >> x;
        if (x == 2){
            x = 3;
        } else if (x > 7){
            if (x%2 == 0) x = 1;
            else x = 2;
        } else {
            if (x%2 == 0) x = 2;
            else x = 1;
        }
    }
    if (a[0] == a[1]) cout << "Yes"; else cout << "No";
    return 0;
}