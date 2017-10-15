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
#define sqr(x) x
#define endl '\n'
using namespace std;
const int maxn = 2e5+5;
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
int idx;
struct node{
    int f[3];
    int id;
    bool operator <(const node &a)const{
        return f[idx]<a.f[idx];
    }
}data[maxn],kd[maxn<<2];
int flag[maxn<<2];
pair<ll,node>res;
inline void build(int l,int r,int rt,int dept){
    if(l>r) return;
    flag[rt] = 1;
    flag[rt<<1] = flag[rt<<1|1] = -1;
    idx = dept%2;
    int mid = l+r>>1;
    nth_element(data+l,data+mid,data+r+1);
    kd[rt] = data[mid];
    build(l,mid-1,rt<<1,dept+1);
    build(mid+1,r,rt<<1|1,dept+1);
}
inline ll dis(int rt,node p){
    return 1ll*sqr(1ll*p.f[0]-kd[rt].f[0])+1ll*sqr(1ll*p.f[1]-kd[rt].f[1]);
}
inline void query(node p,int rt ,int dept){
    if(flag[rt]==-1) return;
    pair<ll,node>cur;
    cur = {dis(rt,p),kd[rt]};
    int idm = dept%2;
    bool fg = false;
    int x = rt<<1;
    int y = rt<<1|1;
    if(p.f[idm]>=kd[rt].f[idm]) swap(x,y);
    if(~flag[x]){
        query(p,x,dept+1);
    }
    if(res.fi==-1){
        if(cur.se.f[2]<=p.f[2])res = cur;
        fg = true;
    }
    else{
        if(cur.se.f[2]<=p.f[2]&&(cur.fi<res.fi||(cur.fi==res.fi&&cur.se.id<res.se.id))){
            res = cur;
        }
        if(1ll*sqr(kd[rt].f[idm]-p.f[idm])<res.fi){
            fg = true;
        }
    }
    if(~flag[y]&&fg){
        query(p,y,dept+1);
    }

}
void solve(){
    int n,m;
    n = Read();
    m = Read();
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            data[i].f[j] = Read();
        }
        data[i].id = i;
    }
    build(0,n-1,1,0);
    for(int i=0;i<m;i++){
        node p;
        for(int j=0;j<3;j++){
            p.f[j] = Read();
        }
        res.fi = -1;
        query(p,1,0);
        printf("%d %d %d\n",res.se.f[0],res.se.f[1],res.se.f[2]);
    }
}
int main(){
    //FILEIN;
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
