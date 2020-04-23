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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

struct Node {
    int val;
    Node *l, *r;
    Node() : val(0), l(nullptr), r(nullptr) {}
    static int cnt;
    void *operator new(size_t){
        static Node pool[1540000];
        return pool + cnt++;
    }
};
int Node::cnt = 0;

template<class T, size_t X>
struct Binarytrie {
    Node *root;
    Binarytrie() { root = new Node; }

    void add(const T b, int x = 1){
        Node *p = root;
        for (int i = X-1; i >= 0; --i) {
            bool f = (b >> i) & 1;
            if(!f && !p->l) p->l = new Node;
            if(f && !p->r) p->r = new Node;
            p = (f ? p->r : p->l);
        }
        p->val += x;
    }
};


int main() {
    int n;
    cin >> n;
    Binarytrie<int, 30> tree;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        tree.add(x);
    }
    auto rec = [&](int X, Node* p, auto &&f) -> int {
        if(!p) return 0;
        if(!p->l) return f(X-1, p->r, f);
        if(!p->r) return f(X-1, p->l, f);
        return min(f(X-1, p->r, f), f(X-1, p->l, f)) + (1 << X);
    };
    cout << rec(29, tree.root, rec) << "\n";
    return 0;
}