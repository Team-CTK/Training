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
const int maxn = 1e4+5;
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
int n,m,k;
map<string,int>mp;
map<int,string>nm;
int cnt;
std::vector<string> v;
int vis[maxn];
int vis1[maxn];
std::vector<int> G[maxn];
set<string>ans;
void dfs(int x){
    vis[x] = 1;
    //cout << nm[x] <<endl;
    if(vis1[x]) ans.insert(nm[x]);
    for(int i=0;i<G[x].size();i++){
        int v = G[x][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}
void init(){
    ans.clear();
    nm.clear();
    mp.clear();
    v.clear();
    CLR(vis);
    CLR(vis1);
    cnt = 0;
}
void solve(){
    /*show me your code*/

    init();
    n = Read();
    m = Read();
    k = Read();

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        v.PB(s);
        if(!mp[s]) {
            mp[s]=++cnt;
            nm[cnt] = s;
        }
    }
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        if(!mp[s]) {
            mp[s] = ++cnt;
            nm[cnt] = s;
        }

        vis1[mp[s]] = 1;
    }
    for(int i=0;i<k;i++){
        string s1,s2;
        cin >> s1 >> s2;
        if(!mp[s1]) {
            mp[s1] = ++cnt;
            nm[cnt] = s1;
        }
        if(!mp[s2]) {
            mp[s2] = ++cnt;
            nm[cnt] = s2;
        }
        int x = mp[s1];
        int y = mp[s2];
        G[x].PB(y);
    }
    for(int i=0;i<v.size();i++){
        int x = mp[v[i]];
        if(!vis[x]){
            dfs(x);
        }
    }
    for(auto it=ans.begin();it!=ans.end();it++){
        if(it==ans.begin())
        cout << *it;
        else cout << " " << *it;
    }
    cout << endl;
    for(int i=1;i<=cnt;i++) G[i].clear();
}
int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
