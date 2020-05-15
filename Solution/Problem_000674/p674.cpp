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
#define MAXN 8000 
int arr[MAXN][51];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int value = 7999;
    
    vector<int>coin {0,1,5,10,25,50};

    memset(arr , 0 , sizeof(arr));
    arr[0][0] = 1;
    for(int i=0;i<=50;++i){
        arr[0][i] = 1;
    }
    for(int j=1;j<(int)coin.size();++j){
        for(int i=1;i<=value;++i){
            if(i-coin[j]>=0){
                arr[i][coin[j]] = arr[i-coin[j]][coin[j]];
            }
            arr[i][coin[j]] += arr[i][coin[j-1]];

        }
    }
    while(cin>>value){
        cout<<arr[value][50]<<'\n';
    }
    return 0;
}
