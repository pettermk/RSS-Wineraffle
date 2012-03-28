#include "contest.h"
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <cstdlib>
#include <ctime>

using namespace std;

Contest::Contest() {
  totaltickets_ = 0;
  cout << endl << endl << "  --- *** Welcome to RSS Wineraffle *** ---" << endl << endl;
}

void
Contest::AddKid(shared_ptr<Contestant> &contestant) {
  contestants_.push_back(contestant);
  totaltickets_ += contestant->GetNumTickets();
  kids_++;
}

Contestant*
Contest::GetKid(int index) {
  return contestants_[index].get();
}

void
Contest::PrintMenu() {
  cout << "1. Add contestant" << endl 
       << "2. Remove contestant"<< endl
       << "3. Print status" << endl
       << "4. Draw winner" << endl
       << "5. Quit" << endl
       << "Enter your choice: " << endl
       << "> ";
}

bool
Contest::HandleMenu(string choice) {
  int number;
  try {
    number = boost::lexical_cast<int>(choice);
  }
  catch(boost::bad_lexical_cast) {
    cout << "Invalid choice, try again";
    return false;
  }
  
  switch(number) {
  case 1:
    AddContestant();
    break;
  case 2:
    RemoveContestant();
    break;
  case 3:
    PrintStatus();
    break;
  case 4:
    DrawWinner();
    break;
  case 5:
    return true;
    break;
  default:
    cout << "Invalid choice, try again" << endl;
    break;
  }
  return false;
  
}

void 
Contest::AddContestant() {
  string name = "";
  string input;
  int    tickets;
  cout << "Enter name:\n> ";
  getline(cin, name); //cin >> name;
  cout << "Enter number of tickets: \n> ";
  getline(cin, input);
  try {
    tickets = boost::lexical_cast<int>(input);
  }
  catch(boost::bad_lexical_cast &) {
    cout << "Illegal value, try again" << endl;
    return;
  }
  auto newcontestant = make_shared<Contestant>();
  newcontestant->SetName(name);
  newcontestant->SetNumTickets(tickets);
  AddKid(newcontestant);
}

void
Contest::RemoveContestant() {
  string name;
  auto found = false;
  cout << "Remove contestant named: " << endl << "> ";
  getline(cin, name);
  vector<shared_ptr<Contestant>>::iterator iter;
  for(iter = contestants_.begin(); iter < contestants_.end(); iter++) {
    if(iter->get()->GetName() == name) {
      totaltickets_ -= iter->get()->GetNumTickets();
      found = true;
      continue;
    }
  }
  if(found) {
    contestants_.erase(iter);
    kids_--;
  }
  else {
    cout << "Contestant not found, try again" << endl;
  }
}

void
Contest::PrintStatus() {
  for(auto iter : contestants_) {
    iter->PrintInfo();
  }
  cout << "Total number of tickets: " << boost::lexical_cast<string>(totaltickets_) << endl;
}

void
Contest::DrawWinner() {
  srand(time(NULL));
  if (totaltickets_ > 0) {
    int draw = rand() % totaltickets_;
    int ticketscounter = 0;
    for(auto iter : contestants_) {    
      ticketscounter += iter->GetNumTickets();
      if(draw < ticketscounter) {
	iter->SetNumTickets(iter->GetNumTickets() - 1);
	totaltickets_--;
	cout << "Winner is " << iter->GetName() << "!!!!!!!";
	return;
      }
    }
  }
  else {
    cout << "Everyone is out of tickets. Buy some new!" << endl;
    return;
  }
  cout << "Critical error, nobody won!!!";
  return;
}
  
  
