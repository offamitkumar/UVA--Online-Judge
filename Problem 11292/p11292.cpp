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
#define MAXN 20020
array<int , MAXN>arr,kni;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n , m;
    while(cin>>n>>m && (n+m)>0){
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        for(int i=0;i<m;++i){
            cin>>kni[i];
        }
        sort(arr.begin() , arr.begin()+n);
        sort(kni.begin() , kni.begin()+m);
        int i = 0 , j = 0;
        int total=0;
        while(i<n && j<m){
            if(arr[i] <= kni[j]){
                total+=kni[j];
                ++i;
                ++j;
                continue;
            }
            if(arr[i] > kni[j]){
                ++j;
            }
        }
        if(i>=n){
            cout<<total<<'\n';
        }else{
            cout<<"Loowater is doomed!"<<'\n';
        }
    }
    return 0;
}
