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
    array<array<int, 15>, 15> v{};
    string s;
    while(cin >> s, s != "#"){
        for (auto &&i : v) fill(i.begin(),i.end(), -1);
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int y = 0, x = 0;
        for (auto &&j : s) {
            if(j == 'b') v[y][x++] = 1;
            else if(j == '/') y++, x = 0;
            else {
                for (int i = 0; i < (j-'0'); ++i) {
                    v[y][x++] = 0;
                }
            }
        }
        v[a-1][b-1] = 0;
        v[c-1][d-1] = 1;
        for (int i = 0; i <= y; ++i) {
            int cnt = 0;
            for (int j = 0; j < 15; ++j) {
                if(v[i][j] == -1){
                    if(cnt) printf("%d", cnt), cnt = 0;
                    if(i != y) printf("/");
                    break;
                }else if(v[i][j] == 0){
                    cnt++;
                }else {
                    if(cnt) printf("%d", cnt), cnt = 0;
                    printf("b");
                }
            }
        }
        puts("");
    }
    return 0;
}