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
    locale::global(locale("ja_JP.UTF-8"));
    wcout.imbue(std::locale("ja_JP.UTF-8"));
    wcin.imbue(std::locale("ja_JP.UTF-8"));
    wstring w;
    wcin >> w;
    int ans=0, t=0;
    for (auto &&i : w) {
        if(i == u'…') t++;
        else t = 0;
        ans = max(ans, t);
    }
    wcout << ans << "\n";
    return 0;
}
