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
array< array< int , MAXN > , MAXN > grid; 
array< array< int , MAXN > , MAXN > dist; 
array< array< bool , MAXN > , MAXN > visited; 
array< int , 4> X{1 ,0 ,0,-1};
array< int , 4> Y{0 ,-1,1,0 };
int n , m ; 
void dijkstra(void){
    priority_queue< tuple< int , int , int > , vector< tuple< int , int , int > > , greater< tuple< int , int , int > > >pq; // min-heap
    visited[0][0] = true;
    dist[0][0] = grid[0][0];
    pq.push(make_tuple(dist[0][0] , 0 , 0)); // tuple = (distance , x_co-ordinate  , y_co-ordinate)


    // check is co-ordinate is valid or not 
    auto valid = [&](int a , int b){
        return (a>=0 && a<n && b>=0 && b<m);
    };

    while(!pq.empty()){
        int x , y; 
        tie( std::ignore , x , y ) = pq.top();
        if(x==n-1 && y==m-1){
            return; 
        }
        pq.pop();
        for(int i{0}; i < 4; ++i){
            if(valid(x+X.at(i) , y+Y[i]) && visited[x+X[i]][y+Y[i]] == false){
                visited[x+X[i]][y+Y[i]] = true;
                dist[x+X[i]][y+Y[i]] = dist[x][y]+grid[x+X[i]][y+Y[i]];
                pq.push(make_tuple(dist[x+X[i]][y+Y[i]] , x+X[i] , y+Y[i]));
            }
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n , &m);
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                dist[i][j] = INT_MAX;
                visited[i][j] = false;
            }
        }
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                scanf("%d",&grid[i][j]);
            }
        }
        dijkstra();
        cout << dist[n-1][m-1] << '\n' ;
    }
    return 0;
}
