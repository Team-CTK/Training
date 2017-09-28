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
char x[30];
int n;
int get(char s[],int x){
    int st;
    if(x==8) st = 0;
    else if(x==16)st = 1;
    else st = -1;

    int len = strlen(s);
    int tmp =1;
    int ans = 0;
    for(int i=len-1;i>st;--i){
        if(s[i]<='9')
        ans+=(s[i]-'0')*tmp;
        else ans+=(s[i]-'A'+10)*tmp;
        tmp*=x;
    }
    return ans;
}
void solve(){
    /*show me your code*/
    int tmp;
    if(x[0]=='0'){
        if(x[1]=='x'){
            tmp = get(x,16);
        }
        else tmp = get(x,8);
    }
    else tmp = get(x,10);
    string op;
    int res = 0;
    int x;
    for(int i=0;i<n;i++){
        cin >> op >> x;

        if(op=="++i"){
            if(x==tmp+1){
                res++;
            }
            tmp = x;
        }
        else if(op=="i++"){
            if(x==tmp){
                res++;
            }
            tmp = x+1;
        }
        else if(op=="--i"){
            if(x==tmp-1){
                res++;
            }
            tmp = x;
        }
        else if(op=="i--"){
            if(x==tmp){
                res++;
            }
            tmp = x-1;
        }
        else{
            if(x==tmp){
                res++;
            }
            tmp = x;
        }
    }
    cout << res << endl;
}
int main(){

    int t = 1;
    int ca = 1;
    while(cin >> x >> n){
        if(x[0]!='0'||n)
        solve();
        else break;
    }
    return 0;
}
