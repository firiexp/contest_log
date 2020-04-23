#include "iostream"
#include "algorithm"
#include "iomanip"
#include "map"
#include "set"
#include "queue"
#include "stack"
#include "numeric"
#include "bitset"
#include "cmath"

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        if(a == b) puts("=");
        else if(u32(b-a)&0x80000000) printf("%c\n", 62);
        else  printf("%c\n", 60);
    }
    return 0;
}