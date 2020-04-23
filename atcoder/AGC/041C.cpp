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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    if(n == 2){
        puts("-1");
    }else if(n == 3){
        puts("aa.\n..b\n..b");
    }else if(n == 6){
        puts("aa....\n..b...\n..b...\n...aa.\n.....b\n.....b");
    }else if(n == 7){
        puts("aabb..c\nb..aa.c\nba....d\n.a..aad\n..a..bc\n..a..bc\nccddcc.");
    }else if(n == 11){
        puts("aabb..c....\nb..aa.c....\nba....d....\n.a..aad....\n..a..bc....\n..a..bc....\nccddcc.....\n.......aabd\n.......ccbd\n.......bdaa\n.......bdcc");
    }else {
        vector<string> A, B;
        A = {"aabd", "ccbd", "bdaa", "bdcc"};
        B = {"aabba", "bcc.a", "b..db", "a..db", "abbaa"};
        vector<string> v(n, string(n, '.'));
        for (int i = 0; i*4 <= n; ++i) {
            if((n-i*4)%5==0){
                int j = (n-i*4)/5;
                int cur = 0;
                for (int k = 0; k < i; ++k) {
                    for (int l = 0; l < 4; ++l) {
                        for (int m = 0; m < 4; ++m) {
                            v[cur+l][cur+m] = A[l][m];
                        }
                    }
                    cur += 4;
                }
                for (int k = 0; k < j; ++k) {
                    for (int l = 0; l < 5; ++l) {
                        for (int m = 0; m < 5; ++m) {
                            v[cur+l][cur+m] = B[l][m];
                        }
                    }
                    cur += 5;
                }
                for (int k = 0; k < n; ++k) {
                    cout << v[k] << "\n";
                }
                return 0;
            }
        }
    }

    return 0;
}