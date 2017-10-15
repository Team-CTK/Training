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
const int MAXM = 128;
vector<int> v[MAXM], ans;
priority_queue<int> pq;
int m, k;
void print(std::vector<int>& v) {
    for(int i=0; i<ans.size(); ++i) {
        printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
    }
}
void solve(){
    scanf("%d%d", &m, &k);
    for(int i=0; i<m; ++i) {
        int n; scanf("%d", &n);
        v[i].clear();
        for(int j=0; j<n; ++j) {
            int x; scanf("%d", &x);
            v[i].push_back(x);
        }
        sort(v[i].begin(), v[i].end());
        if(n>k) v[i].resize(k);
    }
    ans = v[0];
    for(int i=1; i<m; ++i) {
        while (!pq.empty()) {
            pq.pop();
        }
        for(auto u:ans)
            for(auto e:v[i])
                pq.push(-u-e);
        ans.clear();
        for(int i=0; i<k&&!pq.empty(); ++i) {
            ans.push_back(-pq.top());
            pq.pop();
        }
    }
    for(int i=0; i<k; ++i) {
        printf("%d%c", ans[i], " \n"[i==k-1]);
    }
}
int main(){
    int t; scanf("%d", &t);
    int ca = 1;
    while(t--) solve();
    return 0;
}
