#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    vector<int> v{};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        bool flag = false;
        cin >> a;
        sort(v.begin(), v.end());
        if (v.empty()) v.emplace_back(a);
        for (auto &&j : v) {
            if (j >= a){
                j = a;
                flag = true;
                break;
            }
        }
        if(!flag) v.emplace_back(a);
    }
    cout << v.size() << "\n";
    return 0;
}
