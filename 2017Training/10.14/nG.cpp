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
const int maxn = 1e5+5;
typedef unsigned long long ll;
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
const int MAXN = 5e5+1e4;
ll q[MAXN], iq[MAXN];
int m, n;
ll Sum(int x, ll *a) {
    ll ret=0;
    while (x) {
        ret += a[x];
        x -= lowbit(x);
    }
    return ret;
}
void Add(int x, ll* a, ll v) {
    while(x<MAXN) {
        a[x] += v;
        x += lowbit(x);
    }
}
void XAdd(int x, ll v) {
    Add(x, q, v);
    Add(x, iq, x*v);
}
void solve(){
    scanf("%d%d", &m, &n);
    memset(q, 0, sizeof(q));
    memset(iq, 0, sizeof(iq));
    while(m--) {
        //dbg(m);
        char cmd[2];
        scanf("%s", cmd);
        if(*cmd=='Q') {
            int x; scanf("%d", &x);
            ll ans = (x+1)*Sum(x, q)-Sum(x, iq);
            cout << ans << endl;
        }
        else {
            char direct[2];
            int i, ss, aa, d, l, r;
            ll s, a;
            scanf("%s%d%d%d%d\n", direct, &i, &ss, &aa, &d);
            if(*direct=='E') {
                l=i, r=min(n, i+d-1);
                s=ss, a=aa;
            }
            else {
                r=i, l=max(1, i-d+1);
                s=ss+1ll*aa*(r-l);
                a=-aa;
            }
            XAdd(l, s);
            if(l<r) {
                XAdd(l+1, a-s);
                XAdd(r+1, -s-a*(r-l+1));
                XAdd(r+2, s+a*(r-l));
            }
            else {
                XAdd(l+1, -2*s);
                XAdd(l+2, s);
            }
        }
    }
}
int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
