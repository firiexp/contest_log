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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int a;
    cin >> a;
    if(a%3==0) cout << "1 1 " << a-2 << "\n";
    if(a%3==1) cout << "1 1 " << a-2 << "\n";
    if(a%3==2) cout << "1 2 " << a-3 << "\n";
    return 0;
}
