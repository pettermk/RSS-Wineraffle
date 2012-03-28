#ifndef CONTEST_H
#define CONTEST_H

#include "contestant.h"
#include <vector>
#include <memory>
#include <string>
//#include <boost/shared_ptr.hpp>

class Contest
{
 public:
  Contest();
  void                   AddKid(std::shared_ptr<Contestant> &contestant);
  int                    GetNoKids();
  bool                   RemoveKid(int index);
  Contestant            *GetKid(int index);
  void                   PrintMenu();
  bool                   HandleMenu(string choice);
  void                   AddContestant();
  void                   RemoveContestant();
  void                   DrawWinner();
  void                   PrintStatus();

 private:
  vector<shared_ptr<Contestant>> contestants_;
  int                    kids_;
  int                    totaltickets_;
};

#endif
