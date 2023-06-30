#include <iostream>
#include <string>
#include <bitset>
#include "cmath"

using namespace std;

int g(int n) {
    return n ^ (n >> 1);
}


void f(int num, int n) {
    int i;
    for (i = n-1; i >= 0; --i) {
        printf("%d", num & (1 << i) ? 1 : 0);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    double c = pow(2, n);
    for (int i = 0; i < c; ++i) {
        int a = g(i);
        f(a, n);
    }
    return 0;
}


