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
    int t; scanf("%d",&t);
    for(int c = 1; c<=t; ++c){
        cout<<"Case "<<c<<": ";
        int n; cin>>n;
        int current = -1;
        int higher{} ,  lower{};
        for(int next, i=0;i<n;++i){
            cin>>next;
            if(i == 0){
                current = next;
                continue;
            }
            lower+=(current > next);
            higher+=(current < next);
            current = next;
        }
        cout<<higher<<' '<<lower<<'\n';
    }
    return 0;
}
