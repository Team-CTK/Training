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
const int maxn = 400;
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
struct Point{
    int x, y;
    Point(int xx=0, int yy=0)
        :x(xx), y(yy){}
}P[maxn];
bool cmpy(const Point& a, const Point& b) {
    return a.y<b.y;
}
int n, ans;
multiset<int> st;
int a[maxn], sz;
void update(int h) {
    if(st.size()<(n+1)/2) return;
    int w=20000;
    sz = 0;
    for(auto e:st) {
        a[sz++] = e;
    }
    for(int i=0; i+(n+1)/2-1<sz; ++i) {
        int j=i+(n+1)/2-1;
        w = min(w,a[j]-a[i]);
    }
    ans = min(ans, w*h);
}
void solve(){
    ans = (int)4e8;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%d%d", &P[i].x, &P[i].y);
    }
    sort(P, P+n, cmpy);
    for(int i=0; i<n; ++i) {
        if(i&&P[i].y==P[i-1].y)
            continue;
        st.clear();
        for(int j=i; j<n; ) {
            int k=j+1;
            while(k<n&&P[k].y==P[k-1].y) ++k;
            for(int it=j; it<k; ++it) {
                st.insert(P[it].x);
            }
            update(P[j].y-P[i].y);
            j=k;
        }
    }
    printf("%d\n", ans);
}
int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
