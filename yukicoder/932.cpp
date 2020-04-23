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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s;
    cin >> s;
    int val = count_if(s.begin(),s.end(), [](char c){
        return c == 'C';
    });
    int val2 = count_if(s.begin(),s.end(), [](char c){
        return c == ',';
    })+1;
    if(val == val2) puts("Done!");
    else puts("Failed...");
    return 0;
}