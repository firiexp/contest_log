#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a;
    cin >> a;
    int x[4]={a/1000, (a/100)%10, (a/10)%10,  a%10}, y[3];
    int ans;
    for (y[0] = 0; y[0] < 2; ++y[0]) {
        for (y[1] = 0; y[1] < 2; ++y[1]) {
            for (y[2] = 0; y[2] < 2; ++y[2]) {
                ans = 2 * (x[0] + y[0] * x[1] + y[1] * x[2] + y[2] * x[3])
                        - (x[0] + x[1] + x[2] + x[3]);
                if (ans== 7) {
                    cout << x[0];
                    for (int l = 0; l < 3; ++l) {
                        cout << char('-' - 2 * y[l]);
                        cout << x[l+1];
                    }
                    cout << "=7\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
