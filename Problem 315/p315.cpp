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
#define MAXN 102
array<vector<int>,MAXN>graph;
array<int,MAXN>in , out;
array<bool,MAXN>visited;
int counter{};
int timer{};
void articulate(int current = 1 ,int parent=-1){
    visited[current] = true;
    bool is_articulatuation_point=false;
    int child_counter{};
    in[current] = out[current] = timer++;
    for(auto&itr:graph[current]){
        if(itr==parent){
            continue;
        }
        if(!visited[itr]){
            articulate(itr , current);
            child_counter++; // for root 
            if(in[current]<=out[itr]){
                is_articulatuation_point =true;
            }else{
                out[current] = min(out[current] , out[itr]);
            }
        }else{
            out[current] = min(out[current] , in_time[itr]);
        }
    }
    if(parent==-1){
        if(child_counter>=2){
            is_articulatuation_point = true;
        }else{
            is_articulatuation_point = false;
        }
    }
    counter+=is_articulatuation_point;
    return;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    while(true){
        int n;
        for(int i=0;i<MAXN;++i){
            graph[i].clear();
        }
        timer = 1;
        fill(in.begin() , in.end() , 0);
        fill(out.begin() , out.end() , 0);
        fill(visited.begin() , visited.end() , false);
        string buff;
        counter  = 0;
        cin>>n;
        if(n==0){break;}
        getline(cin,buff);
        while(true){
            getline(cin , buff);
            istringstream iss(buff);
            int u , v;
            iss>>u;
            if(u==0){
                break;
            }
            while(iss>>v){
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        articulate();
        printf("%d\n",counter);
    }
    return 0;
}
