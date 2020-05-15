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
#define MAXN (int)1e6+100
vector< tuple< int , int , int > > node;
array< int , MAXN > par;
int find_parent(int a ){
    if(par[a] == a){
        return a;
    }
    return par[a] = find_parent(par[a]);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    bool more = false;
    while(scanf("%d",&n)!=EOF){
        int u , v , w;
        if(more){
            puts("");
        }
        more = true;
        iota(par.begin() , par.begin()+n+10 , 0);
        node.clear();
        long long price{};
        for(int i{0};i < n-1;++i){
            scanf("%d%d%d",&u,&v,&w);
            price+=w;
        }
        printf("%lld\n",price);
        int k; scanf("%d",&k);
        for(int i{0}; i < k; ++i){
            scanf("%d%d%d",&u , &v , &w);
            node.push_back(make_tuple(w,u,v));
        }
        scanf("%d",&k);
        for(int i{0}; i < k; ++i){
            scanf("%d%d%d",&u , &v , &w);
            node.push_back(make_tuple(w,u,v));
        }
        sort(node.begin() , node.end());
        price = 0ll;
        for(int i=0; i < (int)node.size(); ++i){
            int a = find_parent(get<1>(node.at(i)));
            int b = find_parent(get<2>(node.at(i)));
            if(a != b){
                par[a] = b;
                price+=get<0>(node.at(i));
            }
        }
        printf("%lld\n",price);
    }
    return 0;
}
