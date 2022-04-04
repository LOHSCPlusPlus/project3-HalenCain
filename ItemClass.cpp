#include <iostream>
#include <fstream>
#include "ItemClass.h"
#include "ReadUtils.h"
using namespace std;

Game::Game(){
  for (int i = 0; i < MAX_CHAR; i++){
    name[i] = '\0';
    platform[i] = '\0';
    releaseDate[i] = '\0';
    developer[i] = '\0';
    publisher[i] = '\0';
  }
  sales = 0;
}

void Game::print(){
  cout << "Title of game: " << name << endl;
  cout << "Number of sales: " << sales << endl;
  cout << "Platform: " << platform << endl;
  cout << "Release date: " << releaseDate << endl;
  cout << "Developer: " << developer << endl;
  cout << "Publisher: " << publisher << endl;
}

void Game::readFromUser(int gamesAmount){
  cout << "Please enter a game title:" << endl;
  cin.ignore(100, '\n');
  cin.getline(name, gamesAmount);

  sales = readInt("Please enter the number of sales:\n");
  
  cout << "Please enter the platform the game is on:" << endl;
    cin.ignore(100, '\n');
  cin.getline(platform, gamesAmount);
  
  cout << "Please enter a release date (i.e. September 25, 2003):" << endl;
  cin.getline(releaseDate, gamesAmount);
  
  cout << "Please enter the developer of the game:" << endl;
  cin.getline(developer, gamesAmount);
  
  cout << "Please enter the publisher of the game:" << endl;
  cin.getline(publisher, gamesAmount);
  
}

void Game::readFile(ifstream &file){
  file.get(name, MAX_CHAR, ';');
  file.ignore(100,';');
  file >> sales;
  file.ignore(100, ';');
  file.get(platform, MAX_CHAR, ';');
  file.ignore(100,';');
  file.get(releaseDate, MAX_CHAR, ';');
  file.ignore(100,';');
  file.get(developer, MAX_CHAR, ';');
  file.ignore(100,';');
  file.get(publisher, MAX_CHAR, '\n');
  file.ignore(100,'\n');
}

void Game::readToFile(ofstream &out){
  out << name << ";";
  out << sales << ";";
  out << platform << ";";
  out << releaseDate << ";";
  out << developer << ";";
  out << publisher << endl;
}