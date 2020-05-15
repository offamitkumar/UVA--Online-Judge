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
array<char , MAXN>par;
array<bool , MAXN>visited;
void make_set(void){
    for(auto ch = 'A';ch<='Z';++ch){
        par[ch] = ch;
    }
}
char Find(char a){
    if(par[a]==a){
        return a;
    }
    return par[a] = Find(par[a]);
}
void Union(char a , char b){
    a = Find(a);
    b = Find(b);
    par[a] = b;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        char max_node; cin>>max_node;
        string s; int counter{};
        make_set();
        cin.ignore();
        fill(visited.begin() , visited.end() , false);
        while(true){
            if(!getline(cin,s) or s.empty()){
                break;
            }
            Union(s[0],s[1]);
        }
        for(auto ch = 'A'; ch<=max_node;++ch){
            char c = Find(ch);
            if(!visited[c]){
                counter++;
                visited[c] = true;
            }
        }
        printf("%d\n",counter);
        if(t>0){
            puts("");
        }
    }
    return 0;
}
