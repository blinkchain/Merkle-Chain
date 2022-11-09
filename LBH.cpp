#include<iostream>
#include "list.h"
#include "data.h"
using namespace std;

void print(Node* head,List l){
  while (head!=NULL)
  {
    cout<<"the data is "<<head->getData()<<endl;
    cout<<"the head is "<<l.begin()<<endl;
    cout<<"the chainroot is "<<l.chainroot()<<endl;
    head = head->next;
  }
}

void verify(List l,Stored_data d){
  if(d.getdata()==l.chainroot()){
    cout<<"not tampered"<<endl;
  }
  else{
    cout<<"tamperd"<<endl ;
  }
}

int main(){
  
  List l;
  Stored_data d("");
  l.Add_block("1");
  l.Add_block("2");
  l.Add_block("3");
  l.Add_block("4");

  Node* head = l.begin();
  d.setdata(l.chainroot());
  l.Add_block("4");
  
  print(head,l);
  verify(l,d);

   return 0;

}

