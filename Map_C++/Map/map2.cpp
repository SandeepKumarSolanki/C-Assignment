#include<iostream>
#include<map>
#include<iterator>
using namespace std;

int main(){
    map<int,int> mp;
    
    // insert elements in random order
    mp.insert(pair<int, int>(4, 40));
    mp.insert(pair<int, int>(2, 30));
    mp.insert(pair<int, int>(5, 60));
    mp.insert(pair<int, int>(1, 20));
    mp.insert(pair<int, int>(3, 50));
    mp.insert(pair<int, int>(6, 50));

    map<int,int>::iterator it;

    for(auto it = mp.begin() ; it != mp.end() ; it++){
        cout<<"Key : => "<<it->first<<" Value : => " <<it->second <<endl;
    }
}