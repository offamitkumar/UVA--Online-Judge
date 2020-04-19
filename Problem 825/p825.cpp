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
        long long ,
        null_type ,
        less<long long> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
long long w , n;
vector<vector<long long>>graph , dp;
inline bool valid(long long x, long long y){
    return x>=1 && x<=n && y>=1 && y<=w;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long t; scanf("%lld",&t);
    while(t--){
        cin>>n>>w;
        string s;
        graph.assign(n+1 , vector<long long>(w+1,1));
        dp.assign(n+1 , vector<long long>(w+1,0));
        cin.ignore();
        while(getline(cin , s) && !s.empty()){
            istringstream ss(s);
            long long u; ss >> u;
            long long v;
            while(ss >> v){
                graph[u][v] = 0;
            }
        }
        dp[n][w] = 1;
        for(long long i=n;i>=1;--i){
            for(long long j=w;j>=1;--j){
                if(graph[i][j]==0){
                    continue;
                }
                if(valid(i+1,j)){
                    dp[i][j] +=dp[i+1][j];
                }
                if(valid(i,j+1)){
                    dp[i][j] +=dp[i][j+1];
                }
            }
        }
        printf("%lld\n",dp[1][1]);
        if(t>0){
            puts("");
        }
    }
    return 0;
}
