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
    string origString;
    set<char>vowel;
    vowel.insert('a');
    vowel.insert('e');
    vowel.insert('i');
    vowel.insert('o');
    vowel.insert('u');
    vowel.insert('y');
    while(getline(cin, origString)){
        if(origString == "e/o/i"){
            break;
        }
        int partOne{} , partTwo{} , partThree{};
        int i=0;
        for(; origString.at(i) != '/'; ){
            bool found = false;
            while(vowel.find(origString.at(i))!=vowel.end() && origString.at(i)!='/'){
                ++i;
                found = true;
            }
            if(found){
                partOne++;
            }else{
                if(origString.at(i) == '/'){
                    break;
                }
                ++i;
            }
        }
        ++i;
        for(; origString.at(i) != '/';){
            bool found = false;
            while(vowel.find(origString.at(i))!=vowel.end() && origString.at(i)!='/'){
                ++i;
                found = true;
            }
            if(found){
                partTwo++;
            }else{
                if(origString.at(i) == '/'){
                    break;
                }
                ++i;
            }
        }
//        cout <<"testing 1" << endl;
        ++i;
        for(;i<(int)origString.size(); ){
            bool found = false;
            while((int)origString.size()>i && vowel.find(origString.at(i))!=vowel.end()){
                ++i;
                found = true;
            }
            if(found){
                partThree++;
            }else{
                ++i;
            }
        }
        if(partOne!=5){
            cout << "1" << endl;
        }else if(partTwo!=7){
            cout << "2" << endl;
        }else if(partThree != 5){
            cout << "3" << endl;
        }else{
            cout << "Y" << endl;
        }
    }
    return 0;
}
