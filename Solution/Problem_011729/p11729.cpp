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
#define MAXN 1009
array<pair<int,int> , MAXN>arr;
bool compare(pair<int,int>p1 ,pair<int,int>p2){
    return p1.second > p2.second;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n;
    for(int c=1; cin>>n , n;++c){
        printf("Case %d: ",c);
        for(int i=0;i<n;++i){
            cin>>arr[i].first >> arr[i].second;
        }
        sort(arr.begin() , arr.begin()+n ,compare);
        int max_time{0};
        int current_time=0;
        for(auto i=0;i<n;++i){
            max_time = max(max_time , current_time+arr[i].first+arr[i].second);
            current_time += arr[i].first;
        }
        cout<<max_time<<'\n';
    }
    return 0;
}
