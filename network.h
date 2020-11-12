#pragma once
#include "profile.h"

struct Post{
  std::string username;
  std::string message;
};

class Network {
 private:
  static const int MAX_USERS = 20;
  int numUsers;
  Profile profiles[MAX_USERS];
  int findID (std::string u);
  bool following[MAX_USERS][MAX_USERS];
  static const int MAX_POSTS = 100;
  int numPosts;
  Post posts[MAX_POSTS];

 public:
  Network();
  bool addUser(std::string u, std::string d);
  bool follow(std::string usrn1, std::string usrn2);
  void printDot();
  void resetIt();
  bool writePost(std::string usrn, std::string msg);
  bool printTimeline(std::string usrn);
};

