#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x, a = 0;
    cin >> n;
    long long v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            a += (v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }
    cout << a"\n";
}