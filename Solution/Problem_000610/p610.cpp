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
#define MAXNODE 1001

array<vector<int> , MAXNODE>graph;
array<int , MAXNODE>dfs_min; // represent the minimum - reach time
array<int , MAXNODE>dfs_vis; // represent the visited time 
int timer = 1;

enum Current_Situation{TRAVERSING ,COMPLETED , NOT_VISITED};
Current_Situation visited[MAXNODE]; // this will tell us where the current Node stands 

void make_map(int current , int parent ){
    dfs_vis[current] = dfs_min[current] = timer++;
    visited[current] = TRAVERSING;
    for( auto neighbor : graph[current] ){
        
        if(neighbor == parent){
            continue; // don't traverse the parent node  , might create the infinite cycle
        }


        if( visited[neighbor] == NOT_VISITED){ // this is tree edge 
            printf("%d %d\n",current , neighbor);

            make_map(neighbor , current);

            if(dfs_vis[current]<dfs_min[neighbor]){
                // this is a bridge also 
                printf("%d %d\n", neighbor , current);
            }
            
        }else if( visited[neighbor] == TRAVERSING){ // this is back edge 

            printf("%d %d\n",current , neighbor);

        }

        dfs_min[current] = min(dfs_min[current] , dfs_min[neighbor]);
    }
    visited[current] = COMPLETED;
} 


int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int node  , edge;
    int counter{1};
    while(scanf("%d%d",&node , &edge) && node != 0 && edge != 0){
        // clean the graph; 
        for(int i=0;i<MAXNODE;++i){
            graph[i].clear();
            visited[i] = NOT_VISITED;
            dfs_vis[i] = -1;
            dfs_min[i] = -1;
        }
        timer = 1;

        // create the graph
        int u , v;
        for(int i=0;i<edge;++i){
            scanf("%d%d",&u , &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // check every node & if bridge print both [u , v] & [v , u] or just print [u , v]
        printf("%d\n\n",counter++);
        make_map(1 , -1); 
        puts("#");
        
    }
    return 0;
}
