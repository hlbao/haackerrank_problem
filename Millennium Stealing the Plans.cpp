#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int mp[5010][5010];
int x[100010];
int n, m, T;
int main() {
    cin >> n >> m;
    for (int i =1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        // e[u].push_back(v);
        // e[v].push_back(u);
        // mp[u][v] = mp[v][u] = 1;
        mp[u][v] ++;
        mp[v][u] ++;
        // mp[u][v] = 1;
    }
    cin >> T;
    for (int i = 0; i < T; i++){
        for (int j = 0; j < n; j ++){
            cin >> x[j];
        }
        int ck = 1;
        for (int j = 0; j < n; j ++){
            ck &= mp[x[j]][x[(j + 1) % n]] > 0;
            mp[x[j]][x[(j + 1) % n]] --;
            mp[x[(j + 1) % n]][x[j]] --;
        }
        for (int j = 0; j < n; j ++){
            mp[x[j]][x[(j + 1) % n]] ++;
            mp[x[(j + 1) % n]][x[j]] ++;
            // ck &= mp[x[j]][x[(j + 1) % n]] > 0;
            // ck &= mp[x[j]][x[(j + 1) % n]];
        }
        puts(ck?"YES":"NO");
    }
    return 0;
}

