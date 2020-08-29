#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool onlySpace(const string&a , const string&b){
    int i=0, j=0;
    while(i<static_cast<int>(a.size()) && j < static_cast<int>(b.size())){
        if(a.at(i)==' '){
            ++i;
            continue;
        }
        if(b.at(j)==' '){
            ++j; continue;
        }
        if(a.at(i) != b.at(j)){
            return false;
        }
        ++i; 
        ++j;
    }
    if(i < static_cast<int>(a.size())){
        while(i  < static_cast<int>(a.size())){
            if(isalpha(a.at(i))){
                return false;
            }
            ++i;
        }
    }else if(j < static_cast<int>(b.size())){
        while(j  < static_cast<int>(b.size())){
            if(isalpha(b.at(j))){
                return false;
            }
            ++j;
        }
    }
    return true;
}
string sol(const string&a, const string&b){
    string Yes = "Yes" , WA = "Wrong Answer" , OutPutError = "Output Format Error";
    if(a == b){
        return Yes;
    }else{
        if(onlySpace(a,b)){
            return OutPutError;
        }else{
            return WA;
        }
    }
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t;
    cin.ignore();
    for (int tCounter =1 ;tCounter<=t;++tCounter) {
        string A, B; 
        getline(cin, A); 
        getline(cin, B);
        printf("Case %ld: %s\n",tCounter, sol(A , B).c_str());
    }
    return 0;
}
