#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void lcs(vector<string>&a , vector<string>&b){
    int n = a.size(); 
    int m = b.size();
    vector<vector<int>>dp(n+1 , vector<int>(m+1)); 
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    int x= n; 
    int y = m; 
    stack<string>s;
    while(x>=1 && y>=1 ){
        if(a[x-1] == b[y-1]){
            s.push(a[x-1]);
            x--;
            y--;
        }else if(dp[x-1][y] > dp[x][y-1]){
            x--;
        }else{
            y--;
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
        if(s.size()){
            cout<<" ";
        }
    }
    cout << '\n'; 
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string s; 
    set<string>st;
    while(cin >> s){
        vector<string> a; 
        a.push_back(s);
        while(cin >> s && s != "#"){
            a.push_back(s);
        }
        vector<string>b; 
        while(cin >> s && s != "#"){
            b.push_back(s);
        }
        
        lcs(a,b);
    }
    return 0;
}
