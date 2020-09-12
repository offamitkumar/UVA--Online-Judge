#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>arr , sortedArray;
int endPoint,Pos;
pair<int,int> getPosAndValue(void){
    auto p = make_pair(Pos , sortedArray.at(Pos)); 
    endPoint = Pos;
    --Pos; 
    return p;
}
int getPos(int value){
    for(int i=0; i<=endPoint; ++i ){
        if(arr.at(i) == value){
            return i;
        }
    }
    return -1;
}
void takeToOne(int pos){
    if(pos == 0){
        return;
    }else{
        cout << (int)arr.size()-pos <<' ';
        reverse(arr.begin(), arr.begin()+pos+1);
    }
}
void takeToPerfectPosition(int pos){
    cout << (int)arr.size()-pos<<' ';
    reverse(arr.begin(), arr.begin()+pos+1);
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
    while(getline(cin , s)){
        istringstream ss(s); 
        arr.clear(); 
        sortedArray.clear();
        int x;
        bool more = false;
        while(ss >> x){
            if(more){
                cout<<' ';
            }
            more = true;
            arr.push_back(x);
            cout << x ;
        }
        cout << '\n';
        Pos = arr.size()-1;
        sortedArray = arr; 
        sort(sortedArray.begin(), sortedArray.end());
        while(true){
            int pos , value; 
            tie(pos , value) = getPosAndValue();
            if(pos==0){
                break;
            }
            // check where the element is current position 
            int currentPos = getPos(value);
            assert(currentPos!=-1); 
            if(currentPos == pos){continue;}
            takeToOne(currentPos); // take this element to first position
            takeToPerfectPosition(pos); // take to position where this element should be
        }
        for(auto&itr:arr){
            cerr << itr <<' ';
        }
        cerr << '\n';
        cout << 0 << '\n';
    }
    return 0;
}
