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
        long long ,
        null_type ,
        less<long long> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define cube(x) ((x)*(x)*(x))
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long n; 
    long long set_counter{1};
    while(cin >> n) {
        vector< long long > busyness(n);
        for(auto&itr:busyness){
            scanf("%lld",&itr);
        }
        long long roads; scanf("%lld",&roads);
        vector< long long > start(roads) , end(roads) , cost(roads);
        for(long long i{0}; i < roads; ++i){
            scanf("%lld%lld",&start[i] , &end[i]);
            cost[i] = cube(busyness[end[i]-1] - busyness [ start[i]-1 ]);
        }
        vector< long long >dist(n+1 , INT_MAX);
        dist[1] = 0;
        for(long long i{0}; i < n - 1;  ++i){
            bool updating = false;
            for(long long j{0}; j < roads; ++j){
                long long source , destination , current_node_cost;
                tie(source , destination , current_node_cost) = make_tuple(start[j] , end[j] , cost[j]);
                if(dist[source] != INT_MAX and dist[destination] > dist[source] + current_node_cost){
                    updating = true;
                    dist[destination] = dist[source] + current_node_cost;
                }
            }
            if(!updating){
                break;
            }
        }
        // check for the negative cycle
        for(long long j{0}; j < roads; ++j){
            long long source , destination , current_node_cost;
            tie(source , destination , current_node_cost) = make_tuple(start[j] , end[j] , cost[j]);
            if(dist[source] != INT_MAX and dist[destination] > dist[source] + current_node_cost){
                dist[destination] = -INT_MAX;
            }
        }
        long long queries; scanf("%lld",&queries);
        printf("Set #%lld\n",set_counter++);
        while(queries--){
            long long destination; scanf("%lld",&destination);
            if(dist[destination] < 3 || dist[destination] == INT_MAX ){
                printf("?\n");
            }else{
                printf("%lld\n",dist[destination]);
            }
        }
    }
    return 0;
}
