#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp(8 , vector<int>(8));
bitset<10> row , d1 , d2;
int ans{};
void nQueen(int r , int n , int score){
    if(n == 8){
        ans = max(ans , score);
        return ;
    }
    for(int i=0;i<8; ++i){
        if(!row[i] && (!d1[i+r]) && (!d2[r-i+7])){
            row[i] = d1[i+r] = d2[r-i+7] = 1; 
            nQueen(r+1 , n+1 , score+dp[r][i]);
            row[i] = d1[i+r] = d2[r-i+7] = 0; 
        }
    }
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t;
    row.reset();
    d1.reset();
    d2.reset();
    while(t--){
        for(int i=0; i<8; ++i){
            for(int j=0; j<8; ++j){
                cin >> dp[i][j];
            }
        }
        ans = 0;
        nQueen(0 ,0 ,0);
        cout <<setw(5) << setfill(' ')<< ans << '\n'; 
    }
    return 0;
}
