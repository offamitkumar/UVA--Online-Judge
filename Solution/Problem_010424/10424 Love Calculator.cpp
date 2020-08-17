#include <bits/stdc++.h>
using namespace std;
#define int int64_t
map<char , int>f;
int score(string s){
    int x{};
    for(auto&itr:s){
        x+=f[itr];
    }
    while(x >= 10){
        int y {}; 
        while(x){
            y+=(x%10); 
            x/=10;
        }
        x = y;
    }
    return x;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string a,b; 
    int j=1;
    for(char i='a'; i<='z'; ++i){
        f[i]=j++;
    }
    j=1;
    for(char i='A'; i<='Z'; ++i){
        f[i]=j++;
    }
    while(getline(cin , a) && getline(cin , b)){
        double x = score(a); 
        double y = score(b);
        double p1 = ((y / x) * 100.0f); 
        cout << fixed << setprecision(2); 
        if(p1 > 100.0f){
            cout <<  ((x/y) * 100.0f);
        }else{
            cout << p1 ;
        }
        cout <<" %" <<'\n'; 
    }
    return 0;
}
