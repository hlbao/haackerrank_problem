#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const static int inf = 0x3f3f3f3f;
const static int maxnode = 1000010;
const static int maxn = 1001;
const static int maxm = 1001;
int n, m, size;
int row[maxnode], col[maxnode];
int U[maxnode], D[maxnode], L[maxnode], R[maxnode];
int H[maxn], S[maxm];
int ansd;
bool vis[maxm];
int ans;
struct DLX {
    inline void init(int _n, int _m)
    {
        n = _n, m = _m, size = _m, ansd = inf;
        for(int i = 0; i <= m; ++i)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1, R[i] = i+1; 
        }
        L[0] = m, R[m] = 0;
        for(int i = 1; i <= n; ++i) H[i] = -1;
    } 
    inline void Link(int r, int c)
    {
        ++S[col[++size] = c];
        row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0) H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    inline void remove(int c)
    {
        for(int i = D[c]; i != c; i = D[i])
        L[R[i]] = L[i], R[L[i]] = R[i];
    }
    inline void resume(int c)
    {
        for(int i = U[c]; i != c; i = U[i])
        L[R[i]] = R[L[i]] = i;
    }
    inline int h()
    {
        int ret = 0;
        memset(vis, 0, sizeof vis);
        for(int i = R[0]; i; i = R[i])
        {
            if(vis[i]) continue;
            ++ret; vis[i] = true;
            for(int j = D[i]; j != i; j = D[j])
                for(int k = R[j]; k != j; k = R[k])
                    vis[col[k]] = true;
        }
        return ret;
    }
    inline bool dance(int d, int lim)
    {
        if(d > lim) return 0;
        if(R[0] == 0)
        {
            // if(d < ansd) ansd = d;
            return 1;
        } 
        int c = R[0];
        for(int i = R[0]; i; i = R[i])
            if(S[i] < S[c])
                c = i;
        for(int i = D[c]; i != c; i = D[i])
        {
            remove(i);
            for(int j = R[i]; j != i; j = R[j])
                remove(j);
            if (dance(d+1, lim)) return 1;
            for(int j = L[i]; j != i; j = L[j])
                resume(j);
            resume(i);     
        } 
        return 0;
    }
} dlx;

int  w, c;
int main() {
    cin >> n >> m;
    dlx.init(n, m);
    for(int r= 1; r <= n; r++){
        cin >> w;
        for (int j =1; j <= w; j++){
            cin >> c;
            c ++;
            dlx.Link(r, c);
        }
    }
    for (int i=1; i<= n; i++){
        if (dlx.dance(0, i)){
            cout << i << endl;
            break;
        }
    }
    return 0;
}

