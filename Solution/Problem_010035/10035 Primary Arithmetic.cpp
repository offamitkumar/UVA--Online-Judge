#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int u , v; 
    while(cin >> u >> v, u+v){
        int counter{};
        int carry{};
        while(u || v){
            int temp = (u%10 + v%10);
            temp+=carry; carry = 0;
            counter+=(temp>=10);
            carry = temp/10;
            u/=10;
            v/=10;
        }
        if(counter == 0){
            cout << "No";
        }else{
            cout << counter;
        }
        cout <<" carry operation";
        if(counter >1){
            cout <<"s.";
        }else{
            cout <<".";
        }
        cout << '\n'; 
    }
    return 0;
}
