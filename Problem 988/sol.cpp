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
vector< vector< long long > >graph;
vector< long long > dist , ind;
vector< bool > visited;
void top_sort(int start){
    queue< long long >q;
    q.push(start);
    while(!q.empty()){
        long long current_node = q.front();
        q.pop();
        for(auto&itr:graph[current_node]){
            dist[itr] += dist[current_node];
            ind[itr]--;
            if(ind[itr]==0){
                visited.at(itr) = true;
                q.push(itr);
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
    long long n;
    bool more_=false;
    while(cin >> n){
        graph.clear();
        visited.clear();
        dist.clear();
        ind.clear();
        if(more_){
            puts("");
        }
        more_ = true;
        graph.assign(n , vector< long long > (0));
        dist.assign(n , 0);
        visited.assign(n , false);
        ind.assign(n , 0);
        dist[0] = 1;
        for(long long u{}; u < n; ++u){
            long long x; cin >> x;
            long long v;
            for(long long j{}; j < x; ++j){
                cin >> v;
                graph.at(u).push_back(v);
                ind[v]++;
            }
        }
        for(int i=0; i< n; ++i){
            if(!visited[i]){
                top_sort(i);
            }
        }
        long long ans{};
        for(long long i=0; i < n; ++i){
            if(graph.at(i).size()==0){
                ans += dist[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
