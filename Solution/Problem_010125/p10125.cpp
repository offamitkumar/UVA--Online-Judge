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
#define MAXN 1010
array<int,MAXN>arr;

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n;
    while(cin>>n,n){
        for(auto i{0};i<n;++i)
            cin>>arr[i];
        sort(arr.begin() , arr.begin()+n);
        int best{-1};
        for(auto i=n-1;i>=0;--i){ // d
            for(auto j=0;j<n;++j){ // c
                if(i==j)continue;
                auto a=0,b=n-1;
                while(a==j || a==i)++a;
                while(b==j || b==i)--b;
                while(a<b){
                    int d= arr[i] - (arr[j]+arr[a]+arr[b]);
                    if(d==0){
                        best = arr[i];
                        goto hell;
                    }
                    if(d>0){
                        ++a;
                        while(a==j || a==i)++a;
                    }else{
                        --b;
                        while(b==j || b==i)--b;
                    }
                }
            }
        }
hell:
        if(best==-1)cout<<"no solution";
        else cout<<best;
        cout<<'\n';
    }
    return 0;
}
