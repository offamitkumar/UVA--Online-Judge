#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int divisor(int x){
    int y{};
    for(int i =1ll ; i*i<=x;++i){
        if(x%i==0ll){
            y++; 
            if(x/i != i){
                y++;
            }
        }
    }
    return y;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; cin >> n; 
    while(n--){
        int x, y; cin >> x >> y;
        int num{} , numD{};
        for(int i= x; i <=y; ++i){
            int temp = divisor(i);
            if(temp > numD){
                num = i; 
                numD = temp;
            }
        }
        printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",x,y,num,numD);
    }
    return 0;
}
