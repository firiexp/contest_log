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
    string s;
    cin >> s;
    string t, u;
    t += s[0]; t += s[1];
    u += s[2]; u += s[3];
    int a = stoi(t), b = stoi(u);
    int x = (1 <= a && a <= 12), y = (1 <= b && b <= 12);
    if(!x && !y){
        puts("NA");
    }else if(x && !y){
        puts("MMYY");
    }else if(!x && y){
        puts("YYMM");
    }else {
        puts("AMBIGUOUS");
    }
    return 0;
}