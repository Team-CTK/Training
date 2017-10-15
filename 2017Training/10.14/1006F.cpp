#include<bits/stdc++.h>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)

#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
#define eps 1e-12
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
typedef long double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
const long double PI  = acos(-1.0);
const long double R = 6371.0;
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Point{
    db x, y, z;
};
struct Pos{
    db lat, longt;
    Pos(double a=0, double b=0) {
        lat = a*PI/180;
        longt = b*PI/180;
    }
    Point getPoint() {
        Point ret;
        ret.z=sin(lat);
        db r=cos(lat);
        ret.x=r*cos(longt);
        ret.y=r*sin(longt);
        return ret;
    }
}P[2];
db getRad(Point p, Point q) {
    db cr = (p.x*q.x+p.y*q.y+p.z*q.z);
    return acos(cr);
}

double mindis(Pos P, Pos Q) {
    Point u =  P.getPoint();
    Point v =  Q.getPoint();
    db rad = getRad(u,v);
    return double(rad*R);
}
double bugdis(Pos P, Pos Q) {
    db ret = fabs(Q.lat-P.lat)*R;
    db dlongt = fabs(Q.longt-P.longt);
    dlongt = min(dlongt, 2*PI-dlongt);
    ret += R*cos(P.lat)*dlongt;
    return (double)ret;
}
void solve() {
    double a0, b0, a1, b1;
    cin >>a0 >> b0 >> a1>> b1;
    P[0] = Pos(a0, b0);
    P[1] = Pos(a1, b1);
    printf("%.8f %.8f\n", mindis(P[0],P[1]),bugdis(P[0], P[1]));
}
int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
