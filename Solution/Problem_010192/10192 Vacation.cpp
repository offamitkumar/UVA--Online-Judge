#include <bits/stdc++.h>
using namespace std;
#define int int64_t
string clean(string &a){
    string res; 
    for(auto&itr:a){
        if(isspace(itr)){
            continue;
        }
        res+=itr;
    }
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
    string a,b; 
    int case_counter = 1;
    while(getline(cin,a) && a != "#"){
        getline(cin,b);
//         a = clean(a); 
//         b = clean(b);
        int n = a.size(); 
        int m = b.size(); 
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m;++j){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        printf("Case #%ld: you can visit at most %ld cities.\n",case_counter++ , dp[n][m]);
    }
    return 0;
}
