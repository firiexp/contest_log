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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n;
    cin >> n;
    if(n == 1){
        cout << "! 1" << endl;
        return 0;
    }
    vector<int> v(n);
    iota(v.begin(),v.end(), 1);
    for (int i = 0; i < 2*n; ++i) {
        cout << "?";
        int cnt = 2*n, cntt = 0;
        if(i&1) {
            for (int j = 0; j < n/2*2; ++j) {
                cout << " " << v[j];
                cnt--; cntt++;
            }
        }else {
            for (int j = 0; j < (n-1)/2*2; ++j) {
                cout << " " << v[(j+1)%n];
                cnt--; cntt++;
            }
        }
        for (int j = 0; j < cnt; ++j) {
            cout << " 0";
        }
        cout << endl;
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if(j < cntt && c == '>'){
                if(i&1){
                    swap(v[j*2], v[j*2+1]);
                }else {
                    swap(v[j*2+1], v[(j*2+2)%n]);
                }
            }
        }
    }
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << endl;
    return 0;
}