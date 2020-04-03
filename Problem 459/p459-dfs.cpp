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
#define MAXN (int)'Z'+10
array<vector<char>,MAXN>graph;
array<bool,MAXN>visited;
void dfs(char ch){
    visited[ch] = true;
    for(auto&itr:graph[ch]){
        if(!visited[itr]){
            dfs(itr);
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
    for(int tc=0;tc<t;++tc){
        char max_node; cin>>max_node;
        string s;
        fill(visited.begin(),visited.end(),false);
        for(char ch='A';ch<=max_node;++ch){
            graph[ch].clear();
        }
        cin.ignore();
        while(true){
            if(!getline(cin,s) || s.empty()){
                break;
            }
            graph[s[0]].push_back(s[1]);
            graph[s[1]].push_back(s[0]);
        }
        int counter{};
        for(auto ch = 'A';ch<=max_node;++ch){
            if(!visited[ch]){
                counter++;
                dfs(ch);
            }
        }
        if(tc>0){
            puts("");
        }
        printf("%d\n",counter);
    }
    return 0;
}
