#include "ItemClass.h"
#include <iostream>
#include <fstream>
using namespace std;

class GamesDB{
  public:
    GamesDB();
    void print();
    void read();
    void save();
    void remove();
    void add();
    int getAmount();
    void insert();
  private:
    enum {MAX_GAMES=100};
    Game games[MAX_GAMES];
    int gamesAmount;
};