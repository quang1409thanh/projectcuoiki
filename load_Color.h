#include<vector>
#include<fstream>
vector<char> load_Color(string s){
    ifstream in(s);
    int n;
    in>>n;
    vector<char> v;
    while(!in.eof()){
        char c;
        in>>c;
        v.push_back(c);
    }
    return v;
 }