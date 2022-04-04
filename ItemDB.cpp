#include "ItemDB.h"
#include "ReadUtils.h"
#include <iostream>
#include <fstream>
using namespace std;

GamesDB::GamesDB(){
  gamesAmount = 0;
  read();
}


void GamesDB::read(){
  ifstream file("videogames.txt");
  while (file.peek() != EOF){
    games[gamesAmount].readFile(file);
    gamesAmount++;
  }
}

void GamesDB::save(){
  ofstream out("videogames.txt");
  for (int i = 0; i < gamesAmount; i++){
    cout << "1";
    games[i].readToFile(out);
  }
}

void GamesDB::remove(){
  int gone = readInt("Please enter the index you would like to remove");
  for(int i = gone; i < gamesAmount; i++){
    games[i] = games[i + 1];
  }  
  gamesAmount--;
}

void GamesDB::add(){
  if (gamesAmount < MAX_GAMES){            
    games[gamesAmount].readFromUser(gamesAmount);
  gamesAmount++;
    }
  else{
    cout << "No more space!" << endl;
  }
}

int GamesDB::getAmount(){
  return gamesAmount;
}

void GamesDB::print(){
  for (int i = 0; i < gamesAmount; i++){
    cout << "---GAME #" << i << "---" << endl;
    games[i].print();
  }
}

void GamesDB::insert(){
  int here = readInt("Please enter the index you would like to insert at");
  for(int i = gamesAmount; i > here; i--){
    games[i] = games[i - 1];
    
  }
  games[here].readFromUser(gamesAmount);
  gamesAmount++;
}