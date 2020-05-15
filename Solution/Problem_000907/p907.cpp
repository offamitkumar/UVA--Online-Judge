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
#define MAXN 606
int n , k;
array<int , MAXN>arr , cs;
int dp[MAXN][MAXN];
/*
 * cs -> cumulative sum
 * cn -> current node
 * ni -> current night / day as your preference 
 * 
 */
int rec(int cn , int ni){
    if(ni==k){
        return cs[n+1]-cs[cn];
    }
    if(dp[cn][ni]!=-1){
        return dp[cn][ni];
    }
    int ans{INT_MAX},temp;
    for(int i=cn+1; i<=n+1;++i){
        temp = max(cs[i]-cs[cn], rec(i,ni+1));
        ans = min(ans , temp);
    }
    return dp[cn][ni] = ans;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int test_counter{1};
    while(cin >> n>>k){
        fill(cs.begin() , cs.end() , 0);
        fill(arr.begin() , arr.end() , 0);
        memset(dp , -1 , sizeof(dp));
        for(int i=1;i<=n+1;++i){
            cin>>arr[i];
            cs[i] += arr[i]+cs[i-1];
        }
        cerr<<test_counter<<'\n';
        test_counter++;
        if(k>=n){
            cout<<*max_element(arr.begin() , arr.end())<<'\n';
        }else{
            cout<<rec(0,0)<<'\n';
        }
    }
    return 0;
}
