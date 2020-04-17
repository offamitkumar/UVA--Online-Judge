/*
 *
 *
 *   there can be more then one weight for a pair of vertex
 *
 *
 *
 *
 */
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
#define MAXN 103
int capacity[MAXN][MAXN];
array< int , MAXN > parent;
bitset<MAXN>visited;
bool BFS(int source , int sink){
    fill(parent.begin() , parent.end() , -1);
    visited.reset();
    queue< int > q;
    q.push(source);
    visited.set(source);
    bool is_path_found = false;
    while(!q.empty() && is_path_found == false){
        int current_node = q.front();
        q.pop();
        for(int i=0; i < MAXN ; ++i){
            if(capacity[current_node][i] > 0 && !visited[i]){
                q.push(i);
                visited.set(i);
                parent[i] = current_node;
                if(i == sink){
                    is_path_found = true;
                    return true;
                }
            }
        }
    }
    return is_path_found;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    int network_counter{1};
    while(scanf("%d",&n) && n != 0){
        int max_flow{};
        memset(capacity , 0 , sizeof(capacity));
        int s , t , c; scanf("%d%d%d", &s , &t , &c);  
        for(int i{}; i < c; ++i ){
            int u , v , c; scanf("%d%d%d", &u , &v , &c);
                capacity[u][v] += c; // there can be more than one vertex for each pair of vertex
                capacity[v][u] += c;
        }
        while(BFS(s , t)){
            int flow{INT_MAX};
            int v = t;
            while(v != s){
                int u = parent[v];
                if(flow > capacity[u][v]){
                    flow = capacity[u][v];
                }
                v = u;
            }
            v = t;


            while(v != s){
                int u = parent[v];
                capacity[u][v] -= flow;
                capacity[v][u] += flow;
                v = u;
            }
            max_flow += flow;
        }
        printf("Network %d\n",network_counter++);
        printf("The bandwidth is %d.\n",max_flow);
        puts("");
    }
    return 0;
}
