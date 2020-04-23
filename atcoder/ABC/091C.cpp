#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using ll = long long;
using namespace std;
template<typename T, typename U>
using P = pair<T, U>;

bool comparesecond(const P<int , int>& p1, const P<int, int>& p2){
    return p1.second > p2.second;
}

int main() {
    int n, ans = 0;
    vector<P<int, int>> vr, vb;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        vr.emplace_back(a, b);
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        vb.emplace_back(a, b);
    }
    sort(vb.begin(), vb.end());
    sort(vr.begin(), vr.end(), comparesecond);
    for (auto &b: vb) {
        auto r = vr.begin();
        while (r != vr.end()){
            if((*r).first < b.first && (*r).second < b.second){
                r = vr.erase(r);
                ans++;
                break;
            }else r++;
        }
    }
    cout << n-vr.size() << "\n";
    return 0;
}
