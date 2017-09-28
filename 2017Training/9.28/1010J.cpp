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
const int maxn = 1e5+1e3;
const int range = 1e5+7;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;

}
bool is_prime[maxn];
int prime[maxn/2];
int num;
void sieve(){
    num=0;
    int n = range;
    for(int i=1;i<=n;i++) is_prime[i]=true; is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){ if(is_prime[i]){ prime[num++]=i; for(int j=2*i;j<=n;j+=i) is_prime[j]=false; } }
}
ll p1cnt[maxn], p1sum[maxn], p2cnt[maxn],p2sum[maxn];
void init() {
    sieve();
    int n=range;
    for(int i=1; i<=n; ++i) {
        p1cnt[i]=p1cnt[i-1];
        p2cnt[i]=p2cnt[i-1];
        p1sum[i]=p1sum[i-1];
        p2sum[i]=p2sum[i-1];
        if(is_prime[i]) {
            ++p1cnt[i];
            p1sum[i]=(p1sum[i]+i)%mod;
            if(is_prime[i-2]) {
                ++p2cnt[i];
                p2sum[i]=(p2sum[i]+i)%mod;
            }
        }
    }
    /*puts("p1");
    for(int i=1; i<=10; ++i) {
        printf("%lld %lld\n", p1cnt[i], p1sum[i]);
    }
    puts("p2");
    for(int i=1; i<=10; ++i) {
        printf("%lld %lld\n", p2cnt[i], p2sum[i]);
    }*/
}
int main(){
    init();
    int t, ca=0; scanf("%d", &t);
    while(t--) {
        ll n, m;
        scanf("%I64d%I64d", &n, &m);
        ll ret=n, c1=m-1, c2=(m-1)*(m-2)/2%mod, c3=(m-1)*(m-2)/2*(m-3)/3%mod;
        ret += (p1cnt[n]*n%mod-p1sum[n])*c1%mod;
        //dbg(ret);
        if(c2) {
            ret += (p2cnt[n]*n%mod-p2sum[n])*2*c2%mod;
            //dbg(ret);
            if(n>=7&&c3) {
                ret += (n-7)*c3%mod;
            }
        }
        ret %=mod;
        if(ret<0) ret+=mod;
        printf("Case %d: %lld\n", ++ca, ret);
    }
    return 0;
}
