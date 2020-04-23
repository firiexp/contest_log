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
    string a, b;
    cin >> a >> b;
    for (auto &&i : a+b) {
        if(i < '0' || '9' < i){
            puts("NG");
            return 0;
        }
    }
    if(to_string(stoi(a)) != a) {
        puts("NG");
        return 0;
    }
    if(to_string(stoi(b)) != b){
        puts("NG");
        return 0;
    }
    if(max(stoi(a), stoi(b)) > 12345) {
        puts("NG");
        return 0;
    }
    puts("OK");
    return 0;
}
