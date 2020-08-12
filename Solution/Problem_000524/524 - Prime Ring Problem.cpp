#include <bits/stdc++.h>
using namespace std;
#define int int64_t
map<int , set<vector<int>>>f;
set<vector<int>>res;
bool isPrime(int n){
    for(int i=2; i*i<=n;++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
deque<int>d;
set<int>selected;
void ok(int n){
    vector<int>v(d.begin(),d.end());
    if(!isPrime(v[0]+v[n-1])){
        return;
    }
    for(int i=0; i<n; ++i){
        int j = (i+1)%n;
        if(!isPrime(v[i]+v[j])){
            return;
        }
    }
    vector<int>dum;
    for(int i=0; i<n;++i){
        dum.push_back(v.at(i));
    }
    res.insert(dum);
    dum.clear();
    dum.push_back(v[0]);
    for(int i=n-1; i>=1; --i){
        dum.push_back(v[i]);
    }
    res.insert(dum);
}
set<int>removed;
void print(int n,int c=1){
    if(c==n){
        ok(n);
    }
    int x = d.back(); 
    for(int i:selected){
        if(removed.find(i)==removed.end() && isPrime(x+i)){
            removed.insert(i);
            d.push_back(i);
            print(n,c+1);
            d.pop_back();
            removed.erase(i);
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
    int n; 
    int case_counter{1};
    while(cin >> n){ 
        if(case_counter!=1){
            cout << '\n'; 
        }
        res.clear();
        selected.clear();
        for(int i=2;i<=n;++i){
            selected.insert(i);
        }
        d.push_back(1);
        cout << "Case "<< case_counter++ << ":"<<'\n'; 
        if(f.find(n)==f.end()){
            print(n);
        }
        d.pop_back();
        if(f.find(n)==f.end()){
            f[n]= res;
        }else{
            res = f[n];
        }
        for(auto&itr:res){
            for(int i=0; i<(int)itr.size();++i){
                if(i){
                    cout <<' ' ;
                }
                cout << itr.at(i);
            }
//             for(auto&it:itr){
//                 cout << it<<' ';
//             }
            cout << '\n'; 
        }
    }
    return 0;
}
