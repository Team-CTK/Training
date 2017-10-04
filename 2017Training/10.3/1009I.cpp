#include <bits/stdc++.h>
using namespace std;
#define CLR(x) memset(x, 0, sizeof(x))
const int maxn = 32;
const double eps=1e-9;
typedef long long ll;
typedef double db;

struct Light{
    int t, g, r, T;
    void read() {
        scanf("%d%d%d", &t, &g, &r);
        T=g+r;
    }
    db PeriodSt(db mt) {
        if(mt<=t-r) return t-T;
        if(mt<=t) return t;
        mt -= t;
        int M = int(mt/T+eps);
        db r = mt-M*T;
        if(r<g-eps) return M*T+t;
        else return (M+1)*T+t;
    }
}light[maxn];

struct Seg{
    db l, r;
    Seg(db ll=0, db rr=0) {
        l=ll, r=rr;
    }
};
struct Satis{
    Seg seg[maxn];
    int sz;
    void push(Seg v) {
        seg[sz++]=v;
    }
    void logv(db *tmp, int& tmpsz) {
        for(int i=0; i<sz; ++i) {
            tmp[tmpsz++] = seg[i].l;
            tmp[tmpsz++] = seg[i].r;
        }
    }
    void myfill(Seg* nseg, int* cnt, int nsz) {
        int j=0;
        for(int i=0; i<sz; ++i) {
            while(j<nsz&&nseg[j].l<seg[i].r-eps) {
                if(nseg[j].l>seg[i].l-eps) {
                    ++cnt[j];
                }
                ++j;
            }
        }
    }
    void myunique(double *tmp, int& sz) {
        int nsz=1;
        for(int i=1; i<sz; ++i) {
            if(tmp[i]>tmp[nsz-1]+eps) {
                tmp[nsz++]=tmp[i];
            }
        }
        sz=nsz;
    }
    void cross(Satis& b) {
        static db tmp[maxn*4];
        static Seg nseg[maxn];
        static int cnt[maxn];
        int tmpsz=0;

        logv(tmp, tmpsz);
        b.logv(tmp, tmpsz);
        sort(tmp, tmp+tmpsz);
        myunique(tmp, tmpsz);
        CLR(cnt);
        for(int i=0; i+1<tmpsz; ++i) {
            nseg[i]=Seg(tmp[i],tmp[i+1]);
        }
        int nsz=tmpsz-1;
        myfill(nseg, cnt, nsz);
        b.myfill(nseg, cnt, nsz);
        sz=0;
        for(int i=0; i<nsz; ++i)
            if(cnt[i]==2) push(nseg[i]);
    }
}x, y;
db dp[maxn];
int n;
int main(){
    scanf("%d", &n);
    for(int i=1; i<n; ++i)
        light[i].read();
    for(int i=1; i<=n; ++i)
        dp[i]=1e10;
    dp[0]=0;

    for(int i=0; i<n; ++i) {
        x.sz=0;
        x.push(Seg(0.0,2000.0));
        db st=0;
        if(i) {
            st=light[i].PeriodSt(dp[i]);
            if(st<dp[i]) st=dp[i];
        }

        for(int j=i+1; j<=n&&x.sz; ++j) {
            dp[j]=min(dp[j],st+x.seg[0].l+sqrt((j-i)*2000.0));
            //printf("%d, %.6f\n",j, dp[j]);
            if(j==n) break;
            y.sz=0;
            db thet = st+sqrt((j-i)*2000.0);
            db off=light[j].PeriodSt(thet)-thet;
            while (off<2000.0) {
                y.push(Seg(max(off, 0.0), off+light[j].g));
                off += light[j].T;
            }
            x.cross(y);
        }
    }
    printf("%.8f\n", dp[n]);
    return 0;
}
