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
    vector<string> v{"SAT", "FRI", "THU", "WED", "TUE", "MON", "SUN"};
    string s;
    cin >> s;
    for (int i = 0; i < 7; ++i) {
        if(v[i] == s){
            cout << i+1 << "\n";
        }
    }
    return 0;
}