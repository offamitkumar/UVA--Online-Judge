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
vector<vector<int>>g;
vector<int>mh,v;
int n; 
int dfs(int s){
    if(v[s])return 0;
    v[s]=true;
    for(auto&itr:g[s]){
        if(mh[itr]==-1 || dfs(mh[itr])){
            mh[itr]=s;
            return 1;
        }
    }
    return 0;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    vector<string>m(1000),s(1000);
    vector<char>sx(1000);
    vector<int>h(1000);
    while(t--){
         int male{};
         scanf("%d",&n);
         g.clear();
         mh.clear();
         v.clear();
         g.assign(n,vector<int>(0));
         for(int i{};i<n;++i){
             cin>>h[i]>>sx[i]>>m[i]>>s[i];
             male+=(sx[i]=='M');
         }
         int mi{};
         for(int i{};i<n;++i){
             if(sx[i]=='M'){
                 int fi{male};
                 for(int j{};j<n;++j){
                     if(sx[j]=='F'){
                         if(abs(h[i]-h[j])<=40 && m[i]==m[j] && s[i]!=s[j]){
                             g[mi].push_back(fi);
                         }
                         fi++;
                     }
                 }
                 mi++;
             }
         }
         int mf{};
         mh.assign(n,-1);
         for(int l{};l<male;++l){
             v.assign(n,0);
             mf+=dfs(l);
         }
         cout<<n-mf<<'\n';
    }
    return 0;
}
