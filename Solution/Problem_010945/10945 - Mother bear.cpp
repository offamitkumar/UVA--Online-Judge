#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool anagram(const string &a){
    int left = 0 , right = a.size() -1; 
    while(left < right){
        if(char(tolower(a[left])) != char(tolower(a[right]))){
            return false;
        }
        ++left; 
        --right;
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
    string s; 
    while(getline(cin,s) && s!= "DONE"){
        string s_real;
        for(auto&itr:s){
            if((itr>='a' && itr<='z') || (itr >='A' && itr<='Z')){
                s_real += itr;
            }
        }
        if(anagram(s_real)){
            cout << "You won't be eaten!" << '\n'; 
        }else{
            cout << "Uh oh.." << '\n';
        }
    }
    return 0;
}
