#pragma once
#include "profile.h"

class Network {
 private:
  static const int MAX_USERS = 20;
  int numUsers;
  Profile profiles[MAX_USERS];
  int findID (std::string u);
  bool following[MAX_USERS][MAX_USERS];
 public:
  Network();
  bool addUser(std::string u, std::string d);
  bool follow(std::string usrn1, std::string usrn2);
  void printDot();
  void resetIt();
};
