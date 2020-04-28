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
int dp[MAXN][MAXN];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    while(true){
        string a="",b="";
        getline(cin ,a);
        getline(cin,b);
        if(a.empty() && b.empty()){
            break;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=(int)a.size();++i){
            for(int j=1;j<=(int)b.size();++j){
                if(a[i-1]==b[j-1]){
                    dp[i][j] =dp[i-1][j-1]+1;
                }else{
                    dp[i][j] =max({ dp[i-1][j] , dp[i][j-1],dp[i-1][j-1] });
                }
            }
        }
        cout<<dp[a.size()][b.size()]<<'\n';
    }
    return 0;
}
