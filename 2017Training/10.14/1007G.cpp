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
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
#define endl '\n'
using namespace std;
const int maxn = 5e5+5;
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
int m, n;
struct Node{
    ll sum, setv;
    bool flag;
}node[maxn*4];
void pushdown(int id, int l, int r, int m) {
    if(!node[id].flag) return;
    node[id<<1].flag=node[id<<1|1].flag=true;
    node[id<<1].setv=node[id<<1|1].setv=node[id].setv;
    node[id<<1].sum = (m-l+1)*node[id].setv;
    node[id<<1|1].sum = (r-m)*node[id].setv;
    node[id].flag=false;
}
ll Sum(int id, int l, int r, int al, int ar) {
    if(al<=l&&r<=ar) {
        return node[id].sum;
    }
    ll ret=0;
    if(l<r) {
        int m= l+r>>1;
        pushdown(id, l, r, m);
        if(max(l,al)<=min(m,ar))
            ret += Sum(id<<1, l, m, al, ar);
        if(max(m+1, al)<=min(r,ar))
            ret += Sum(id<<1|1, m+1, r, al, ar);
    }
    return ret;
}
void Set(int id, int l, int r, int al, int ar, int v) {
    if(al<=l&&r<=ar) {
        node[id].sum=(r-l+1)*v;
        node[id].flag=true;
        node[id].setv=v;
        return;
    }
    int m=l+r>>1;
    pushdown(id, l, r, m);
    if(max(l,al)<=min(m,ar))
        Set(id<<1, l, m, al, ar, v);
    if(max(m+1, al)<=min(r,ar))
        Set(id<<1|1, m+1, r, al, ar, v);
    node[id].sum = node[id<<1].sum+node[id<<1|1].sum;
}
void solve(){
    scanf("%d%d", &m, &n);
    memset(node, 0, sizeof(node));
    while(m--) {
        char cmd[2];
        scanf("%s", cmd);
        if(*cmd=='Q') {
            int x; scanf("%d", &x);
            printf("%lld\n", Sum(1, 0, n+1, 0, x));
        }
        else {
            char direct[2];
            int i, s, a, d, l, r;
            scanf("%s%d%d%d%d\n", direct, &i, &s, &a, &d);
            if(*direct=='E') {
                l=i, r=min(n, i+d-1);
            }
            else {
                r=i, l=max(1, i-d+1);
                s=s+a*(r-l);
                a=-a;
            }
            ll arr = Sum(1, 0, n+1, 0, r+1);
            ll dl = s+Sum(1,0,n+1, l, l);
            ll drr = arr-s-a*(r-l);
            Set(1,0,n+1, l,l, dl);
            if(l<r) Set(1,0,n+1, l+1, r, a);
            Set(1,0,n+1, r+1,r+1, drr);
        }
    }
}
int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
