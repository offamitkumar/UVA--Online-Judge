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
#define MAXN (int)1e6+100
array<int, MAXN>arr;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    fill(arr.begin() , arr.end() , 0);
    for(int i=1;i*i<MAXN;++i){
        arr[i*i]++;
    }
    for(int i=1;i<MAXN;++i){
        arr[i] = arr[i]+arr[i-1];
    }
    int m,n;
    while(cin>>m>>n,m,n){
        cout<<arr[n]-arr[m-1]<<'\n';
    }
    return 0;
}
