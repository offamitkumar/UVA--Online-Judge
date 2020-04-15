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
#define MAX_CONNECTION 15
array< array< long long , MAX_CONNECTION > , MAX_CONNECTION > dist;
array< array< long long , MAX_CONNECTION > , MAX_CONNECTION > parent;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int intersection;
    int case_counter{1};
    while(scanf("%d",&intersection) and intersection != 0){
        for(int i{0}; i < MAX_CONNECTION; ++i){
            for(int j{0}; j < MAX_CONNECTION; ++j){
                dist[i+1][j+1] = INT_MAX;
                parent[i+1][j+1] = i+1;
            }
        }
        for(int start{0}; start < intersection; ++start){
            int connections; scanf("%d",&connections);
            for(int j{0}; j < connections; ++j){
                int end , delay; scanf("%d%d",&end , &delay);
                dist[start+1][end] = delay;
            }
        }
        for(int mid{0}; mid < intersection; ++mid){
            for(int start{0}; start < intersection; ++start){
                for(int end{0}; end < intersection; ++end){
                    if(dist[start+1][end+1] > dist[start+1][mid+1] + dist[mid+1][end+1]){
                        dist[start+1][end+1] = dist[start+1][mid+1] + dist[mid+1][end+1];
                        parent[start+1][end+1] = parent[mid+1][end+1];
                    }
                }
            }
        }

        int intial_destination , final_destination; scanf("%d%d",&intial_destination ,&final_destination);

        int id = intial_destination , fd = final_destination;

        printf("Case %d: ", case_counter++);

        stack< int > path;
        path.push(final_destination);
        while(parent[intial_destination][final_destination] != intial_destination){
            final_destination = parent[intial_destination][final_destination];
            path.push(final_destination);
        }
        path.push(intial_destination);
        printf("Path = ");
        while(!path.empty()){
            printf("%d" , path.top());
            path.pop();
            if(path.size() >= 1){
                printf(" ");
            }else{
                printf("; ");
            }
        }
        printf("%lld second delay\n" , dist[id][fd]);
    }
    return 0;
}
