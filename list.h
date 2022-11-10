#include <stddef.h>
#include<string.h>
#include "sha256.cpp"


class List;    


class Node{                            // block disign
    std::string Node_root;            //data in the node
public:
    Node* next;                      // the add of the next node
    Node(std::string Nr):Node_root(Nr),next(NULL){};
    
    std::string getData(){              
        return Node_root; 
    }

    friend class List;
};





class Root_block     //root block
{
std::string Chain_root;               //root of the chain
public:
Node* head;                   // the add of the head node
Root_block(std::string Cr):Chain_root(Cr),head(NULL){};

friend class List;
};



class List{                                 //block actions
    Node* head;                            // add of the head node
    Node* tail;                           // add of the tail node
    Root_block r;                        //obj of the root block
private:

   std::string genroot(Node* h){        //genrate chain root
   std::string i;
    while (h!=NULL)
    {
        i = sha256(i+h->getData());
        h = h->next;
    }
    return i;
   }

public:

   List():head(NULL),tail(NULL),r(""){}

   Node* begin(){                   //getter for head 
    return head;
   }

    std::string chainroot(){                 //getter for root
    return r.Chain_root;
   }
   
   void Add_block(std::string data){        // adding new data in the chain
     if(head==NULL){
        Node* n=new Node(data);
        r.Chain_root = data;
        head = tail = n;
        r.head = head;    
     }
     else{
        Node* n = new Node(data);
        tail->next = n;
        tail = n;  
        r.Chain_root = genroot(head);
     }
   }


};






  

