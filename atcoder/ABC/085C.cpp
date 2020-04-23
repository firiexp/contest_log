#include <iostream>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;
    for (int i = 0;  i <= n; i++) {
        for (int j = 0; i + j <= n; j++) {
            if(i*10000 + j*5000 + (n-i-j)*1000 == y){
                printf("%d %d %d\n", i, j, n-i-j);
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << "\n";
}