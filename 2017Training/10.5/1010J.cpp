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
#define FILEIN freopen("input.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
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
const int maxn = 1e2+5;
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

int n,m;
string s[maxn];
string t[maxn];
struct node{
    string tp;
    string a,b;
};
int a[105][2];
int mp[205];
int b[105][2];
int vis[205];
std::vector<int> G[405];
std::vector<node> at,ta;
int dfs(int x){
    for(int i=0;i<G[x].size();i++){
        if(!vis[G[x][i]]){
            vis[G[x][i]] = 1;
            if(mp[G[x][i]]==-1||dfs(mp[G[x][i]])){
                mp[G[x][i]] = x;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<m;i++) cin >> t[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) a[i][0] +=s[i][j]-'0';
        for(int j=3;j<6;j++) a[i][1] +=s[i][j]-'0';
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++) b[i][0] +=t[i][j]-'0';
        for(int j=3;j<6;j++) b[i][1] +=t[i][j]-'0';
    }
    MEM(mp,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][0]==b[j][1]||a[i][1]==b[j][0])
            {
                G[i].PB(j+100);
                G[j+100].PB(i);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        CLR(vis);
        if(dfs(i)) ans++;
    }
    cout << ans << endl;
    for(int i=100;i<m+100;i++){
        if(~mp[i]){
            //dbg(a[mp[i]][0]);
            //dbg(b[i-100][1]);
            if(b[i-100][1]==a[mp[i]][0]){

                cout << "AT " << s[mp[i]] << " " << t[i-100] << endl;
            }
            else
            {
                //cout << a[mp[i]][0] << " " << b[i-100][1] << endl;
                cout << "TA "<< t[i-100] <<" " << s[mp[i]] << endl;

            }
        }
    }
}
int main(){
    FILEIN;
    FILEOUT;
    int t = 1;
    int ca = 1;
    while(scanf("%d %d",&n,&m)!=EOF) solve();
    return 0;
}
