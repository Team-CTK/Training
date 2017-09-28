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
bool is_prime[maxn*10];
int pid[maxn*10];
int prime1[maxn*10];
int num;
int vis[maxn];
std::vector<int> G[maxn];
void sieve(){
    num=0;
    int n = 1000000;
    for(int i=0;i<=n;i++) pid[i]= i;
    for(int i=1;i<=n;i++) is_prime[i]=true; is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){ if(is_prime[i]){prime1[i]=num++; for(int j=2*i;j<=n;j+=i) {is_prime[j]=false; pid[j] = i;}} } }
void init(){
    for(int i=0;i<maxn;i++){
        G[i].clear();
    }
    CLR(vis);
}
void dfs(int x){
    vis[x] = 1;
    for(int i=0;i<G[x].size();i++){
        if(!vis[G[x][i]]) dfs(G[x][i]);
    }
}
void solve(){
    init();
    int n = Read();
    for(int i=num;i<num+n;i++){
        int x = Read();
        int  tmp = x;
        while(tmp>1){
            int cnt = pid[tmp];
            while(!(tmp%cnt)){
                tmp/=cnt;
            }
            G[prime1[cnt]].PB(i);
            G[i].PB(prime1[cnt]);
        }
    }
    int ans = 0;
    for(int i=num;i<num+n;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
}
int main(){
    sieve();
    int t = Read();
    int ca = 1;
    while(t--) {
        printf("Case %d: ",ca++);
        solve();

    }
    return 0;
}
