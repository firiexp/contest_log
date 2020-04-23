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
using namespace std;

int main() {
    int n;
    cin >> n;
    int one = int(), zero = one++;
    int three = one+one+one, five = three+one+one;
    for (int i = one; i <= n; ++i) {
        string ans;
        if(!(i%three)) ans += "Fizz";
        if(!(i%five)) ans += "Buzz";
        cout << (ans.size() ? ans : to_string(i)) << "\n";
    }
    return zero;
}