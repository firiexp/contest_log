#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    double ans = 0;
    double x[100];
    double y[100];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            double x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
            double t = hypot((y1-y2), (x1-x2));
            if(ans < t) ans = t;
        }
    }
    cout << ans << "\n";
    return 0;
}
