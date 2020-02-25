#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a, b , f[100000];
int n , m;
struct Edge{
    int u, v, c;
}w[100000];
bool cmp(Edge a, Edge b){
    return a.c < b.c;
}
int gf(int x){
    return f[x] == x? x:f[x] = gf(f[x]);
}
int main() {
    cin >> n >> m;
    for (int i =0;i < n; i++) f[i] = i;
    for (int i= 1;i <=m; i++){
        cin >> w[i].u >> w[i].v >> w[i].c;     
    }
    sort(w +1, w + m + 1, cmp);
    int ans = 0;
    for (int i =1; i <=m; i++){
        if (gf(w[i].u) != gf(w[i].v)){
            f[gf(w[i].u)] = gf(w[i].v);
            ans += w[i].c;    
        }
        
    }
    cout << ans << endl;
    return 0;
}
