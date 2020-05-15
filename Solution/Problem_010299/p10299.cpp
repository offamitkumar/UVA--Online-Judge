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
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long n; 
    while(cin>>n){
        if(n==0ll){
            break;
        }
        if(n==1ll){
            cout<<0<<endl;
            continue;
        }
        long long counter = n;
        for(int i=2ll;i*i<=n;++i){
            if(n%i==0){
                while(n%i==0){
                    n/=i;
                }
                counter-=(counter/i);
            }
        }
        if(n>1){
            counter-=(counter/n);
        }
        cout<<counter<<endl;
    }

    return 0;
}
