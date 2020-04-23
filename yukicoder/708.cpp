#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int expr(string &s, int &i);
int factor(string &s, int &i);

int factor(string &s, int &i) {
    if(isdigit(s[i])) return (s[i++] - '0');
    i++;
    int ret = expr(s, i);
    i++;
    return ret;
}

int expr(string &s, int &i) {
    int val = factor(s, i);
    while (s[i] == '+' || s[i] == '-'){
        char op = s[i];
        i++;
        int val2 = factor(s, i);
        if(op == '+') val += val2;
        else val -= val2;
    }
    return val;
}


int main() {
    string s;
    cin >> s;
    int cur = 0;
    cout << expr(s, cur) << "\n";
    return 0;
}
