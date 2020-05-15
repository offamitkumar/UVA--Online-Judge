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
#define MAXN 1001
map< pair< int , int > , int >grid;
array< int , MAXN > dist;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
         grid.clear();
         for(auto i{0}; i < MAXN; ++i){
             dist[i] = INT_MAX;
         }
         int total_stars , total_wormhole; scanf("%d%d",&total_stars,&total_wormhole);
         for(int i{0}; i < total_wormhole; ++i){
             int start , end , t; scanf("%d%d%d",&start , &end , &t);
             grid[make_pair(start , end)] = t;
         }
         dist[0] = 0;
         for(int i{0}; i < total_stars - 1; ++i){
             for(auto&itr : grid){
                 if(dist[itr.first.first]+itr.second < dist[itr.first.second]){
                     dist[itr.first.second] = dist[itr.first.first] + itr.second;
                 }
             }
         }
         
         // let's check if vertices relaxed one more time or not 
         bool ok = true;
         for(auto&itr : grid){
             if(dist[itr.first.first]+itr.second < dist[itr.first.second]){
                 ok = false;
                 dist[itr.first.second] = dist[itr.first.first] + itr.second;
             }
         }
         if(!ok){
             puts("possible");
         }else{
             puts("not possible");
         }
    }
    return 0;
}
