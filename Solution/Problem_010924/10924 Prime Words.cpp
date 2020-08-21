#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool isPrime(int x){
    for(int i=2; i*i <= x; ++i){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    map<char , int> f; 
    int counter= 1;
    for(auto ch = 'a'; ch <='z'; ++ch){
        f[ch]  = counter++;
    }
    for(auto ch = 'A'; ch <='Z'; ++ch){
        f[ch]  = counter++;
    }
    string s; 
    while(cin >> s){
        counter = 0;
        for(auto&itr:s){
            counter += f[itr];
        }
        if(isPrime(counter)){
            cout <<"It is a prime word.";
        }else{
            cout <<"It is not a prime word.";
        }
        cout << '\n'; 
    }
    return 0;
}
