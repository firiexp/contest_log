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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int G[9][9], wrong[9][9];
int cnt[9];

int main() {
    int t;
    cin >> t;
    int a = 0;
    while(t--){
        if(a++) puts("");
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cin >> G[i][j];
                G[i][j]--;
                wrong[i][j] = 0;
            }
        }
        fill(cnt, cnt+9, 0);
        for (int i = 0; i < 9; ++i) {
            fill(cnt, cnt+9, 0);
            for (int j = 0; j < 9; ++j) cnt[G[i][j]]++;
            for (int j = 0; j < 9; ++j) if(cnt[G[i][j]] >= 2) wrong[i][j] = 1;
        }
        for (int i = 0; i < 9; ++i) {
            fill(cnt, cnt+9, 0);
            for (int j = 0; j < 9; ++j) cnt[G[j][i]]++;
            for (int j = 0; j < 9; ++j) if(cnt[G[j][i]] >= 2) wrong[j][i] = 1;
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                fill(cnt, cnt+9, 0);
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        cnt[G[i*3+k][j*3+l]]++;
                    }
                }
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if(cnt[G[i*3+k][j*3+l]] >= 2) wrong[i*3+k][j*3+l] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                putchar(wrong[i][j] ? '*' : ' ');
                printf("%d", G[i][j]+1);
            }
            puts("");
        }
    }
    return 0;
}