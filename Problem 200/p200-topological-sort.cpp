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
#define MAXN int('Z')+10
bitset<300>visited , present;
array<vector<char> , MAXN>graph;
string res{""};
void dfs(char ch){
    visited.set(ch);
    for(auto &itr:graph[ch]){
        if(!visited[itr]){
            dfs(itr);
        }
    }
    res+=ch;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif
	string previous , current ;
	cin>>previous;
	visited.reset();
	present.reset();
	while(cin>>current && current!="#"){
        for(int i{} , j{}; i< (int) current.size() and j < (int) previous.size() ; ++i , ++j){
            if(previous[i]!=current[i]){
                present[previous[i]] = true;
                present[current[i]] = true;
                graph[previous[i]].push_back(current[i]);
                break;
            }
        }
        previous = current;
	}
    for(auto ch = 'A'; ch<='Z';++ch){
        if(!visited[ch] and present[ch]){
            dfs(ch);
        }
    }
    reverse(res.begin() , res.end());
    cout<<res<<'\n';
    return 0;
}
