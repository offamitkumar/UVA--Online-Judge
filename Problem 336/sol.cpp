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
#define MAXN 10000
//array< vector< int > , MAXN > graph;
map< long long , vector< long long> > graph;
map< long long , bool > visited;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    // input section 
    int NC; 
    int case_counter = 1;
    while(scanf("%d",&NC) && NC != 0){
        graph.clear();
        int temp = NC;
        cin.ignore();
        set<int>total_vertex;
        string s; 
        while(getline(cin , s) && !s.empty() && s!=" " ){
            istringstream ss(s);
            if(temp){
                int u , v;
                while(ss >> u && ss >> v && temp >= 0){
                    total_vertex.insert(u);
                    total_vertex.insert(v);
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                    visited[u] = false;
                    visited[v] = false;
                    temp--;
                }
                continue;
            }
            // query section 
            int current_node , TTL; 
            while(ss >> current_node && ss >> TTL && (current_node !=0 )){
                int ans = (int)total_vertex.size();
                bool first_time = true;
                if(first_time==true){
                    --ans;
                    if(graph.find(current_node)==graph.end()){
                        ++ans;
                    }
                }
                first_time = false;
                queue< int > q;
                for(auto&itr:visited){
                    itr.second = false;
                }
                q.push(current_node);
                q.push(-1);
                visited[current_node] = true;
                int tt = current_node;  // just for print at last
                int xx = TTL; // just for print at last
                while(!q.empty() && TTL){
                    current_node = q.front();
                    q.pop();
                    for(auto&itr:graph[current_node]){
                        if(!visited.at(itr)){
                            --ans;
                            visited.at(itr) = true;
                            q.push(itr);
                        }
                    }
                    if(q.front()==-1){
                        TTL--;
                        q.pop();
                        if(!q.empty()){
                            q.push(-1);
                        }
                    }
                }
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",case_counter++ , ans , tt , xx);
            }
        }
    }
    return 0;
}
