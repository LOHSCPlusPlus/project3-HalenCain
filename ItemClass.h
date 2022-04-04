#include <iostream>
#include <fstream>
using namespace std;

class Game {
  public:
    Game();
    void print();
    void readFromUser(int gamesAmount);
    void readFile(ifstream &file);
    void readToFile(ofstream &out);
  private:
    enum {MAX_CHAR = 100};
    char name[MAX_CHAR];
    int sales;
    char platform[MAX_CHAR];
    char releaseDate[MAX_CHAR];
    char developer[MAX_CHAR];
    char publisher[MAX_CHAR];
};