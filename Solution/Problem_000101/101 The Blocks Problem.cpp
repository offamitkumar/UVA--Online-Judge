#include <bits/stdc++.h>
using namespace std;
#define int int64_t

map<int,int>loc;
int getLocation(int b){
    //return loc[b];
    if(loc[b] == b){
        return b;
    }else{
        loc[b] = getLocation(loc[b]);
        return loc[b];
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
    int n; cin >> n; 
    vector<vector<int>> v(n);
    for(int i =0; i<n; ++i){
        v.at(i).push_back(i);
        loc[i] = i;
    }
    string c1,c2; 
    while(cin >> c1){
        int a,b;
        if(c1 == "move"){
            cin >> a >> c2 >> b; 
            if(getLocation(a) == b || getLocation(b) == a || a == b || getLocation(a) == getLocation(b)){
                continue;
            }
            if(c2 == "onto"){ 
                // return box on a to their location 
                for(int i=(int)v.at(getLocation(a)).size()-1; i>=0 && v.at(getLocation(a)).at(i)!=a;--i){
                    int x = v.at(getLocation(a)).back();
                    loc[x] = x;
                    v.at(x).push_back(x);
                    v.at(getLocation(a)).pop_back();
                }
                // return box on b to their location 
                for(int i=(int)v.at(getLocation(b)).size()-1; i>=0 && v.at(getLocation(b)).at(i)!=b;--i){
                    int x = v.at(getLocation(b)).back();
                    loc[x] = x;
                    v.at(x).push_back(x);
                    v.at(getLocation(b)).pop_back();
                }
                v.at(getLocation(a)).pop_back(); 
                loc[a] = b;
                v.at(getLocation(b)).push_back(a);
            }else {
                // empty a 
                for(int i=(int)v.at(getLocation(a)).size()-1; i>=0 && v.at(getLocation(a)).at(i)!=a;--i){
                    int x = v.at(getLocation(a)).back();
                    loc[x] = x;
                    v.at(x).push_back(x);
                    v.at(getLocation(a)).pop_back();
                }
                // put a on top of b
                v.at(getLocation(a)).pop_back(); 
                loc[a] = b;
                v.at(getLocation(b)).push_back(a);
            }
        }else if(c1 == "pile"){
            cin >> a >> c2 >> b; 
            if(getLocation(a) == b || getLocation(b) == a || a == b || getLocation(a) == getLocation(b)){
                continue;
            }
            if(c2 == "onto"){
                // empty box b 
                for(int i=(int)v.at(getLocation(b)).size()-1; i>=0 && v.at(getLocation(b)).at(i)!=b;--i){
                    int x = v.at(getLocation(b)).back();
                    loc[x] = x;
                    v.at(x).push_back(x);
                    v.at(getLocation(b)).pop_back();
                }
                // put everything containing the box a on to top of box b
                int Loc = getLocation(a);
                int i=0; 
                for(; i<(int)v.at(getLocation(a)).size(); ++i){
                    if(v.at(getLocation(a)).at(i) == a){
                        break;
                    }
                }
                int j = i; 
                // from here put everything on the top of b 
                for(; i<(int)v.at(Loc).size(); ++i){
                    int k = v.at(Loc).at(i);
                    v.at(getLocation(b)).push_back(k); 
                    loc[k] = b;
                }
                --i;
                for(; i>=j; --i){
                    v.at(Loc).pop_back();
                }
            }else {
                // get location of a 
                int i=0; 
                for(; i<(int)v.at(getLocation(a)).size(); ++i){
                    if(v.at(getLocation(a)).at(i) == a){
                        break;
                    }
                }
                int j = i; 
                int Loc = getLocation(a); 
                // from here put everything on the top of b 
                for(; i<(int)v.at(Loc).size(); ++i){
                    int k = v.at(Loc).at(i);
                    v.at(getLocation(b)).push_back(k); 
                    loc[k] = b;
                }
                --i;
                for(; i>=j; --i){
                    v.at(Loc).pop_back();
                }
            }
        }else {
            break;
        }
    }
    for(int i =0; i<n; ++i){
        cout << i << ":";
        for(int j=0; j<(int)v.at(i).size(); ++j){
            cout <<' ';
            cout <<  v.at(i).at(j);
        }
        cout << '\n'; 
    }
    return 0;
}
