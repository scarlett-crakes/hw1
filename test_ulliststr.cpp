#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr MyTester;

  MyTester.push_back("hello");
  //MyTester.push_back("world");

  /*std::cout << MyTester.get(0) << std::endl;
  std::cout << MyTester.get(1) << std::endl;*/

  //MyTester.push_front("goodbye");
  //MyTester.push_front("said");

  //std::cout << MyTester.get(0) << std::endl;
  //std::cout << MyTester.get(1) << std::endl;
  //std::cout << MyTester.front() << std::endl;
  //std::cout << MyTester.back() << std::endl;
  //std::cout << MyTester.get(2) << std::endl;
  //std::cout << MyTester.get(3) << std::endl;

  MyTester.pop_front();
  //std::cout << MyTester.front() << std::endl;
  //std::cout << MyTester.back() << std::endl;
  //std::cout << MyTester.size() << std::endl;
  //std::cout << MyTester.get(2) << std::endl;
  //std::cout << MyTester.get(1) << std::endl;
  ULListStr list;

	
  MyTester.push_back("foo");
  MyTester.push_back("BAR");
  MyTester.push_back("baz");

  std::cout << MyTester.get(0) << std::endl;
  std::cout << MyTester.get(1) << std::endl;
  std::cout << MyTester.get(2) << std::endl;

  MyTester.pop_front();

  std::cout << MyTester.get(0) << std::endl;
  std::cout << MyTester.get(1) << std::endl;

  //EXPECT_EQ(0, list.size());
  //EXPECT_EQ(true, list.empty());
	
}
