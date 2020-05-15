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
    int road , name;
    int case_counter{1};
    while(cin>>road>>name && road !=0 && name!=0){
        printf("Case %d: ",case_counter++);
        road-=name;
        int i{};
        for(i=1;i<=26 && road>0;++i){ // for ith iteration we are name remaining cities with iA,iB,iC...
            road-=name;

        }
        if(road>0){
            puts("impossible");
        }else{
            cout<<i-1<<'\n';
        }
    }
output:   
    return 0;
}
