#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    int a[3];
    int x = 0, y = 0, z = 0;
    while (true){
        for (int &i : a) cin >> i;
        sort(a, a+3);
        if (a[0]+ a[1] <= a[2]) break;
        if (a[0] * a[0] + a[1]  * a[1] == a[2] * a[2]) x++;
        else if (a[0] * a[0] + a[1] * a[1] < a[2] * a[2]) z++;
        else y++;
    }
    printf("%d %d %d %d\n",x+y+z, x, y, z);
    return 0;
}
