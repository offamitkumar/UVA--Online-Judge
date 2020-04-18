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
#define MAXN 101
array< vector< int > , MAXN > graph;
array< int , MAXN > in_degree , dist;
set<int> zero;
void top_sort(void){
    while(!zero.empty()){
        int current_node = *zero.begin();
        zero.erase(current_node);
        for(auto&itr:graph[current_node]){
            in_degree[itr]--;
            dist[itr] = max(dist[itr] , dist[current_node]+1);
            zero.insert(itr);
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    int case_counter{1};
    while(cin >> n && n != 0){
        fill(in_degree.begin() , in_degree.end() , 0);
        fill(dist.begin() , dist.end() , 0);
        for(int i{}; i < MAXN; ++i){
            graph.at(i).clear();
        }
        int start_point; cin >> start_point;
        zero.insert(start_point);
        int u , v;
        while(cin >> u >> v && u!= 0 && v != 0){
            graph.at(u).push_back(v);
            in_degree[v]++;
        }
        top_sort();
        int max_dist{} , point{start_point};
        for(int i=0; i < MAXN; ++i){
            if(max_dist < dist[i]){
                max_dist = dist[i];
                point = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.",case_counter++ , start_point , max_dist , point);
        puts("");
        puts("");
    }
    return 0;
}
