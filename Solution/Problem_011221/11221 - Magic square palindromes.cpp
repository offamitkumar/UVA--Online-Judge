//  Author : Amit Kumar 
//  Date   : Tuesday 21 July 2020 12:41:00 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t
string Get(void){
    string a; getline(cin , a); 
    string res;
    for(auto&itr:a){
        if(isalpha(itr)){
            res+=itr;
        }
    }
    return res;
}
bool palin(string &a){
    int high = a.size()-1; 
    int low = 0; 
    while(low < high){
        if(a[low] != a[high]){
            return false;
        }
        ++low; 
        --high;
    }
    return true;
}
signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            // DISABLE FOR INTERACTIVE PROBLEMS
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    int t; cin >>t ; 
    cin.ignore();
    for(int l = 1; l<=t; ++l){
        cout <<"Case #" << l <<":" << '\n'; 
        string s = Get();
        int a = sqrt(s.size()); 
        if((a*a!=(int)s.size())|| (!palin(s))){
            cout <<"No magic :(" << '\n'; 
        }else{
            cout << a << '\n'; 
        }
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
