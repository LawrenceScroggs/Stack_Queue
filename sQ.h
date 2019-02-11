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

  qNode * next;


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
    char * peek();
    int display();
    int deletePop();

    ~stack();
    

  private:
    char* peek_aboo(stackNode * head); // peeks and returns top of stack
    int display_private(stackNode * head); // displays list of arrays of emails
    int push(stackNode * & head, email & userData); // puts email into array 
    int pop(stackNode * & head, email * & entries); // deletes top of stack

    stackNode * head;
    int counter = 0;
    int top = counter;

};
class queue{

  public:

  private:


};
