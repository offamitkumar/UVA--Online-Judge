/*
 * If you print the for first 200 number then you can see 
 *
 * the pattern easily 
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t

//  int f91(int n){
//      if(n>=101){
//          return n-10;
//      }else{
//          return f91(f91(n+11));
//      }
//  };

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; 
    while(cin>>n,n){
        int f91;
        if(n<=100){
            f91 = 91;
        }else{
            f91 =n-10;
        }
        printf("f91(%ld) = %ld\n",n,f91);
    }
    return 0;
}
