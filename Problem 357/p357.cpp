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
#define MAXN 30010
long long dp[6][MAXN] = {0};
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    for(long long i=0;i<6;++i){
        dp[i][0] = 1;
    }
    long long arr[] = {0 ,1 , 5 , 10 , 25 , 50};
    for(auto i = 1; i<6; ++i){
        for(auto j = 1; j<MAXN; ++j){
            dp[i][j] = dp[i-1][j];
            if(j - arr[i] >= 0){
                dp[i][j] += dp[i][j-arr[i]];
            }
        }
    }
//    for(auto i=0;i<=5;++i){
//        for(long long j=0;j<20;++j){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
    long long nu;
    while(cin>>nu){
        if(dp[5][nu]==1){
            printf("There is only 1 way to produce %lld cents change.\n",nu);
        }else{
            printf("There are %lld ways to produce %lld cents change.\n",dp[5][nu] , nu);
        }
    }
    return 0;
}
