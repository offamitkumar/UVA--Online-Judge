#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int w, h, n; 
    while(cin >> w >> h >> n, n+w+h){
        vector<vector<bool>>dp(w, vector<bool>(h,true));
        for(int i=0,u1,v1,u2,v2; i<n;++i){
            cin >> u1 >> v1 >> u2 >> v2; 
            --u1, --u2 , --v1, --v2;
            if(u2 < u1){
                swap(u1,u2);
            }
            if(v2 < v1){
                swap(v1,v2);
            }
            for(int j=u1; j<=u2;++j){
                for(int k=v1; k<=v2; ++k){
                    dp[j][k] = false;
                }
            }
        }
        int counter{};
        for(int i=0; i<w; ++i){
            for(int j=0; j<h;++j){
                counter+=dp[i][j];
            }
        }
        if(counter == 0){
            cout <<"There is no empty spots.";
        }else if(counter == 1){
            cout <<"There is one empty spot.";
        }else{
            cout<<"There are "<< counter <<" empty spots.";
        }
        cout<<'\n';
    }
    return 0;
}
