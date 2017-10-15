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

const double pi = acos(-1.0);
struct point{
	double x,y;
	point(){}
	point(double _x,double _y){
		x = _x,y = _y;
	}
	point operator - (const point &b)const{
		return point(x-b.x,y-b.y);
	}
	double operator *(const point &b){
		return x*b.x + y*b.y;
	}
};

struct Line{
	point s,e;
	Line(){}
	Line(point _s,point _e){
		s = _s,e = _e;
	}
};

inline double dist(point a,point b){
	double res = sqrt((a-b)*(a-b));
	//dbg(a.x),dbg(a.y),dbg(b.x),dbg(b.y),dbg(res);
	return res;
}

inline point NearestPointTolLineSeg(point P,Line L){
	point res;
	double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	if(t >= 0 && t <= 1){
		res.x = L.s.x + (L.e.x-L.s.x)*t;
		res.y = L.s.y + (L.e.y-L.s.y)*t;
	}else{
		if(dist(P,L.s) < dist(P,L.e)) res = L.s;
		else res = L.e;
	}
	return res;
}

point p[100+7];
void solve(){
    /*show me your code*/
    int N,M,K;
	N = Read(),M = Read(),K=Read();
	for(int i = 0;i < N;++i){
		p[i].x = Read()*1.0,p[i].y = Read()*1.0;
	}
	if(M+K < N+2 || M+K > N+4 || M < 3||K < 3){
		puts("-1");
		return;
	}
	double ans = 10000000.0;
	if(M+K == N+2){
		for(int i = 0;i < N;++i){
			point t = p[(i+M-1+N)%N];
			ans = min(ans,dist(p[i],t));
		}
	}
	else if(M+K == N+3){
		for(int i = 0;i < N;++i){
			Line lin(p[(i+M-2+N)%N],p[(i+M-1+N)%N]);
			point np = NearestPointTolLineSeg(p[i],lin);
			ans = min(ans,dist(p[i],np));
		}
	}else if(M+K == N+4){
		if(M == 3 || N == 3) ans = 0;
		for(int i = 0;i < N;++i){
			Line lin(p[(i+M-2+N)%N],p[(i+M-1+N)%N]);
			point np = NearestPointTolLineSeg(p[i],lin);
			//printf("%d %d %d \n",i,(i+M-2+N)%N,(i+M-1+N)%N);
			//dbg(p[i].x),dbg(p[i].y),dbg(np.x),dbg(np.y);
			ans = min(ans,dist(p[i],np));
			np = NearestPointTolLineSeg(p[(i+1)%N],lin);
			ans = min(ans,dist(p[(i+1)%N],np));
		}
	}
	printf("%.3f\n",ans);
}

int main(){
	//FILEIN;
	//FILEOUT;
	solve();
    return 0;
}
