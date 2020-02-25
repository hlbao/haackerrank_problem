#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool f[2010];
int n, k, T;
int v[2010];
int main() {
    cin >> T;
    while(T --){
        cin >>  n >> k;
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        f[0] = 1;
        for (int i = 1; i <=n; i++){
            // f[i][0] = 1;
            for (int j = v[i]; j <= k; j++)
                f[j] |= f[j - v[i]] ;
        }
        for (int i = k; 1; i--){
            if (f[i]){
                cout << i << endl;
                break;
            }
        }
        memset(f,0,sizeof(f));
    }
    return 0;
}
