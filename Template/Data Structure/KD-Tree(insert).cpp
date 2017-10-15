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
const int maxn = 1e6+5;
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
int n,m;
struct node {
    int d[2],ma[2],mn[2],l,r;
    bool operator<(const node &a)const {
        return d[idx]<a.d[idx];
    }
    int & operator[](int x) {return d[x];}
    node(int x = 0,int y = 0){
        l = 0, r= 0;
        d[0] = x;
        d[1] = y;
    }
    /* data */
}kd[maxn];

inline void push_up(int rt){
    int lson = kd[rt].l;
    int rson = kd[rt].r;
    if(lson){
        for(int i=0;i<2;i++){
            kd[rt].ma[i] = max(kd[rt].ma[i],kd[lson].ma[i]);
            kd[rt].mn[i] = min(kd[rt].mn[i],kd[lson].mn[i]);
        }
    }
    if(rson){
        for(int i=0;i<2;i++){
            kd[rt].ma[i] = max(kd[rt].ma[i],kd[rson].ma[i]);
            kd[rt].mn[i] = min(kd[rt].mn[i],kd[rson].mn[i]);
        }
    }
}
inline int build(int l,int r,int dept){
    idx = dept%2;
    int mid = l+r>>1;
    nth_element(kd+l,kd+mid,kd+r+1);
    for(int i=0;i<2;i++){
        kd[mid].mn[i] = kd[mid].ma[i] = kd[mid].d[i];
    }
    kd[mid].l = kd[mid].r = 0;
    if(l<mid) kd[mid].l = build(l,mid-1,dept+1);
    if(r>mid) kd[mid].r = build(mid+1,r,dept+1);
    push_up(mid);
    return mid;
}

inline int dis(int rt,node z){
    int cnt = 0;
    for(int i=0;i<2;i++){
        cnt+=abs(kd[rt].d[i]-z.d[i]);
    }
    return cnt;
}
inline int get(int rt,node z){
    int d1 = 0,d2 = 0;
    d1+=max(0,kd[rt].mn[0]-z.d[0]);
    d1+=max(0,z.d[0]-kd[rt].ma[0]);
    d2+=max(0,kd[rt].mn[1]-z.d[1]);
    d2+=max(0,z.d[1]-kd[rt].ma[1]);
    return d1+d2;
}

int ans;
inline void query(node p,int rt){
    int cnt = dis(rt,p);
    //dbg(rt);
    //dbg(cnt);
    ans = min(ans,cnt);
    int lson = kd[rt].l,rson = kd[rt].r;
    //dbg(lson);
    //dbg(rson);
    int dl = inf,dr = inf;
    if(lson) dl = get(lson,p);
    if(rson) dr = get(rson,p);
    if(dl<=dr){
        if(lson&&dl<ans) query(p,lson);
        if(rson&&dr<ans) query(p,rson);
    }
    else{
        if(rson&&dr<ans) query(p,rson);
        if(lson&&dl<ans) query(p,lson);
    }
}
void insert(node p,int rt,int dept){
    idx = dept%2;
    if(p.d[idx]>=kd[rt].d[idx]) {
        if(kd[rt].r) insert(p,kd[rt].r,dept+1);
        else{
            kd[rt].r = ++n;
            kd[n] = p;
            for(int i=0;i<2;++i) kd[n].mn[i] = kd[n].ma[i] = kd[n].d[i];
        }
    }
    else{
        if(kd[rt].l) insert(p,kd[rt].l,dept+1);
        else{
            kd[rt].l = ++n;
            kd[n] = p;
            for(int i=0;i<2;++i) kd[n].mn[i] = kd[n].ma[i] = kd[n].d[i];
        }
    }
    push_up(rt);
}
inline void solve(){
    /*show me your code*/
    n = Read();
    m = Read();
    for(int i=1;i<=n;i++){
        kd[i].d[0] = Read();
        kd[i].d[1] = Read();
    }
    int root;
    root = build(1,n,0);
    int op;
    node p;
    for(int i=0;i<m;i++){
        op = Read();
        int x,y; x = Read(); y = Read();
        p = node(x,y);
        if(op==1) insert(p,root,0);
        else{
            ans = inf;
            query(p,root);
            cout << ans << endl;
        }
    }
}
int main(){
    //FILEIN;
    int t = 1;
    int ca = 1;
    while(t--) solve();
    return 0;
}
