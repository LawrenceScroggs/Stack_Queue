// This is the header file I will implement my classes and struct


# include <cctype>
# include <iostream>
# include <cstring>

using namespace std;

int const MAX = 5;


struct email{


  email();

  char * user;
  char * topic;
  char * body;
  char * date;

  email * next;

  ~email();


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
    int peek();

    email get();

    bool empty(email & head);

    ~stack();
    

  private:
    email getter(stackNode * head); // peeks and returns top of stack

    int peek_aboo(stackNode * head); // peeks and returns top of stack info
    int display_private(stackNode * head); // displays list of arrays of emails
    int push(stackNode * & head, email & userData); // puts email into array 
    int pop(stackNode * & head); // deletes top of stack

    bool is_empty(email & temp);// checks if list is full

    stackNode * head;
   
    int counter = 0;
    int top = counter;

};
class queueList{

  public:
    queueList();
    ~queueList();

    //wrapper functions
    int enqueue(email & userData);
    int displayQ();
    int peekQ();
    int dequeue();

  private:
    int dequeue_private(email *& rear); // grabs last input and deletes
    int peekQ_private(email * rear); //grabs rear of list and displays
    int buildQ(email *& qHead, email & userData); // builds CLL
    int displayQ_private(email * current, email * rear); // displays CLL

    email * rear;


};
