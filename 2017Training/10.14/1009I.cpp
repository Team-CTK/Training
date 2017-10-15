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

int cnt[100];
int a[100];

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.fi != b.fi) return a.fi > b.fi;
    if(a.se == 7 || b.se == 7) return a.se == 7;
    return a.se < b.se;
}
void solve(){
    /*show me your code*/
    memset(cnt,0,sizeof(cnt));
    int n;n =Read();
    rep(j,0,n)
    rep(i,0,6){
        a[i] = Read();
        cnt[a[i]] ++;
    }
    std::vector<pair<int,int> > q;
    rep(i,0,50){
        q.PB(MP(cnt[i],i));
    }
    sort(q.begin(),q.end(),cmp);
    std::vector<int> v;
    rep(i,0,6){
        v.PB(q[i].se);
    }
    sort(v.begin(),v.end());
    rep(i,0,6){
        printf("%d%c",v[i]," \n"[i==5]);
    }
}
int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
