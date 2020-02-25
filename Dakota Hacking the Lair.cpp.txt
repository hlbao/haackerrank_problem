#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int f[10010], v[101];
int m, x;
int main() {
    cin >> m >> x;
    int n = 1;
    for (; n<=m; n++){
        long long cnt = 1;
        for (int j =1; j <= x; j++) cnt *= n;
        if (cnt > m) break;
        v[n] = cnt;
    }
    f[0] = 1;
    for (int i =1; i < n ;i++){
        // cout << v[i] << endl;
        for (int j = m; j >= v[i] ;j --)
            f[j] += f[j - v[i]];
    }
    cout << f[m] << endl;
    return 0;
}
