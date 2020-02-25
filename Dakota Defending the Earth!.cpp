#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <time.h>
using namespace std;
const static int inf = 0x3f3f3f3f;
const static int maxnode = 200010;
const static int maxn = 1501;
const static int maxm = 1501;
int n, m, size;
int row[maxnode], col[maxnode];
int U[maxnode], D[maxnode], L[maxnode], R[maxnode];
int H[maxn], S[maxm];
int ansd;
bool vis[maxm];
int sk[maxn], ans[maxn];
int ct;
clock_t start;
struct DLX {
    inline void init(int _n, int _m)
    {
        n = _n, m = _m, size = _m;
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
    inline bool dance(int d)
    {
        if(d + h() >= ansd) return 0;
        if(R[0] == 0){
            ansd = d;
            for (int i = 0; i < ansd; i ++) ans[i] = sk[i];            
            return 1;
        } 
        clock_t now = clock();
        if ((float(now) - float(start)) / CLOCKS_PER_SEC > 1.8){
            // cout << float(now) - float(start) << endl;
            // cout << now <<" "<< start << " " <<CLOCKS_PER_SEC<< endl;
            return 0;
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
            sk[d] = row[i];
            dance(d+1);
            for(int j = L[i]; j != i; j = L[j])
                resume(j);
            resume(i);     
        } 
        return 0;
    }
} dlx;

vector<int> e[1010];
int w, c;
void gao(){
    int all = 0;
    while (all < m){
        int max = 0, cs = 0;
        for (int i = 1; i <= n; i ++)
        {
            int cnt = 0;            
            for (int j = 0; j < e[i].size(); j ++)
                cnt += !vis[e[i][j]];            

            if (cnt > max){
                max = cnt;
                cs = i;
            }
            // cout << max <<" "<< cs << endl;
        }
        // cout << cs <<" "<< e[cs].size() << endl;
        // cout << max <<" "<< cs << endl;
        // puts("!!");
        ans[++ansd] = cs;        
        for (int j = 0; j < e[cs].size(); j ++){
            if (vis[e[cs][j]] == false){
                vis[e[cs][j]] = 1;
                all ++;
            }
        }        
    }
}
int main() {
    start = clock();
    cin >> n >> m;
    dlx.init(n, m);
    for(int r= 1; r <= n; r++){
        cin >> w;
        for (int j =1; j <= w; j++){
            cin >> c;
            e[r].push_back(c + 1);
            dlx.Link(r, c + 1);
        }
    }    

    gao();
    memset(vis,0,sizeof(vis));
    dlx.dance(0);
    cout << ansd << endl;
    for (int i =1 ; i<= ansd; i++) cout << ans[i] - 1 <<" "; cout << endl;

    return 0;
}
