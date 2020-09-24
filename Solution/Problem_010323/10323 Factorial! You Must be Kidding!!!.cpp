#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define LOW 10000
#define HIGH 6227020800

int factorial(int n) {
    if(n < 0) {
        if(n&1){
            throw "Overflow!";
        }else{
            throw "Underflow!";
        }
    }
    int counter{1};
    while(n>0){
        counter *= n;
        if(counter > HIGH) {
            throw "Overflow!";
        }
        --n;
    }
    if(counter < LOW) {
        throw "Underflow!";
    }
    return counter; 
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n;
    while(cin >> n){ 
        try{
            cout << factorial(n) << '\n'; 
        }catch(const char* message) {
            cout << message << '\n'; 
        }
    }
    return 0;
}
