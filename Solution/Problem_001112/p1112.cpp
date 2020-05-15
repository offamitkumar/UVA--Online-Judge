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
#define  MAXN 103
array< vector< int >  , MAXN > graph;
array< array< int , MAXN >  , MAXN > dist;
array< bool , MAXN > visited;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){

        for(int i{0}; i < MAXN; ++i){
            fill(dist.at(i).begin() , dist.at(i).end() , 0);
            graph.at(i).clear();
        }
        fill(visited.begin() , visited.end() , false);

        int N , exit_cell , T , M; scanf("%d%d%d%d",&N , &exit_cell , &T , &M);
        while(M--){
            int u , v , w; scanf("%d%d%d",&u,&v,&w);
            graph.at(v).push_back(u); // create the reverse graph , 
            dist[v][u] = w; // we are going to start the traversing from end point 
        }

        auto dijkstra = [&](){
            int counter{1};
            priority_queue< pair< int , int > , vector< pair< int , int > > , greater< pair< int , int > > > pq;
            pq.push(make_pair(0 , exit_cell));
            visited.at(exit_cell) = true;
            while(!pq.empty()){
                int current_node , time_elapsed; 
                tie(time_elapsed, current_node) = pq.top();
                pq.pop(); 
                for(auto&itr:graph[current_node]){
                    if(!visited.at(itr) && T-(time_elapsed + dist[current_node][itr]) >= 0){
                        counter++;
                        pq.push(make_pair(time_elapsed + dist[current_node][itr] , itr));
                        visited.at(itr) = true;
                    }
                }
            }
            return counter;
        };
        cout << dijkstra() << '\n' ;
        if(t>0)
            cout<< '\n'; 
    }
    return 0;
}
