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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int ask(int x, int y, int z) {
	int d;
	cout << "?" << " " << x << " " << y << " " << z << endl;
	cin >> d;
	return d;
}

void answer(int x, int y, int z) {
	cout << "!" << " " << x << " " << y << " " << z << endl;
}

int main() {
    vector<int> ls(3, -100), rs(3, 101);
    while(rs[0]-ls[0] > 1){
        int mid = (rs[0]+ls[0])/2;
        if(ask(mid, ls[1], ls[2]) - ask(mid-1, ls[1], ls[2]) < 0) ls[0] = mid;
        else rs[0] = mid;
    }
    while(rs[1]-ls[1] > 1){
        int mid = (rs[1]+ls[1])/2;
        if(ask(ls[0], mid, ls[2]) - ask(ls[0], mid-1, ls[2]) < 0) ls[1] = mid;
        else rs[1] = mid;
    }
    while(rs[2]-ls[2] > 1){
        int mid = (rs[2]+ls[2])/2;
        if(ask(ls[0], ls[1], mid) - ask(ls[0], ls[1], mid-1) < 0) ls[2] = mid;
        else rs[2] = mid;
    }
    answer(ls[0], ls[1], ls[2]);
    return 0;
}