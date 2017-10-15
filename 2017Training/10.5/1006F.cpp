#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("input.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
#define endl '\n'
using namespace std;
const int maxn = 1023;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n, m;
int dis[maxn], rdis[maxn];
char tb[maxn][maxn];
void spfa(char c, int* dis) {
    static int q[maxn];
    static bool in[maxn];
    memset(dis, 0, sizeof(int)*maxn);
    memset(in, true, sizeof(in));
    int l=0, r=n;
    for(int i=0; i<n; ++i)
        q[i]=i+1;
    while (l!=r) {
        int u=q[l++];
        if(l==maxn) l=0;
        in[u]=false;
        for(int i=1; i<=n; ++i) {
            if(tb[u][i]==c) {
               if(dis[i]<dis[u]+1) {
                   dis[i]=dis[u]+1;
                   if(!in[i]) {
                       in[i]=true;
                       q[r++] = i;
                       if(r==maxn) r=0;
                   }
               }
            }
            else if(tb[u][i]=='=') {
                if(dis[i]<dis[u]) {
                    dis[i]=dis[u];
                    if(!in[i]) {
                        in[i]=true;
                        q[r++] = i;
                        if(r==maxn) r=0;
                    }
                }
            }
        }
    }
}
void solve(){
    scanf("%d%d", &n, &m);
    CLR(tb);
    while (m--) {
        int u, v, d;
        char op;
        scanf("%d%c%d", &u, &op, &v);
        if(op=='=') tb[u][v]=tb[v][u]=op;
        else {
            tb[u][v] = op;
            tb[v][u] = op^'<'^'>';
        }
    }
    spfa('<', dis);
    spfa('>', rdis);
    for(int i=1; i<=n; ++i) {
        char c;
        if(dis[i]+rdis[i]==2) {
            if(dis[i]==0) c='B';
            else if(dis[i]==1) c='R';
            else c='W';
        }
        else c='?';
        putchar(c);
    }
    puts("");
}
int main(){
    FILEIN;
    // FILEOUT;
    solve();
    return 0;
}
/*
int u, v;
char op;
scanf("%d%c%d", &u, &op, &v);
printf("dbg:%d %c %d\n", u, op, v);

u=getfa(u);v=getfa(v);
if(op=='=') {
    fa[u]=v;
    w[v] &= w[u];
}
else {
    if(op=='>') swap(u,v);
    w[u] &= 3;
    w[v] &= 6;
}
}
for(int i=1; i<=n; ++i) {
int v=w[getfa(i)];
dbg(v);
if((v&-v)==v) {
    if(v==1) putchar('B');
    else if(v==2) putchar('R');
    else putchar('W');
}
else putchar('?');
*/
