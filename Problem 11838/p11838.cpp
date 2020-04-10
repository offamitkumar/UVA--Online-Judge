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
#define MAXN 2002
// container 
array< vector< int > , MAXN > graph; // graph
array< vector< int > , MAXN > rev_graph; // reverse graph 
stack< int > stk , stk2; // stack for storing dfs traversal 
array< bool , MAXN > visited;


void dfs(int current_node){
    visited.at(current_node) = true;
    for(auto& itr: graph[current_node]){
        if(!visited.at(itr)){
            dfs(itr);
        }
    }
    // after completely traversing the node we will push it into stack 
    stk.push(current_node);
}


void dfs2(int current_node){
    visited.at(current_node) = true;
    for(auto& itr: rev_graph[current_node]){
        if(!visited.at(itr)){
            dfs2(itr);
        }
    }
    stk2.push(current_node);
}


int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n , m; 
    while(scanf("%d%d",&n,&m) && n!=0 && m!=0){
        int u , v , w;


        // clear the containers
        for(int i{0}; i < MAXN; ++i){
            graph.at(i).clear();
            rev_graph.at(i).clear();
            visited.at(i) = false;
        }
        while(!stk.empty()){
            stk.pop();
        }

        while(!stk2.empty()){
            stk2.pop();
        }

        for(int i{0}; i < m; ++i){
            scanf("%d%d%d",&u,&v,&w);
            if(w==1){
                graph.at(u).push_back(v); 
                rev_graph.at(v).push_back(u); // reverse graph required while traversing back from stack
            }else{
                graph.at(u).push_back(v);
                graph.at(v).push_back(u);

                rev_graph.at(u).push_back(v);
                rev_graph.at(v).push_back(u);
            }
        }
        dfs(1);
        if(stk.size() != n){
            puts("0");
        }else{
            fill(visited.begin() , visited.end() , false);
            dfs2(stk.top());
            if(stk2.size() != n){
                puts("0");
            }else{
                puts("1");
            }
        }
    }
    return 0;
}
