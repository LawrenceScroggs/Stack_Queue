// This is the header file I will implement my classes and struct


# include <cctype>
# include <iostream>
# include <cstring>

using namespace std;

int const MAX = 5;


struct email{

  
  char * user;
  char * topic;
  char * body;
  char * date;

  email * next;


};
class stackNode{

  public:
  stackNode();
  email * entries;
  stackNode * next;

  private:


};
class stack{

  public:
    stack();
    //wrapper functions
    int pushInfo(email & userData); 
    int display();
    int deletePop();

    email peek();

    bool empty();

    ~stack();
    

  private:
    email peek_aboo(stackNode * head); // peeks and returns top of stack

    int display_private(stackNode * head); // displays list of arrays of emails
    int push(stackNode * & head, email & userData); // puts email into array 
    int pop(stackNode * & head); // deletes top of stack

    bool is_empty(stackNode * head);// checks if list is full

    stackNode * head;
   
    int counter = 0;
    int top = counter;

};
class queueList{

  public:
    queueList();
    ~queueList();
    int enqueue(email & userData);

  private:
    int buildQ(email *& qHead, email & userData);
    email * qHead;


};
