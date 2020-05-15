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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
         long long n ,max_answer{INT_MIN}, k; cin>>n>>k;
         n= pow(10 , n);
         k/=(n/10);
         int i = 10000;
         while(i--){
             k*=k;
             if(k>=n){
                 k/=(n/10);
             }
             max_answer = max(max_answer , k);
             if(max_answer == n-1ll){
                 break;
             }
         }
         cout<<max_answer<<'\n';
    }
    return 0;
}
