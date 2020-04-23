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

array<array<int, 10>, 10> v{};
array<int, 8> dx {-1, -1, -1, 0, 0, 1, 1, 1}, dy{-1, 0, 1, -1, 1, -1, 0, 1};

int turn1(){
    int res1 = 0, res2 = 0, m = 0;
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            if(v[i][j] != 0) continue;
            int kes = 0;
            for (int k = 0; k < 8; ++k) {
                int p = dy[k], q = dx[k];
                int s = i, t = j;
                int kess = 0;
                while(v[s+p][t+q] == 2) kess++, s += p, t += q;
                if(v[s+p][t+q] == 1) kes += kess;
            }
            if(m < kes) res1 = i, res2 = j, m = kes;
        }
    }
    if(m){
        v[res1][res2] = 1;
        for (int k = 0; k < 8; ++k) {
            int p = dy[k], q = dx[k];
            int s = res1, t = res2;
            while(v[s+p][t+q] == 2) s += p, t += q;
            if(v[s+p][t+q] == 1) {
                s = res1, t = res2;
                while(v[s+p][t+q] == 2) v[s+p][t+q] = 1, s += p, t += q;
            }
        }
        return 1;
    }
    return 0;
}

int turn2(){
    int res1 = 0, res2 = 0, m = 0;
    for (int i = 8; i >= 1; --i) {
        for (int j = 8; j >= 1; --j) {
            if(v[i][j] != 0) continue;
            int kes = 0;
            for (int k = 0; k < 8; ++k) {
                int p = dy[k], q = dx[k];
                int s = i, t = j;
                int kess = 0;
                while(v[s+p][t+q] == 1) kess++, s += p, t += q;
                if(v[s+p][t+q] == 2) kes += kess;
            }
            if(m < kes) res1 = i, res2 = j, m = kes;
        }
    }
    if(m){
        v[res1][res2] = 2;
        for (int k = 0; k < 8; ++k) {
            int p = dy[k], q = dx[k];
            int s = res1, t = res2;
            while(v[s+p][t+q] == 1) s += p, t += q;
            if(v[s+p][t+q] == 2) {
                s = res1, t = res2;
                while(v[s+p][t+q] == 1) v[s+p][t+q] = 2, s += p, t += q;
            }
        }
        return 1;
    }
    return 0;
}


int main() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            v[i][j] = -1;
        }
    }
    for (int i = 0; i < 8; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            if(s[j] == 'o') v[i+1][j+1] = 1;
            else if(s[j] == 'x') v[i+1][j+1] = 2;
            else v[i+1][j+1] = 0;
        }
    }
    int turn = 0;
    while(true){
        if(!turn) {
            int res = turn1();
            if(!res) {
                res = turn2();
                turn ^= 1;
            }
            if(!res) break;
        }else {
            int res = turn2();
            if(!res) {
                res = turn1();
                turn ^= 1;
            }
            if(!res) break;
        }
        turn ^= 1;
    }
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            if(v[i][j] == 0) printf(".");
            else if(v[i][j] == 1) printf("o");
            else printf("x");
        }
        puts("");
    }
    return 0;
}