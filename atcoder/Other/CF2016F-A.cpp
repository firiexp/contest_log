#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int h, w;
    string s;
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> s;
            if (s == "snuke") {
                cout << char('A'+j) << i+1 << "\n";
                return 0;
            }
        }
    }
    return 0;
}
