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
const int maxn = 5e6+2333;
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
bool is_prime[maxn];
ll prime[348513+2333];
int num;
ll n;
void sieve(){
    num=0;
    int _n = maxn;
    for(int i=1;i<_n;i++) is_prime[i]=true; is_prime[0]=is_prime[1]=false;
    for(int i=2;i<_n;i++){ if(is_prime[i]){ prime[num++]=i; for(int j=2*i;j<=_n;j+=i) is_prime[j]=false; } }
}

void solve(){
    /*show me your code*/
    //printf("%d\n",num);
    std::vector<ll>v;
    for(int i = 0;i < num && prime[i]*prime[i] <= n;++i){
        while(n%prime[i] == 0){
            n /= prime[i];v.PB(prime[i]);
        }
    }
    if(n != 1){
        v.PB(n);
    }
    if(v.size() == 3 && v[0] != v[1] && v[1] != v[2]) puts("YES");
    else puts("NO");
}
int main(){
    FILEIN;
    FILEOUT;
    sieve();
    while(~scanf("%I64d",&n)) solve();
    return 0;
}
