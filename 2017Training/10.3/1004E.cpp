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
multiset<int>st;
typedef pair<int,int>pr;
pair<int,int>p[maxn];
bool cmp(pr a,pr b){
    return a.fi<b.fi;
}
void solve(){
    int n,k;
    cin >>n >> k;
    for(int i=0;i<n;i++){
        p[i].fi = Read();
        p[i].se = Read();
    }
    sort(p,p+n,cmp);
    for(int i=0;i<k;i++){
        st.insert(p[i].se);
    }
    int ans = k;
    for(int i=k;i<n;i++){
        auto it = st.begin();
        if(p[i].fi>=*it){
            st.erase(it);
            st.insert(p[i].se);
            ans++;
        }
        else{
            auto it = st.end();
            it--;
            if(p[i].se<*it){
                st.erase(it);
                st.insert(p[i].se);
            }
        }
    }
    cout << ans << endl;
}
int main(){
    int t = 1;
    int ca = 1;
    while(t--) solve();
    return 0;
}
