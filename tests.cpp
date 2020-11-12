#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

Profile p1("reconnecting...", "Alijah");
Profile p2("iPad", "Yamilette");
Profile p3("Arianna", "Gao");
Network nw;

TEST_CASE ("Task A"){
  CHECK(p1.getUsername() == "reconnecting...");
  CHECK(p1.getFullName() == "Alijah(@reconnecting...)");
  p1.setDisplayName("jennylin");
  CHECK(p1.getFullName() == "jennylin(@reconnecting...)");
  CHECK(p2.getUsername() == "iPad");
  CHECK(p2.getFullName() == "Yamilette(@iPad)");
  p2.setDisplayName("Lori");
  CHECK(p2.getFullName() == "Lori(@iPad)");
  CHECK(p3.getUsername() == "Arianna");
  CHECK(p3.getFullName() == "Gao(@Arianna)");
  p3.setDisplayName("Sami");
  CHECK(p3.getFullName() == "Sami(@Arianna)");
}

//Task B
TEST_CASE("Task B: Empty String"){
  CHECK(nw.addUser("","Marc") == false);
}
TEST_CASE ("Task B: Regular Cases"){
  CHECK(nw.addUser("Marc", "Cuadra") == true);
  CHECK(nw.addUser("kai", "barry") == true);
  CHECK(nw.addUser("tyler levitt", "simonelli") == false);
  CHECK(nw.addUser("tasmia !@#", "chowdhury") == false);
  CHECK(nw.addUser("Marc", "zainab") == false);
  CHECK(nw.addUser("svetlanaK", "rivitsky") == true);
  CHECK(nw.addUser("nahima123", "ahmed") == true);
  for(int i=0; i<16; i++){
    nw.addUser("steven"+std::to_string(i), "coronado"+std::to_string(i));
  }
  CHECK(nw.addUser("matthew", "padilla") == false);
  CHECK(nw.addUser("luisa", "velasquez") == false);
}

//Task C
TEST_CASE("Task C: Regular Cases"){
  CHECK(nw.follow("Marc", "kai") == true);
  CHECK(nw.follow("kai", "Marc") == true);
  CHECK(nw.follow("kai", "Marc") == false);
  CHECK(nw.follow("Marc", "svetlanaK") == true);
  CHECK(nw.follow("svetlanaK", "Marc") == true);
  CHECK(nw.follow("nahima123", "steven1") == true);
  CHECK(nw.follow("steven1", "nahima123") == true);
  CHECK(nw.follow("nahima123", "steven1") == false);
}

TEST_CASE("Task C: non-existance username"){
  CHECK(nw.follow("melano", "hyun") == false);
  CHECK(nw.follow("jeremy", "steven10") == false);
  CHECK(nw.follow("steven7", "kang") == false);
}

//Task D
TEST_CASE ("Task D: Empty String"){
  CHECK(nw.writePost("","") == false);
  CHECK(nw.writePost("steven0", "") == true);
  CHECK(nw.writePost("", "Test 2") == false);
}
TEST_CASE ("Task D: Regular Cases"){
  CHECK(nw.writePost("Marc", "It's a-me, Mario!") == true);
  CHECK(nw.writePost("kai", "Hey, hey!") == true);
  CHECK(nw.writePost("nahima123", "Helloooo") == true);
  CHECK(nw.writePost("steven13", "yep") == true);
  //user not in network
  CHECK(nw.writePost("melano", "Hi Luigi!") == false);
  CHECK(nw.writePost("jeremy", "Test 1") == false);
  CHECK(nw.writePost("kang", "Test 3") == false);
  for (int i=5; i<=100; i++){
    nw.writePost("steven9", "Test "+ std::to_string(i));
  }
  CHECK(nw.writePost("Marc", "Happy") == false);
  CHECK(nw.writePost("kai", "Me too") == false);
}
TEST_CASE("Task D: Print Timeline"){
  CHECK(nw.printTimeline("steven0") == true);
  CHECK(nw.printTimeline("kai") == true);
  CHECK(nw.printTimeline("") == false);
}
TEST_CASE("Task D: Only follower have posts"){
  CHECK(nw.printTimeline("svetlanaK") == true);
  CHECK(nw.printTimeline("steven1") == true);
}
TEST_CASE("Task D: Only user have posts"){
  CHECK(nw.printTimeline("nahima123") == true);
  CHECK(nw.printTimeline("steven13") == true);
}
TEST_CASE("Task D: No posts"){
  CHECK(nw.printTimeline("steven2") == false);
  CHECK(nw.printTimeline("steven3") == false);
  CHECK(nw.printTimeline("steven4") == false);
}

