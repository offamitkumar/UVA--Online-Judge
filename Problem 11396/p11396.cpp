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
vector<vector<int>>graph;
vector<int>color; // 1 , 2
vector<bool>visited; 
bool is_bipartite (int current , int c){
    color[current] = (3-c);
    visited[current] = true;
    bool ok = true;
    for(auto&itr:graph[current]){
        if(itr==current){
            continue;
        }
        if(!visited[itr]){
             ok &= is_bipartite(itr , color[current]);
        }
        if(color[itr]==color[current]){
            ok = false;
        }
        if(!ok){break;}
    }
    return ok;
}

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    string s;
    while(true){
        int u,v;scanf("%d",&v);
        if(v==0){return 0;}
        graph.resize(v+10);
        for(int i=0;i<v+10;++i){
            graph[i].clear();
        }
        color.assign(v+10 , false);
        visited.assign(v+10 , false);
        while(scanf("%d%d",&u,&v) && u!=0 && v!=0){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(is_bipartite(1 , 2)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
