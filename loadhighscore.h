#include<fstream>
int loadhighscore(){
    std::ifstream inFile;
    inFile.open("Data/data_txt/highscore.txt");
    int n;
    inFile >> n;
    return n;
}
void sethighscore(int& n){
    std::ofstream outFile;
    outFile.open("Data/data_txt/highscore.txt");
    outFile << n;
    outFile.close();
}