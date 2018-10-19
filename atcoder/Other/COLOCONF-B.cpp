#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s, t;
    cin >> s;
    stack<char> v;
    for (auto &&i : s) {
        if(i == ',') t += v.top();
        else if(('0' <= i && i <= '9') || i == '(') t += i;
        else if(i == ')') v.pop(), t += i;
        else v.emplace(i);
    }
    cout << t << "\n";
    return 0;
}
