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
#include <unordered_map>
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
map<int,int>dp;
int pass(int i){
    if(dp.find(i)!=dp.end()){
        return dp[i];
    }
    int temp =i;
    int counter = 1;
    while(i!=1){
        ++counter;
        if(i&1){
            i = 3*i+1;
        }else{
            i = i/2;
        }
    }
    dp[temp] = counter;
    return counter;
}
int getAns(int left , int right){
    int max_ans= INT_MIN;
    for(int i=left;i<=right;++i){
        max_ans = max(max_ans , pass(i));
    }
    return max_ans;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int left , right;
    while(cin>>left>>right){
        cout<<left<<' '<<right<<' ';
        if(left>right){
            swap(left,right);
        }
        cout<<getAns(left , right)<<'\n';
    }
    return 0;
}
