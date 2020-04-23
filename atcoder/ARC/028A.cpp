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
    int n, a, b, turn = 1;
    cin >> n >> a >> b;
    while(n){
        if(turn%2){
            if(n <= a){
                cout << "Ant\n";
                return 0;
            }
            else n-=a;
        }else{
            if(n <= b){
                cout << "Bug\n";
                return 0;
            }
            else n-=b;
        }
        turn++;
    }
    return 0;
}
