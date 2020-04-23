#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

/* initialize */
auto p = [](int i) -> int {return i/2;};
auto l = [](int i) -> int{return 2 *i;};
auto r = [](int i) -> int{return 2*i+1;};
int H,temp;
int A[2000001];

void increasekey(int i, int key) {
    if ( key < A[i]) return;
    A[i] = key;
    while (i > 1 && A[p(i)] < A[i]){
        temp = A[p(i)]; A[p(i)] = A[i]; A[i] = temp;
        i = p(i);
    }
}

void maxheapify(int i){
    int largest,temp;
    int le=l(i), ri=r(i);
    if (le <= H && A[le] > A[i]) largest = le;
    else largest = i;
    if (ri <= H && A[ri] > A[largest]) largest = ri;
    if (largest!=i){
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxheapify(largest);
    }
}

void ins(int key){
    H++;
    A[H] = -(1<<30);
    increasekey(H, key);
}

int ext() {
    int maxv;
    if (H < 1) return -(1<<30);
    maxv = A[1];
    A[1] = A[H--];
    maxheapify(1);
    return maxv;
}

/* main */
int main() {
    int key;
    char c[10];

    while(true){
        scanf("%s", c);
        if (c[0] == 'e' and c[1] == 'n') break;
        else if (c[0] == 'i') {scanf("%d", &key); ins(key);}
        else printf("%d\n", ext());
    }
    return 0;
}