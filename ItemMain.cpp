#include <iostream>
#include <fstream>
#include <cstring>
#include "ReadUtils.h"
#include "ItemDB.h"
using namespace std;

void menu(){ 
  cout << "1) Reload previous version" << endl;
  cout << "2) Print database" << endl;
  cout << "3) Add a game" << endl;
  cout << "4) Remove a game" << endl;
  cout << "5) Save current changes" << endl;
  cout << "6) Insert new game in specific spot" << endl;
  cout << "7) Quit" << endl;
}



int main(){
  GamesDB gamesOld;
  GamesDB games;

  int select = 0;
  do{
    menu();
    select = readInt("Please input a selection by inputting 1 - 7:");
    switch(select) {
      case 1:
        gamesOld.save();
        break;
      case 2:
        games.print();
        break;
      case 3:
        games.add();
        break;
      case 4:
        games.remove();
        break;
      case 5:
        games.save();
        gamesOld = games;
        break;
      case 6:
        games.insert();
      case 7:
        break;
      default:
        cout << "Please enter a valid option" << endl;
    }
  }while(select != 7);
  
  
  return 0;
}