// #include "main.h"
#include "contest.h"
#include <iostream>

#include <fstream>
#include <string>
#include <memory>

using namespace std;


void PrintLogo() {
  string line;
  ifstream myfile("gfx/logo");
  if(myfile.is_open()) {
    while(myfile.good()) {
      getline(myfile, line);
      cout << line << endl;
    }
    myfile.close();
  }
  else {
    cout << "Critical error, logo not loaded";
  }
}

int main(){
  auto wineraffle = make_shared<Contest>();
  int stop = 0;
  string choice;
  while(!stop) {
    PrintLogo();
    cout << endl;
    wineraffle->PrintStatus();
    cout << endl;
    wineraffle->PrintMenu();
    getline(cin, choice);
    stop = wineraffle->HandleMenu(choice);
  }
  return 0;
}
