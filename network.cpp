#include <iostream>

#include "profile.h"
#include "network.h"

Network::Network (){
  numUsers = 0;
  numPosts = 0;
  for(int i=0; i<MAX_USERS; i++){
    for(int j=0; j<MAX_USERS; j++){
      following[i][j] = false;
    }
  }
}

int Network::findID (std::string u){
  for(int i=0; i<numUsers; i++){
    if (profiles[i].getUsername() == u){
      return i;
    }
  }
  return -1;
}

bool Network::addUser(std::string u, std::string d){
  if(numUsers > 19 || findID(u) >= 0 || u == "") {
    return false;
  }
  for (int i=0; i<u.length(); i++){
    if (!isalnum(u[i])){
      return false;
    }
  }
  Profile a(u,d);
  profiles[numUsers] = a;
  numUsers++;
  return true;
}

bool Network::follow(std::string u1, std::string u2){
  if (findID(u1) == -1 || findID(u2) == -1){
    return false;
  }
  if (following[findID(u1)][findID(u2)] == true){
    return false;
  }
  following[findID(u1)][findID(u2)] = true;
  return true;
}

void Network::printDot(){
  std::string result = "digraph {\n";
  for (int i=0; i<numUsers; i++){
    result += "   \"@" + profiles[i].getUsername() + "\";\n";
  }
  result += "\n";
  for (int i=0; i<numUsers; i++){
    for (int j=0; j<numUsers; j++){
      if (following[i][j]){
	result += "   \"@" + profiles[i].getUsername() + "\" -> \"@" + profiles[j].getUsername() + "\";\n";
      }
    }
  }
  result += "}";
  std::cout << result << std::endl;
}

void Network::resetIt(){
  numUsers = 0;
  numPosts = 0;
  for(int i=0; i<MAX_USERS; i++){
    for(int j=0; j<MAX_USERS; j++){
      following[i][j] = false;
    }
  }
}

bool Network::writePost(std::string u, std::string m){
  if (findID(u) == -1 || numPosts > MAX_POSTS-1){
    return false;
  }
  posts[numPosts].username = u;
  posts[numPosts].message = m;
  numPosts++;
  return true;
}

bool Network::printTimeline(std::string u){
  if (findID(u) == -1){
    return false;
  }
  std::string result = "";
  bool som = false;
  for(int i=numPosts-1; i>=0; i--){
    if(following[findID(u)][findID(posts[i].username)] || posts[i].username == u){
      result += profiles[findID(posts[i].username)].getFullName() + ": " + posts[i].message + "\n";
      som = true;
    }
  }
  std::cout << result << std::endl;
  return som;
}

