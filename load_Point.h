#include<vector>
#include<fstream>
struct Point{
    int x;
    int y;
    Point(){
        x=0;
        y=0;
    }
    Point(int a,int b){
        x=a;
        y=b;
    }
};
vector<Point> load_Vector(std::string s){
    ifstream in(s);
    int n;
    in>>n;
    vector<Point> v;
    while(!in.eof()){
        int x,y;
        in>>x>>y;
        v.push_back(Point(x,y));
    }
    return v;
}