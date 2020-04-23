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

void poster(int n,int k){
    if(n == 0)  {
        cout << "J";
        return;
    }
    if(k < (1 << (n-1))){
        cout << string((1 << (n - 1)), 'J');
        cout << string((1 << (n - 1)), 'O');
    }else{
        cout << string((1 << (n - 1)), 'I');
        poster(n-1, k-(1 << (n-1)));
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    poster(n, k-1);
    cout << "\n";
    return 0;
}
