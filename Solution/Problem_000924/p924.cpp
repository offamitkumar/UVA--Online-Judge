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
#define MAXN 2510
array< vector< int > , MAXN >graph;
array< bool , MAXN > visited;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int e; cin >> e;
    for(int i{0}; i < e; ++i){
        int no_of_friend; cin >> no_of_friend;
        for(int j{0}; j < no_of_friend; ++j){
            int x; cin >> x;
            graph.at(i).push_back(x);
        //    graph.at(x).push_back(i);
        }
    }
    int test_case; cin >> test_case; 
    while(test_case--){
        fill(visited.begin() , visited.end() , false);
        int source; cin >> source;
        queue< int > q;
        q.push(source); q.push(-1); // -1 is our tag for level 
        visited.at(source) = true;
        int max_boom{};
        int boom_counter{} , day_counter{};
        int day{};
        while(!q.empty()){
            int current_node = q.front(); q.pop();
            if(current_node==-1){
                continue;
            }
            for(auto&itr:graph[current_node]){
                if(!visited.at(itr)){
                    boom_counter++;
                    q.push(itr);
                    visited.at(itr) = true;
                }
            }
            if(q.front()==-1){
                day_counter++;
                if(boom_counter>max_boom){
                    day = day_counter;
                    max_boom = boom_counter;
                }
                boom_counter = 0;
                q.pop();
                if(!q.empty()){
                    q.push(-1);
                }
            }
        }
        if(max_boom == 0){
            cout << 0 << '\n' ;
        }else{
            cout << max_boom << " " << day << '\n' ;
        }
    }
    return 0;
}
