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
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
#define endl '\n'
using namespace std;
const int maxn = 1e5+5;
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

std::vector<int> G[maxn];
int len[maxn],cnt;
int vis[maxn];
pair<int,int> dfs(int u, int fa) {
    auto ret=make_pair(u,0);
    vis[u] = 1;
    for(int i=0; i<G[u].size(); ++i) {
        int v=G[u][i];
        if(v==fa) continue;
        auto tmp=dfs(v,u);
        ++tmp.second;
        if(tmp.second>ret.second) ret=tmp;
    }
    return ret;
}
int GLP(int s){
    auto ret=dfs(s,s);
    ret = dfs(ret.first, ret.first);
    int ans=ret.second;
    return ans;
}

int main(){
    int n,k;
    n = Read(),k=Read();
    rep(i,0,k){
        int u,v;
        u = Read(),v = Read();
        G[u].PB(v),G[v].PB(u);
    }
    int ans = 0;
    int tt = 0;
    for(int i = 0;i < n;i++){
        if(vis[i]) continue;
        int l = GLP(i);
        ans = max(l,ans);
        len[tt++] = l+1>>1;
    }
    sort(len,len+tt);
    if(tt>=2){
        ans = max(ans,len[tt-1]+len[tt-2]+1);
    }
    if(tt>=3&&len[tt-2]==len[tt-3]){
        ans = max(ans,len[tt-2]+len[tt-3]+2);
    }
    cout << ans << endl;
    return 0;
}
