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
#define MAXN (int)1e5+3
int arr[MAXN][10];
inline void write(int i,string j){
    for(int k=0;k<=9;++k){
        arr[i][k]=arr[i-1][k];
    }
    for(auto&itr:j){
        arr[i][itr-'0']++;
    }
}
inline void pre(void){
    memset(arr , 0, sizeof(arr));
//    arr[0][0]=1;
    for(int i{1};i<MAXN;++i){
        write(i,to_string(i));
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    pre();
    int test_case;cin>>test_case;
    while(test_case--){
        int n; cin>>n;
        for(int i=0;i<=9;++i){
            cout<<arr[n][i];
            if(i!=9){
                cout<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}
