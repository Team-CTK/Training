#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
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
#define _ixvii0iv
using namespace std;
const int maxn = 1e5+1e3+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 +7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
//ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;

}
ll inv[maxn];
void init() {
    inv[1]=1;
    for(int i=2; i<maxn; ++i) {
        inv[i]=-(mod/i)*inv[mod%i]%mod+mod;
    }
}
struct Edge{
    int to, next;
}e[maxn];
int head[maxn];
int pre[maxn], low[maxn], sccno[maxn], scc_cnt, dfs_clk;
int scc_size[maxn];
stack<int> S;
void dfs(int u) {
    pre[u]=low[u]=++dfs_clk;
    S.push(u);
    for(int p=head[u]; p; p=e[p].next) {
        int v=e[p].to;
        if(!pre[v]) {
            dfs(v);
            low[u]=min(low[u], low[v]);
        }
        else if(!sccno[v]) {
            low[u]=min(low[u], pre[v]);
        }
    }
    if(low[u]==pre[u]) {
        ++scc_cnt;
        while (true) {
            int v=S.top();S.pop();
            sccno[v]=scc_cnt;
            if(v==u) break;
        }
    }
}
ll pi[maxn], qi[maxn];
ll work(int n, int K) {
    ll Combo=1, total=0, ret=0;
    for(int i=0; i<K; ++i) {
        ll tmp= Combo*pi[i]%mod*qi[n-i]%mod;
        total = (total+tmp)%mod;
        ret += (ret+i*tmp)%mod;
        Combo = Combo*(n-i)%mod*inv[i+1]%mod;
    }
    ret = (ret+n*(1-total))%mod;
    if(ret<0) ret+=mod;
    return ret;
}
ll Expect(int n, int K) {
    dfs_clk=scc_cnt=0;
    CLR(pre);
    CLR(sccno);
    CLR(scc_size);
    while (!S.empty()) {
        S.pop();
    }
    for(int i=1; i<=n; ++i) {
        if(!pre[i]) dfs(i);
    }
    for(int i=1; i<=n; ++i) {
        ++scc_size[sccno[i]];
    }
    ll ret=0;
    for(int i=1; i<=scc_cnt; ++i) {
        ret += work(scc_size[i], K);
    }
    ret %= mod;
    if(ret<0) ret+=mod;
    return ret;
}
void solve() {
    int R, K, a, b;
    ll p, q;
    scanf("%d%d%d%d", &R, &K, &a, &b);
    p = a*inv[b]%mod;
    q = 1+mod-p;
    pi[0]=qi[0]=1;
    for(int i=1; i<maxn; ++i) {
        pi[i]=pi[i-1]*p%mod;
        qi[i]=qi[i-1]*q%mod;
    }
    for(int r=1; r<=R; ++r) {
        int n, m;
        scanf("%d%d", &n, &m);
        CLR(head);
        for(int i=1; i<=m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[i].to=v;
            e[i].next=head[u];
            head[u] = i;
        }
        printf("Region %d: %lld\n", r, Expect(n, K));
    }
}
int main(){
    int t, ca=0;
    scanf("%d", &t);
    init();
    while (t--) {
        printf("Case %d:\n", ++ca);
        solve();
    }
    return 0;
}
