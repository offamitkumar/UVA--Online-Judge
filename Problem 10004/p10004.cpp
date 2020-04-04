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
#define MAXN 202
array<vector<int>,MAXN>graph;
array<bool,MAXN>visited , current_color; // true = color 1 && false = color 0 :)
bool is_bipartite(int current_node , int color=0){
    visited[current_node] = true;
    current_color[current_node] = 1^color;
    bool ok  = true;
    for(auto&itr:graph[current_node]){
        if(!visited[itr]){
            ok &= is_bipartite(itr , current_color[current_node]);
        }
        if((!ok) or current_color[itr]==current_color[current_node]){
            return false;
        }
    }
    return ok;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    while(scanf("%d",&n) && n!=0){
        fill(current_color.begin() , current_color.end() , 0);
        fill(visited.begin() , visited.end() , 0);
        for(int i=0;i<MAXN;++i){
            graph[i].clear();
        }
        int edge; scanf("%d",&edge);
        for(int i=0;i<edge; ++i){
            int u , v; scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        puts(is_bipartite(0)?"BICOLORABLE.":"NOT BICOLORABLE.");
    }
    return 0;
}
