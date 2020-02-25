#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a, b , f[100000];
int n , m;
int gf(int x){
    return f[x] == x? x:f[x] = gf(f[x]);
}
int main() {
    cin >> n >> m;
    for (int i =0;i < n; i++) f[i] = i;
    for (int i= 1;i <=m; i++){
        cin >> a >> b;
        f[gf(a)] = gf(b);
    }
    int ans = 0;
    for (int i =0; i <n; i++){
        ans += gf(i) == i;
    }
    cout << ans << endl;
    return 0;
}
