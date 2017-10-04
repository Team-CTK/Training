#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+48;
bool dp[maxn][105], ans=true;

void solve(){
    memset(dp,false,sizeof(dp));
    int R,n;
    cin >> R >> n;
    for(int i=0;i<=R;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++){
        int r,l;
        cin >> l >> r;
        for(int j=0;j<=R;j++){
            if(j-(r-l)>=0) dp[j][i] |=dp[j-(r-l)][i-1];
            if(j+(r-l)<=R) dp[j][i] |=dp[j+(r-l)][i-1];
        }

    }
    bool fg = false;
    for(int j=0;j<=R;j++){
        fg|=dp[j][n];
    }
    ans &= fg;

}
int main(){
    int t; scanf("%d", &t);
    int ca = 1;
    while(t--) solve();

    if(ans) cout << "possible" << endl;
    else cout << "impossible" << endl;

    return 0;
}
