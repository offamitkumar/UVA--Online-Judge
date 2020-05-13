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
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    while(cin>>n,n){
        map<int ,int>incoming , outgoing;
        for(int i=0;i<n;++i){
            int inc , out;
            cin>>inc>>out;
            outgoing[inc]++;
            incoming[out]++;
        }
        if(outgoing.size() != incoming.size()){
            puts("NO");
            goto hell;
        }else{
            auto itr = incoming.begin();
            auto itr1 = outgoing.begin();
            while(itr1 != outgoing.end()){
                if(itr1 ->first != itr ->first){
                    puts("NO");
                    goto hell;
                }
                if(itr1 -> second != itr -> second){
                    puts("NO");
                    goto hell;
                }
                itr1 = next(itr1);
                itr = next(itr);
            }
        }
        puts("YES");
hell:
        ;
    }
    return 0;
}
