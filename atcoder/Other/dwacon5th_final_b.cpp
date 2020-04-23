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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

struct Node {
    int val, sum;
    Node *nxt[2];
    Node() : val(0), nxt{nullptr, nullptr} {}
    static int cnt;
    void *operator new(size_t){
        static Node pool[3000000];
        return pool + cnt++;
    }
};
int Node::cnt = 0;

template<class T, size_t X>
struct Binarytrie {
    Node *root;
    Binarytrie() { root = new Node; }

    void add(const T b, T x = 1){
        Node *p = root;
        p->sum += x;
        for (int i = X-1; i >= 0; --i) {
            bool f = (b >> i) & 1;
            if(!p->nxt[f]) p->nxt[f] = new Node;
            p = p->nxt[f];
            p->sum += x;
        }
        p->val += x;
    }

    T xor_min(Node* t, const T &x, int dep = X-1){
        if(dep < 0) return 0;
        T f = (x >> dep) & 1U; f ^= (!t->nxt[f]) || (!t->nxt[f]->sum);
        return xor_min(t->nxt[f], x, dep-1) | (f << dep);
    }
    T max_element(T x = 0) {
        return xor_min(root, ~x);
    }
    T min_element(T x = 0){
        return xor_min(root, x);
    }
};

int main() {
    int n;
    cin >> n;
    vector<u32> v(n);
    Binarytrie<u32, 30> Trie;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        if(i) v[i] ^= v[i-1];
        if(i != n-1) Trie.add(v[i]);
    }
    vector<u32> ans(n+1);
    for (int i = 0; i < n-1; ++i) {
        u32 x = Trie.min_element(ans[i]);
        Trie.add(x, -1);
        ans[i+1] = x;
    }
    ans.back() = v.back();
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]^ans[i+1]);
    }
    puts("");
    return 0;
}