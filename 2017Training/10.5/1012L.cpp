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

ll ans;
stack<int>st[3];

bool hanoi(int x,int y,int z,int n){
    if(n <= 0) return false;
    if(hanoi(x,z,y,n-1)) return true;
    //printf("Disk %d %c to %c\n", n,x+'A',y+'A');
    st[x].pop();
    st[y].push(n);
    ++ans;
    if(st[0].size() == st[1].size() && st[1].size() == st[2].size())
		return true;
    return hanoi(z,y,x,n-1);
}

int n=0;
void solve(){
    /*show me your code*/
    n += 3;
    ans = 0;
    for(int i = 0;i < 3;++i){
        while(!st[i].empty()) st[i].pop();
    }
    for(int i = 0;i < n;++i) st[0].push(n-i);
    hanoi(0,1,2,n);
    printf("%I64d\n",ans);
    for(int i = 0;i < 3;++i){
        printf("%c :",'A'+i);
        while(st[i].size()){
            printf("%d",st[i].top());st[i].pop();
        }
        puts("");
    }
    puts("**********************************");
}
int main(){
    int t = 9;//Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
