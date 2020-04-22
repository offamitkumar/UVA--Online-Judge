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
#define MAXN 1003
int g[MAXN][MAXN]; // grid
set<int>E;
int dp[MAXN][MAXN];
bool v[MAXN]; // visited
int c , s , e, a,t;
int rec(int cc , int ti){ // cc->current city , ti -> time left / city left which we can travel 
    int i;
    int ans{INT_MIN };
    if(ti==0 && E.find(cc)==E.end()){
        return INT_MIN;
    }else if(ti==0){
        return 0;
    }
    if(E.find(cc)!=E.end()){
        ans=0;
    }
    if(dp[cc][ti]!=-1){
        return dp[cc][ti];
    }
    for(i=0;i<c;++i){
        if(i!=cc){
            int x = rec(i , ti-1) + g[cc][i];
            ans = max(ans , x);
        }
    }
    return dp[cc][ti]=ans;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    while(cin>>c>>s>>e>>t && (c!=0)){
        int i ,j;
        E.clear();
        memset(dp , -1 , sizeof(dp));
        for(i=0;i<c;++i){
            for(j=0;j<c;++j){
                cin>>g[i][j];
            }
        }
        for(i=0;i<e;++i){
            cin>>j;E.insert(j-1);
        }
        int x = rec(s-1,t);
        if(x==INT_MIN){
            cout<<0<<'\n';
        }else{
            cout<<x<<'\n';
        }
    }
    return 0;
}
