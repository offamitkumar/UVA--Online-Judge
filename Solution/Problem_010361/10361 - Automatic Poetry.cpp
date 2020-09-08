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
    int t; cin >> t; 
    cin.ignore();
    while(t--){
        vector<string>v(5); 
        string dum; getline(cin , dum);
        int j =0; 
        for(int i=0; i < 5; ++i){
            while(j <(int)dum.size() && dum.at(j) != '>' && dum.at(j)!='<' && dum.at(j)!='.'){
                v.at(i).push_back(dum.at(j));
                ++j;
            }
            ++j;
        }
        for(int i=0; i<5; ++i){
            cout << v.at(i);
        }
        cout << '\n'; 
        getline(cin , dum);
        for(auto&itr:dum){
            if(itr!='.'){
                cout << itr;
            }else{
                break;
            }
        }
        cout << v.at(3) << v.at(2) << v.at(1) << v.at(4) << '\n'; 
    }
    return 0;
}
