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
#define MAXN (int)1e6+10
bool arr[MAXN];
int sum(int i){
    int counter{i};
    while(i){
        counter+=(i%10);
        i/=10;
    }
    return counter;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    memset(arr,true,sizeof(arr));
    for(int i=1;i<=1000000;++i){
        if(arr[i]==true){
            cout<<i<<'\n';
        }
        int x = sum(i);
        if(x<MAXN){
            arr[x]= false;
        }
    }
    return 0;
}
