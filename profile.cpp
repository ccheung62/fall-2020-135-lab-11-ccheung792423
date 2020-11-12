#include <iostream>

#include "profile.h"

Profile::Profile(std::string u, std::string d){
  username = u;
  displayname = d;
}

Profile::Profile(){
  username = "";
  displayname = "";
}

std::string Profile::getUsername(){
  return username;
}

std::string Profile::getFullName(){
  return displayname + "(@" + username + ")";
}

void Profile::setDisplayName(std::string d){
  displayname = d;
}

