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
    int m, vv;
    cin >> m;
    if(m < 100){
        vv = 0;
    }else if (m <= 5000){
        vv = m/100;
    }else if (m <= 30000){
        vv = m/1000+50;
    }else if (m <= 70000){
        vv = (m-30000)/5000+80;
    }else vv = 89;
    printf("%02d\n", vv);
    return 0;
}
