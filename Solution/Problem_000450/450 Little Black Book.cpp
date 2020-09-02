#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct Data{
    string fName , Name , lName , addr , hPhone, wPhone, box; 
    string department;
};
bool compare(Data &a, Data &b){
    bool ok = (a.lName <  b.lName);
    return ok;
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
    vector<Data>v;
    Data d;
    string info,fName,Name,lName,addr,hPhone,wPhone,box; 
    while(t--){
        string department; getline(cin , department);
        while(getline(cin, info) && info.size()){
            istringstream ss(info); 
            d.department = department;
            getline(ss, info , ','); 
            d.fName = info; 
            getline(ss, info , ','); 
            d.Name = info; 
            getline(ss, info , ','); 
            d.lName = info; 
            getline(ss, info , ','); 
            d.addr = info; 
            getline(ss, info , ','); 
            d.hPhone = info; 
            getline(ss, info , ','); 
            d.wPhone = info; 
            getline(ss, info , ','); 
            d.box = info; 
            v.emplace_back(d);
        }
    }
    sort(v.begin(), v.end(), compare);
    for(auto&i:v){
        cout <<"----------------------------------------" << '\n';
        cout << i.fName <<' ' << i.Name <<' ' << i.lName << '\n'; 
        cout << i.addr << '\n'; 
        cout << "Department: " << i.department << '\n'; 
        cout << "Home Phone: " << i.hPhone << '\n'; 
        cout << "Work Phone: " << i.wPhone << '\n'; 
        cout << "Campus Box: " << i.box << '\n'; 
    }
    return 0;
}
