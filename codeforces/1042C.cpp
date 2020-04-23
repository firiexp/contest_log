#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, p = 0, s = INF<int>, t = -1;
    cin >> n;
    int dd = 0;
    vector<int> v;
    vector<bool> vv(n, true);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d",&k);
        v.emplace_back(k);
        if(k < 0) {
            p++;
            if(abs(k) < abs(s)) {
                s = k;
                t = i;
            }
        }
        if(k == 0){
            vv[i] = false;
            dd++;
        }
    }
    if(p % 2){
        vv[t] = false;
        dd++;
    }
    auto ddd = dd;
    for (int i = 0; i < n; ++i) {
        if(vv[i]) continue;
        bool flag = false;
        for (int j = i+1; j < n; ++j) {
            if(vv[j]) continue;
            printf("1 %d %d\n", i+1, j+1);
            flag = true;
            dd--;
            break;
        }
        if(!flag && (dd>1 || n-ddd >= 1)) {printf("2 %d\n", i+1);}
    }
    for (int i = 0; i < n; ++i) {
        if(!vv[i]) continue;
        for (int j = i+1; j < n; ++j) {
            if(!vv[j]) continue;
            printf("1 %d %d\n", i+1, j+1);
            vv[i] = vv[j] = true;
            break;
        }
    }
    return 0;
}
