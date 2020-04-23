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
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;



int main() {
    string s;
    cin >> s;
    map<char, int> m;
    for (auto &&i : s) {
        m[i]++;
    }
    int c = 0;
    for (auto &&i : m) {
        if(i.second%2) c++;
    }
    if(c <= 1){
        puts("First");
        return 0;
    }
    cout << (s.size()%2 ? "First" : "Second") << "\n";
    return 0;
}
