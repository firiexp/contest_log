#include <iostream>
#include <cmath>

using ll = long long;
using namespace std;

int main() {
    double w,h;
    cin >> w >> h;
    if(fabs(w/h - 16.0/9.0) <= 1e-9) cout << "16:9" << "\n";
    else cout << "4:3" << "\n";
    return 0;
}
