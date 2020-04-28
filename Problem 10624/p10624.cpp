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
#define MAXN 50
int n , m ;
int ans[MAXN];
bool ans_found{false};
bool divisible(int index , int digit){
    int temp = 0;
    for(int i=1;i<index;++i){
        temp = temp*10+ans[i];
        temp%=index;
    }
    temp = temp*10+digit;
    return (temp%index==0);
}
void search(int index){
    if(ans_found){
        return;
    }
    if(index==m+1){
        ans_found = true;
        return;
    }
    int j=1;
    for(int i=(index==1);(!ans_found)&&i<10;i+=j){
        if(index>=n){
            if(divisible(index , i)){
                ans[index] = i;
                j = index;
                search(index+1);
            }
        }else{
            ans[index] = i;
            search(index+1);
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
//    freopen("output","w",stdout);
 //   freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    for(int x=1;x<=t;++x){
        cout<<"Case "<<x<<": ";
        ans_found = false;
        cin>>n>>m;
        memset(ans , -1 , sizeof(ans));
        search(1);
        if(ans_found){
            for(int i=1;i<=m;++i){
                cout<<ans[i];
            }
        }else{
            cout<<ans[0];
        }
        puts("");
    }
    return 0;
}
