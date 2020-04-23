#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, m, b = 0;
    cin >> t >> n;
    vector<int> v {};
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        v.emplace_back(e);
    }
    cin >> m;
    auto a = v.begin();
    for (int i = 0; i < m; ++i) {
        int e;
        cin >> e;
        while(!(*a <= e && e <= *a + t ) && a != v.end()){
            a++;
        }
        if(a == v.end()) break;
        if(*a <= e && e <= *a + t) {a++; b++;}
    }
    cout << (b == m ? "yes" : "no") << "\n";
    return 0;
}
