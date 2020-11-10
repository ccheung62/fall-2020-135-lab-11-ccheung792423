#pragma once
class Profile {
 private:
  std::string username;
  std::string displayname;
 public:
  Profile(std::string u, std::string d);
  Profile();
  std::string getUsername();
  std::string getFullName();
  void setDisplayName(std::string d);
};
