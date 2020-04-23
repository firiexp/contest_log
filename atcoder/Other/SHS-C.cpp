#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double n, m, d;
    cin >> n >> m >> d;
    if (d == 0){
        cout <<  ((m - 1) /n) << "\n";
    }else{
        double k = (2 * m / n - 2 /n);
        double l = (1 - d / n);
        cout << setprecision(10) << (l* k) << "\n";
    }
    return 0;
}