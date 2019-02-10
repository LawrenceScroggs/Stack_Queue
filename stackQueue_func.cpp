// This will implement all the functions of my class

# include "sQ.h"

stack::stack(){


  head = NULL;  


}
stackNode::stackNode(){

  entries = new email[MAX];
  for(int i = 0; i < MAX; ++i)
  {
    entries[i].user = NULL;
  }

  
  next = NULL;



}
// wrapper function for display_private
int stack::display(){

  int dispCheck = 0;

  dispCheck = display_private(head);

  if(dispCheck == -1)
    cout << "No More Emails Available" << endl;

  else return 1;

}
// display function to show the full list of emails
int stack::display_private(stackNode * head){

  cout << "counter: " << counter << "test: " << head->entries[counter-1].user << endl;
  if(!head) return -1;
  if(counter == 0)
  {
    cout << "Email Username: " << head->entries[counter].user << endl;
    counter = 5;
    display_private(head->next);
    cout << endl << endl;

  }

  if(counter != 0)
  {
    cout << "Email Username: " << head->entries[counter-1].user << endl;
    --counter;
    display_private(head);

  }

}
// this function will get the email info and pass to array
int stack::pushInfo(email & userData){

 
  push(head, userData);

  return 0;



}
int stack::push(stackNode * & head, email & userData){

  cout << counter << endl;
  if(!head)
  { 
    head = new stackNode;
    //head->entries = new email[MAX];
    cout << MAX << " & " << counter << endl;
    head->entries[counter].user = new char[strlen(userData.user)+1];
    strcpy(head->entries[counter].user, userData.user);
    cout << "test " << head->entries[counter].user << endl;
    ++counter;
    head->next = NULL;
  }
  else if(counter <  MAX-1)
  {
    cout << " in the middle " << endl;
    head->entries[counter].user = new char[strlen(userData.user)+1];
    strcpy(head->entries[counter].user, userData.user);
    ++counter;

  }
  else if(counter == MAX-1)
  {
    cout << " at end of array " << endl;
    stackNode * temp;
    temp = head;
    head = new stackNode;
    temp = head->next;
    head->next = temp;

    head->entries[counter].user = new char[strlen(userData.user)+1];
    strcpy(head->entries[counter].user, userData.user);
    counter = 0;

  }
}
// destructor for stack
stack::~stack(){


}
