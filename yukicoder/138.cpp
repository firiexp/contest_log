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
    vector<int> v(3), v1(3);
    scanf("%d.%d.%d", &v[0], &v[1], &v[2]);
    scanf("%d.%d.%d", &v1[0], &v1[1], &v1[2]);
    if(v >= v1){
        cout << "YES\n";
        return 0;
    }else if(v < v1){
        cout << "NO\n";
        return 0;
    }
    return 0;
}
