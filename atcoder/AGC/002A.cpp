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
    int a, b;
    cin >> a >> b;
    string ans;
    if(a <= 0 && 0 <= b){
        ans = "Zero";
    }else if(a > 0 && b > 0){
        ans = "Positive";
    }else {
        if((b + a -1)%2) ans = "Negative";
        else ans = "Positive";
    }
    cout << ans << "\n";
    return 0;
}
