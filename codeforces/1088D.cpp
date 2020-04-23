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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    cout << "? 0 0" << endl;
    int zero; cin >> zero;
    int A = 0, B = 0;
    for (int i = 29; i >= 0; --i) {
        int ret1, ret2;
        cout << "? " << (A^(1 << i)) << " " << B << endl;
        cin >> ret1;
        cout << "? " << A << " " << (B^(1 << i)) << endl;
        cin >> ret2;
        if(ret1 != ret2){
            if(ret1  == -1){
                A ^= (1 << i);
                B ^= (1 << i);
            }
        }else {
            if(zero == 1) A += 1 << i;
            else B += 1 << i;
            zero = ret1;
        }
    }
    cout << "! " << A << " " << B << endl;
    return 0;
}