#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    int ok = n, ng = 1;
    while(ok-ng > 1){
        int m = (ok+ng)/2;
        if (n >= 4096 && ng == 1 && ok == n) m = 4096;
        printf("? %d", m);
        for (int i = 1; i <= m; ++i) {
            printf(" %d", i);
        }
        cout << endl;
        string s;
        cin >> s;
        if(s == "Rabbit") ok = m;
        else ng = m;
    }
    int ansR = ok;
    ok = 1, ng = ansR;
    while(ng-ok > 1){
        int m = (ok+ng)/2;
        printf("? %d", ansR-m+1);
        for (int i = m; i <= ansR; ++i) {
            printf(" %d", i);
        }
        cout << endl;
        string s;
        cin >> s;
        if(s == "Rabbit") ok = m;
        else ng = m;
    }
    int ansL = ok;
    cout << "! " << ansL << " " << ansR << endl;
    return 0;
}