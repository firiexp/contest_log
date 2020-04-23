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
    ll x;
    cin >> x;
    ll p = x/11*2;
    if(x%11 > 6) {
        p+=2;
    }else if(x%11 >= 1){
        p+=1;
    }
    cout << p << "\n";
    return 0;
}
