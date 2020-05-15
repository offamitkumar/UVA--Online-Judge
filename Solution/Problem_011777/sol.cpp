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
    for(int case_counter{1};case_counter<=t;++case_counter){
        printf("Case %d: ",case_counter);
        int arr[3];
        int x , sum{};
        for(int i=0;i<4;++i){
            cin>>x;
            sum+=x;
        }
        for(int i=0;i<3;++i){
            cin>>arr[i];
        }
        sort(arr,arr+3);
        sum+=(arr[1]+arr[2])/2;
        if(sum>=90){
            puts("A");
        }else if(sum>=80){
            puts("B");
        }else if(sum>=70){
            puts("C");
        }else if(sum>=60){
            puts("D");
        }else{
            puts("F");
        }
    }
    return 0;
}
