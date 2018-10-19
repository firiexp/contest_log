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
    int n, x;
    cin >> n >> x;
    if(x == 1 || x == (2*n-1)) {
        cout << "No" << "\n";
        return 0;
    }
    cout << "Yes" << "\n";
    deque<int> Q;
    if(x == 2){
        Q.emplace_back(1);
        Q.emplace_back(2);
        Q.emplace_back(3);
        for (int i = 4; i <= 2*n-1; ++i) {
            if(i%2) Q.emplace_back(i);
            else Q.emplace_front(i);
        }
    }else if(x == 2*n-2){
        Q.emplace_back(2*n-1);
        Q.emplace_back(2*n-2);
        Q.emplace_back(2*n-3);
        for (int i = 2*n-4; i >= 1; --i) {
            if(i%2) Q.emplace_back(i);
            else Q.emplace_front(i);
        }
    }else {
        Q.emplace_back(x+2);
        Q.emplace_back(x-1);
        Q.emplace_back(x);
        Q.emplace_back(x+1);
        Q.emplace_back(x-2);
        int turn = 0;
        for (int i = 1; i < x-2; ++i) {
            if(turn%2) Q.emplace_back(i);
            else Q.emplace_front(i);
            turn++;
        }
        for (int i = x+3; i <= 2*n-1; ++i) {
            if(turn%2) Q.emplace_back(i);
            else Q.emplace_front(i);
            turn++;
        }
    }
    while(!Q.empty()){
        printf("%d\n", Q.front());
        Q.pop_front();
    }
    return 0;
}
