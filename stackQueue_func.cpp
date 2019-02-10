// This will implement all the functions of my class

# include "sQ.h"

stack::stack(){


  head = NULL;  


}
stackNode::stackNode(){

  entries = new email[MAX];
  for(int i = 0; i < MAX; ++i)
    entries[i].user = NULL;

  
  next = NULL;



}
// wrapper function for display_private
int stack::display(){

  int dispCheck = 0;

  dispCheck = display_private(head,userData);

  if(dispCheck == -1)
    cout << "No Emails Available" << endl;

  else return 1;

}
// display function to show the full list of emails
int stack::display_private(stackNode * head, email * userData){

  if(!head) return -1;
  if(counter == 0)
  {
    cout << "Email Username: " << entries[counter].user << endl;
    counter = 5;
    display_private(head->next);

  }

  if(counter != 0)
  {
    cout << "Email Username: " << entries[counter].user << endl;
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


  if(!head)
  { 
    head = new stackNode;
    head->entries[counter].user = new char[strlen(userData.user)+1];
    strcpy(head->entries[counter].user, userData.user);
    ++counter;
    head->next = NULL;
  }
  if(head && counter < MAX)
  {
    head->entries[counter].user = new char[strlen(userData.user)+1];
    ++counter;

  }
  if(counter == MAX)
  {
    counter = 0;
    stackNode * temp = new stackNode;
    temp = head;
    head = head->next;

    head->entries[counter].user = new char[strlen(userData.user)+1];
    strcpy(head->entries[counter].user, userData.user);
    ++counter;

  }


    


}
// destructor for stack
stack::~stack(){


}
