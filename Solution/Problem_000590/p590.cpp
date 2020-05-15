#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
vector<vector<vector<int>>>graph;
vector<vector<int>>dp;
int n , k; 
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int counter{1};
    while(cin>>n>>k && n!=0 && k!=0){
        graph.assign(n+1 , vector<vector<int>>(n+1));
        dp.assign(n+1 , vector<int>(k+1,INT_MAX));
        for(int u=1;u<=n;++u){
            for(int v=1;v<=n;++v){
                if(u==v)continue;
                int period; cin>>period;
                graph[u][v].resize(period+1);
                for(auto p{1};p<=period;++p){
                    cin>>graph[u][v][p];
                }
            }
        }
        for (int i = 0; i <= n; ++i)
        {
            for (int d = 0; d <= k; ++d)
                dp[i][d] = INT_MAX;
        }
        dp[1][0] = 0;

        dp[1][0]=0;

        for(int d=1;d<=k;++d){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    if(i!=j){
                        int q= (d-1)%((int)graph[j][i].size()-1)+1;
                        if(graph[j][i][q] && dp[j][d-1]!=INT_MAX){
                            dp[i][d] = min(dp[i][d] ,dp[j][d-1]+graph[j][i][q]);
                        }
                    }
                }
            }
        }

        printf("Scenario #%d\n",counter++);
        if(dp[n][k]==INT_MAX){
            cout<<"No flight possible."<<'\n';
        }else{
            printf("The best flight costs %d",dp[n][k]);
            
            puts(".");
        }
        puts("");
    }
    return 0;
}
