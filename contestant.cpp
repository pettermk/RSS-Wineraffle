#include "contestant.h"
#include <iostream>
#include <boost/lexical_cast.hpp>

Contestant::Contestant() {
  name_ = string("");
  num_tickets_ = 0;
  
}

Contestant::Contestant(Contest* parent) {
  name_ = "";
  num_tickets_ = 0;
  parent_ = parent;
}

void
Contestant::SetName(string name) {
  name_ = name;
}

string
Contestant::GetName() {
  return name_;
}

void
Contestant::SetNumTickets(int numtickets) {
  num_tickets_ = numtickets;
}

int
Contestant::GetNumTickets() {
  return num_tickets_;
}

void
Contestant::PrintInfo() {
  cout << name_ << " has " << boost::lexical_cast<string>(num_tickets_) << " tickets" << endl;
}

void
Contestant::SetChanceLower(int lower) {
  chance_[0] = lower;
}

void
Contestant::SetChanceUpper(int upper) {
  chance_[1] = upper;
}
