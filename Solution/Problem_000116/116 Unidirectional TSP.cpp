#include <bits/stdc++.h>
using namespace std;
#define int int64_t
string Min(const string&s1 , const string&s2) {
    istringstream S1(s1) , S2(s2); 
    int x; 
    int y; 
    while(S1 >> x && S2 >> y) {
        if(x < y) {
            return s1;
        }else if(x > y) {
            return s2; 
        }
    }
    return s1;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n , m; 
    while(cin >> n >> m){
        vector<vector<int>>input(n , vector<int>(m));
        vector<vector<int>>cost(n+1 , vector<int>(m+1));
        vector<vector<string>>direction(n , vector<string>(m));
        for (int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cin >> input[i][j]; 
            }
        }
        for(int j=0; j<n; ++j){
            cost[j][0] = input[j][0];
            //direction[j][0] = to_string(j+1)+" ";
        }
        for(int i=1; i<m; ++i) {
            for(int j=0;j<n; ++j) {
                string add;
                //cost[j][i] = min({cost[j][i-1] , cost[(j-1+n)%n][i-1] , cost[(j+1)%n][i-1]}) + input[j][i];
                cost[j][i] = cost[j][i-1]; 
                add = direction[j][i-1]+to_string(j+1);
                if(cost[j][i] > cost[(j-1+n)%n][i-1]){
                    cost[j][i] = cost[(j-1+n)%n][i-1];
                    add = direction[(j-1+n)%n][i-1]+to_string(((j-1+n)%n)+1);
                }else if(cost[j][i] == cost[(j-1+n)%n][i-1]) {
                    add = Min(add ,direction[(j-1+n)%n][i-1]+to_string((j-1+n)%n+1));
                }
                if(cost[j][i] > cost[(j+1)%n][i-1]){
                    cost[j][i] = cost[(j+1)%n][i-1];
                    add = direction[((j+1)%n)][i-1]+to_string((j+1)%n+1);
                }else if(cost[j][i] == cost[(j+1)%n][i-1]) {
                    add = Min(add ,direction[((j+1)%n)][i-1]+to_string((j+1)%n+1));
                }
                cost[j][i]+=input[j][i];
                direction[j][i] += (add+" ");
            }
        }
        int ans{INT_MAX};
        string path;
        for(int i=0; i<n; ++i) {
            if(ans > cost[i][m-1]) {
                ans = cost[i][m-1];
                path = direction[i][m-1]+to_string(i+1);
            }else if(ans == cost[i][m-1]){
                path = Min(path , direction[i][m-1]+to_string(i+1));
            }
        }
        cout << path << '\n'; 
        cout << ans << '\n'; 
    }
    return 0;
}
