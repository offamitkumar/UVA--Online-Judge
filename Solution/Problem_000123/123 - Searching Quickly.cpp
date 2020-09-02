#include <bits/stdc++.h>
using namespace std;
//.#define int int64_t
set<string>toIgnore;
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string temp;
    while(getline(cin,temp) && temp!="::"){
        toIgnore.insert(temp);
    }
    multimap<string,string>ans;
    while(getline(cin, temp)){
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        string key= temp;
        int i =0 , j= 0;
        while(i < (int)temp.size()){
            if(isalpha(temp.at(i))){
                j = i;
                string value;
                while(j<(int)temp.size() && isalpha(temp.at(j))){
                    value+=temp.at(j);
                    ++j;
                }
                if(toIgnore.find(value)==toIgnore.end()){
                    transform(temp.begin()+i, temp.begin()+j, temp.begin()+i, ::toupper);
                    ans.insert(make_pair(value , temp));
                    transform(temp.begin()+i, temp.begin()+j, temp.begin()+i, ::tolower);
                }
                i = j;
            }else{
                i++;
            }
        }
    }
    for(auto&itr:ans){
        cout << itr.second << '\n'; 
    }
    return 0;
}
