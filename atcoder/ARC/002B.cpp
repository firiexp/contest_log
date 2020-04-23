#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <boost/date_time/gregorian/gregorian.hpp>
using boost::gregorian::date;
static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    date day1(y+400, m, d);
    while((day1.year()-400) % (day1.month()*day1.day())){
        day1 += (boost::gregorian::date_duration(1));
    }
    printf("%d/%02d/%02d\n", day1.year()-400, day1.month()-0, day1.day()-0);
    return 0;
}
