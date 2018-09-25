#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if(a > b || (n == 1 && a < b)){
        cout << 0 << "\n";
        return 0;
    }else if (n <= 2){
        cout << 1 << "\n";
        return 0;
    }
    cout << ((ll)b-a)*(n-2)+1 << "\n";
    return 0;
}
