#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
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
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;

}
multiset<int>st[10005];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        x = Read();
        y = Read();
        st[x].insert(y);
    }
    int m  = Read();
    int ans = n;
    for(int i=0;i<m;i++){
        int x,y,r;
        x = Read();
        y = Read();
        r = Read();
        for(int j=max(0,x-r);j<=min(10000,x+r);j++){
            int tmp = floor(sqrt(r*r-(x-j)*(x-j)));
            auto it = st[j].lower_bound(y-tmp);
        //    dbg(tmp);
            //cout << *it << endl;
            //dbg(i);
        //    cout << j << endl;
            //dbg(it);
            for(;it!=st[j].end()&&(*it)<=min(10000,(y+tmp));){
                //dbg(st[j].size());
                //dbg(*it);
                ans--;
                st[j].erase(it++);
            }
            //dbg(ans);
        }
    }
    cout << ans << endl;


}
