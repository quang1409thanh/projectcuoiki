#include<iostream>
#include<fstream>
#include<map>
#include<vector>
using namespace std;
int main(){
    string path;
    cin>>path;
    ifstream f(path);
    string x;
    map<char, int > m;
    while(f>>x){
        for(int i=0;i<x.size();i++){
            m[x[i]]++;
        }
    }
    for(auto & i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }
}