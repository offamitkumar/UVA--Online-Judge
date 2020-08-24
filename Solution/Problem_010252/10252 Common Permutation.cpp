#include <bits/stdc++.h>
using namespace std;
#define int int64_t
string lcs(string &a, string&b){
    int n = (int)a.size(); 
    int m = (int)b.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m;++j){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    string res;
    int i=n; 
    int j=m;
    while(i>=1 && j>=1){
        if(a[i-1] == b[j-1]){
            res+=a[i-1];
            i--;
            j--;
        }else if(dp[i][j-1] > dp[i-1][j]){
            --j;
        }else{
            --i;
        }
    }
    sort(res.begin(),res.end());
    return res;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string a, b; 
    while(getline(cin,a) && getline(cin,b)){
        sort(a.begin(), a.end()); 
        sort(b.begin(), b.end());
        cout << lcs(a,b) << '\n'; 
    }
    return 0;
}
