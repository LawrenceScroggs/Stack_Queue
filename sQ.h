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
    int pushInfo(email & userData);
    int peek();
    int display();
    int deletePop();

    ~stack();
    

  private:
    int peek_aboo();
    int display_private(stackNode * head, email * userData);
    int push(stackNode * & head, email & userData);
    int pop(stackNode * & head, email * & entries);

    stackNode * head;
    int counter = 0;

};
class queue{

  public:

  private:


};
