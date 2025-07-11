#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string , int> mp;
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
    // mp["four"] = 4;


    map<string , int>  it;
    for(auto it = mp.begin() ; it != mp.end() ; it++){
        cout<<"key:=> "<<it->first <<" value: => "<<it->second <<endl;
    }

    cout<<"Size of map :=> "<<mp.size();

    return 0;
}