#ifndef CONTESTANT_H
#define CONTESTANT_H

//#include "contest.h"
#include <string>
#include <vector>

class Contest;

using namespace std;

class Contestant 
{
public:
  Contestant();
  Contestant(Contest* parent);

  void        SetName(string name);
  void        SetNumTickets(int numtickets);

  string      GetName();
  int         GetNumTickets();

  void        PrintInfo();
  void        SetChanceLower(int lower);
  void        SetChanceUpper(int upper);

private:
  string      name_;
  int         num_tickets_;
  vector<int> chance_;
  Contest     *parent_;
};

#endif

