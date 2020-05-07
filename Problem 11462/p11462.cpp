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
    bool more = false;
    while(cin>>n){
        if(more){
            cout<<'\n';
        }
        more = true;
        int arr[101];memset(arr,0,sizeof(arr));
        int mx_found{-1};
        for(int x,i=0;i<n;++i){
            cin>>x;arr[x]++;
            mx_found = max(mx_found , x);
        }
        for(int i=1;i<101;++i){
            while(arr[i]!=0){
                printf("%d",i);
                --arr[i];
                if(i == mx_found){
                    if(arr[i]!=0){
                        printf(" ");
                    }
                }else{
                    printf(" ");
                }
            }
        }
    }
    return 0;
}