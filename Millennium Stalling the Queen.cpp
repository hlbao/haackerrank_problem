#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

#define ll long long
map<ll, int> x;
ll a[1010];
ll f[1010];
int n , T;
ll m;
int main() {
    cin >> T;
    while(T --){
        cin >>m >> n;
        ++n;
        memset(f,0,sizeof(f));
        for (int i = 2; i<=n ; i++) {
            cin >> a[i];
            a[i] = -a[i];
        }
        a[1] = -m;
        
        sort(a + 2, a + n + 1);
        // for (int i =1; i<=n; i++) cout << a[i] <<" "; cout << endl;
        ll ans = 0;
        f[1] = 0;
        for (int i =2 ; i <= n; i++){
            // cout <<i <<" "<< a[i] <<" "; 
            for (int j = 1; j < i; j ++)
                if (-a[1] % -a[j] == 0 && -a[j] % -a[i] == 0 && -a[j] > -a[i])
                    f[i] = max(f[i], f[j] + m / (-a[j]));
            // cout << f[i] <<" "; cout << endl;
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
