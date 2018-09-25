#include <iostream>
using namespace std;

int main() {
    string s, ans;
    int w;
    cin >> s >> w;
    for (int i = 0; i < ((s.size() + w-1) / w); ++i) {
        ans += s[i*w];
    }
    cout << ans << "\n";
}