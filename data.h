#include <stddef.h>
#include<string.h>
#include<iostream>
class Stored_data{
  
  std::string chainroot;
public:
  Stored_data(std::string root):chainroot(root){}
  std::string getdata(){
    return chainroot;
  }
  void setdata(std::string data){
    chainroot = data;
  }

};
