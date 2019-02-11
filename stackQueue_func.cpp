// This will implement all the functions of my class

# include "sQ.h"

stack::stack(){


  head = NULL;  
  begin = NULL;


}
stackNode::stackNode(){

  entries = new email[MAX];
  for(int i = 0; i < MAX; ++i)
  {
    entries[i].user = NULL;
  }

  
  next = NULL;



}
// wrapper function for peek
char* stack::peek(){

  char * temp = new char[100];

  temp = peek_aboo(head);

  cout << "temp " << temp << endl;

  if(temp != NULL)
    return temp;

  else
    return NULL;
  
}
// finds the top of stack displays for client
char* stack::peek_aboo(stackNode * headPeek){

  if(!head)
  {
    cout << "List is empty. " << endl;
    return NULL;
  }
  if(top == 0)
  {
    return headPeek->next->entries[top + 4].user;
  }
  else if(top < MAX)
  {
    return head->entries[top-1].user;

  }


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

  if(!head) 
    return -1; // checks for head data
  

  else if(counter-1 == -1)
  {
    counter = 5;
    if(!head->next)
    {
      cout << "End of List" << endl;
      return -1;
    }
    else
    display_private(head->next);

  }

  else if(counter != -1)
  {
    cout << counter << endl;
    cout << "Email Username: " << head->entries[counter-1].user << endl;
    --counter;
    display_private(head);

  }
  
  else if(!head->next) 
    return -1; // check for end of list

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
    head->entries = new email[MAX];
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
    cout << "test " << head->entries[counter].user << endl;
    ++counter;
    begin = head;

  }
  else if(counter == MAX-1)
  {

    head->entries[counter].user = new char[strlen(userData.user)+1];
    strcpy(head->entries[counter].user, userData.user);
    cout << "test " << head->entries[counter].user << endl;

    cout << " at end of array " << endl;
    stackNode * temp;
    temp = head;
    head = new stackNode;
    head->entries = new email[MAX];
    //temp = head->next;
    head->next = temp;

    counter = 0;

  }
  top = counter;
  return 0;
}
// destructor for stack
stack::~stack(){


}
