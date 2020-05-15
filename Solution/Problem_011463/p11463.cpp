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
array< array< long long , MAXN > , MAXN > dist; // distance 
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int Case; scanf("%d",&Case);
    for(int current_case{1}; current_case <= Case; ++current_case){

        printf("Case %d: ", current_case);
        int total_building , roads; scanf("%d%d",&total_building , &roads);

        for(int i{0}; i < MAXN; ++i){
            for(int j{0}; j < MAXN; ++j){
                dist[i][j] = INT_MAX ;
                dist[i][i] = 0;
                dist[j][j] = 0;
            }
        }

        for(int i{0}; i < roads; ++i){
            int start , end; scanf("%d%d",&start , &end);
            dist[start][end] = 1;
            dist[end][start] = 1;
        }

        int inital_destination ,final_destination; 
        scanf("%d%d",&inital_destination , &final_destination);

        for(int mid = {0}; mid < total_building; ++mid){
            for(int start{0}; start < total_building; ++start){
                for(int end{0}; end < total_building ; ++end){
                    dist[start][end] = min((long long)dist[start][end] , dist[start][mid] + dist[mid][end]);
                }
            }
        }

        int ans = INT_MIN ;

        for(int mid{0}; mid < total_building ; ++mid){
            if(dist[inital_destination][mid]==INT_MAX  or dist[mid][final_destination]==INT_MAX){
                continue;
            }
            ans = max((long long )ans , dist[inital_destination][mid]+dist[mid][final_destination]);
        }

        printf("%d\n",ans);

    }
    return 0;
}
