#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int n, m, a;
    int s = 0;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        s += a;
        v[i] = s / m;
        s = s % m;
    }
    for (int i = 0; i < n-1; ++i) {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[n-1]);
    return 0;
}
