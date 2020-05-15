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
#define MAXN 3000
array< vector< int > , MAXN >graph;
array< vector< int > , MAXN >rev_graph;
map< string , int >name;
map< int , string >rev_name;
array< bool , MAXN >visited;
stack< int > stk;

void dfs1(int current){
    visited.at(current) = true;
    for(auto&itr:graph.at(current)){
        if(!visited.at(itr)){
            dfs1(itr);
        }
    }
    stk.push(current);
}

void dfs2(int current){
    visited.at(current) = true;
    cout<<rev_name[current];
    for(auto&itr:rev_graph.at(current)){
        if(!visited.at(itr)){
            printf(", ");
            dfs2(itr);
        }
    }
}

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n , m; 
    int c = 1;
    while(scanf("%d%d",&n,&m) && n!=0){
        if(c>1){
            puts("");
        }
        printf("Calling circles for data set %d:\n" , c++);
        int counter{0};
        string u , v;

        for(auto i{0}; i < MAXN; ++i){
            graph.at(i).clear();
            rev_graph.at(i).clear();
            visited.at(i) = false;
        }
        name.clear();
        rev_name.clear();


        for(int i{0}; i < m; ++i){
            cin >> u >> v;
            if(name.find(u)==name.end()){
                rev_name[counter] = u;
                name[u] = counter++;
            }
            if(name.find(v)==name.end()){
                rev_name[counter] = v;
                name[v] = counter++;
            }
            rev_graph.at(name[v]).push_back(name[u]);
            graph.at(name[u]).push_back(name[v]);
        }

        for(auto i{0}; i < counter; ++i){
            if(!visited.at(i)){
                dfs1(i);
            }
        }
        fill(visited.begin() , visited.end() , false);
        while(!stk.empty()){
            if(!visited.at(stk.top())){
                dfs2(stk.top());
                puts("");
            }
            stk.pop();
        }
    }
    return 0;
}
