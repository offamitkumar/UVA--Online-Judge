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
vector<int>ans; // final - answer storing vector
array<vector<int>, MAXN>graph; // adj-list graph
array<bool , MAXN>visited; 
array<int ,MAXN> ind; // this will maintain in-degree of each node
set<int>order; // will contain the node having in-degree 0 && IF WE HAVE CHOICE THEN WE HAVE TO DRINK THAT BEVERAGE WHICH APPEARED IN THE LIST FIRST.
void top_sort(void){
    while(!order.empty()){
        ans.push_back(*(order.begin()));
        int current_node =(*(order.begin()));
        visited[current_node] = true;
        order.erase(current_node);
        for(auto &itr: graph[current_node]){
            ind[itr]--;
            if(ind[itr]==0){
                order.insert(itr);
            }
        }
        graph[current_node].clear();
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    int x = 1;
    scanf("%d",&n);
    while(scanf("%d",&n)!=EOF){
        printf("Case #%d: Dilbert should drink beverages in this order: ",x++);
        for(int i=0;i<MAXN;++i){
            graph[i].clear();
        }
        ans.clear();
        fill(ind.begin() , ind.end() , 0);
        fill(visited.begin() , visited.end() , 0);
        map<string , int> s_i; // string to int
        map<int , string> i_s; // int to string
        // map & reverse - map
        string s , t;
        for(int i=0;i<n;++i){
            cin>>s;
            s_i[s] = i;
            i_s[i] = s;
        }
        int edge; scanf("%d",&edge);
        for(int i=0;i<edge;++i){
            cin>>s>>t;
            if(find(graph[s_i[s]].begin() , graph[s_i[s]].end() , s_i[t])!=graph[s_i[s]].end()){
                continue;
            }
            graph[s_i[s]].push_back(s_i[t]);
            ind[s_i[t]]++; // as t is more stronger then s , so let's first drink s 
        }
        for(int i=0;i<n;++i){
            if(ind[i]==0)
                order.insert(i);
        }
        top_sort();
        for(int i=0;i<n;++i){
            if(!visited[i]){
                ans.push_back(i);
            }
        }
        for(int i=0;i<(int)ans.size();++i){
            cout<<i_s[ans[i]];
            if(i+1!=(int)ans.size()){
                printf(" ");
            }
        }
        puts(".\n");
    }
    return 0;
}
