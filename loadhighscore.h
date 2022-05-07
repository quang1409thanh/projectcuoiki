#include<fstream>
int loadhighscore(){
    std::ifstream inFile;
    inFile.open("highscore.txt");
    int n;
    inFile >> n;
    return n;
}
void sethighscore(int& n){
    std::ofstream outFile;
    outFile.open("highscore.txt");
    outFile << n;
    outFile.close();
}