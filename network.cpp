#include <iostream>

#include "profile.h"
#include "network.h"

Network::Network (){
  numUsers = 0;
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
  if(numUsers > 19 || findID(u) > 0 || u == "") {
    return false;
  }
  for (int i=0; i<u.length(); i++){
    if (!isalnum(u[i])){
      return false;
    }
  }
  Profile a(u,d);
  numUsers ++;
  profiles[numUsers] = a;
  return true;
}

bool Network::follow(std::string u1, std::string u2){
  if (following[findID(u1)][findID(u2)] == true){
    return false;
  }
  following[findID(u1)][findID(u2)] = false;
  return true;
}

void Network::printDot(){
  digraph {
  "@mario"
  "@luigi"
  "@yoshi"

  "@mario" -> "@luigi"
  "@luigi" -> "@mario"
  "@luigi" -> "@yoshi"
  "@yoshi" -> "@mario"
}
}

void Network::resetIt(){
  numUsers = 0;
  for(int i=0; i<MAX_USERS; i++){
    for(int j=0; j<MAX_USERS; j++){
      following[i][j] = false;
    }
  }
}
