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
    int n, a, b;
    cin >> n >> a >> b;
    if(a == 1 && b == 2){
        cout << "Borys" << "\n";
        return 0;
    }
    if((b-a)%2){
        cout << "Borys\n";
    }else {
        cout << "Alice\n";
    }
    return 0;
}
