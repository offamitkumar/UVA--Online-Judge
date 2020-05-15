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
#define MAXN 5*int(1e5)+100
array<int,MAXN> arr, temp;
long long ans = 0;
void merge(int start ,int end){
    int mid = (start+end)/2;
    int i = start , k = start , j = mid+1; 
    while(i<=mid and j<=end){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            ans+=(mid - i+1);
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    for(i = start; i<=end;++i){
        arr[i] = temp[i];
    }
}
void inver(int start , int end ){
    if(start >= end){
        return ;
    }
    int mid = (start+end)/2;
    inver(start , mid);
    inver(mid+1 , end);
    merge(start ,end);
    return ;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    while(cin>>n,n){
        ans =0;
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        inver(0 , n-1);
        cout<<ans<<'\n';
    }
    return 0;
}
