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
int A[11][11];
int cal(int* a) {
    int ret=0;
    for(int i=0; i<4; ++i)
        ret=A[ret][a[i]];
    return ret;
}
bool maybe(int x) {
    int a[5], b[5];
    for(int i=3; i>-1; --i) {
        a[i]=x%10;
        x/=10;
    }
    a[4]=cal(a);
    memcpy(b, a, sizeof(b));
    for(int i=0; i<5; ++i) {
        for(int j=1; j<10; ++j) {
            b[i]=(a[i]+j)%10;
            if(!A[cal(b)][b[4]]) return true;
        }
        b[i]=a[i];
    }
    for(int i=0; i<4; ++i) {
        if(b[i]==b[i+1]) continue;
        swap(b[i], b[i+1]);
        if(!A[cal(b)][b[4]]) return true;
        swap(b[i], b[i+1]);
    }
    return false;
}
void solve(){
    for(int i=0; i<10; ++i)
        for(int j=0; j<10; ++j)
            scanf("%d", A[i]+j);
    int ans=0;
    for(int i=0; i<10000; ++i) {
        if(maybe(i)) ++ans;
    }
    printf("%d\n", ans);
}
int main(){
    solve();
    return 0;
}
