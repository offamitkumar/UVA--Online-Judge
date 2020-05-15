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
#define MAXN 1010
string s;
int n,palin[MAXN][MAXN] ,dp[MAXN];
int Palin(int start , int end){
    if(start>end){return 1;}
    if(palin[start][end]!=-1)return palin[start][end];
    palin[start][end] = 0;
    if(s[start] == s[end])palin[start][end] = Palin(start+1 , end-1);
    return palin[start][end];
}
int sol(int index){
    if(index >= n) return 0;
    if(dp[index]!=-1)return dp[index];
    dp[index] = INT_MAX;
    for(int i=index; i<n;++i){
        if(Palin(index , i)){
            dp[index] = min(dp[index] , sol(i+1)+1);
        }
    }
    return dp[index];
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        memset(dp , -1 , sizeof(dp));
        memset(palin , -1 , sizeof(palin));
        cin>>s;n = (int)s.size();
        cout<<sol(0)<<'\n';
    }
    return 0;
}
