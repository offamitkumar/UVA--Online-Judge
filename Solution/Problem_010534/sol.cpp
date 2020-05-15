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
#define MAXN (int)20
array<int,MAXN>arr,inc,Dec;
void lis(int n){
    for(int i=0;i<n;++i){
        int j = 0;
        while(j<n && j<i){
            if(arr[i]>arr[j]){
                inc[i] = max(inc[i] , inc[j]+1);
            }
            ++j;
        }
    }
}
void lis1(int n){
    for(int i=n-1;i>=0;--i){
        int j = n-1;
        while(j>=0 && j>i){
            if(arr[i]>arr[j]){
                Dec[i] = max(Dec[i] , Dec[j]+1);
            }
            --j;
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int N; 
    while(cin>>N){
        fill(inc.begin(),inc.begin()+N,1);
        fill(Dec.begin(),Dec.begin()+N,1);
        for(auto i=0;i<N;++i){
            cin>>arr[i];
        }
        lis(N);
        lis1(N);
        int best = 1;
        for(auto i=0;i<N;++i){
            int l = min(inc[i] , Dec[N-i-1]);
            best = max(best , 2*l-1);
        }
        cout<<best<<'\n';
    }
    return 0;
}
