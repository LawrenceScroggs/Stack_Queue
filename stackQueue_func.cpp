// This will implement all the functions of my class

# include "sQ.h"


email::email(){

  user = NULL;
  topic = NULL;
  body = NULL;
  date = NULL;

  next = NULL;
}
queueList::queueList(){

  rear = NULL;

}
stack::stack(){


  head = NULL;  


}
stackNode::stackNode(){

  entries = new email[MAX];
  for(int i = 0; i < MAX; ++i)
  {
    entries[i].user = NULL;
    entries[i].topic = NULL;
    entries[i].body = NULL;
    entries[i].date = NULL;
  }

  
  next = NULL;



}
// wrapper for peekQ_private
int queueList::peekQ(){

  int check = 0;

  check = peekQ_private(rear);

  if(check == 1)
    return 0;

  else
  {
    cout << "List is empty" << endl;
    return -1;
  }

}
// checks for rear of list and displays
int queueList::peekQ_private(email * rear){

  if(!rear) return -1;

  else
  {
    cout << "Email Username: " << rear->next->user << endl;
    return 1;
  }
}
// wrapper for displayQ_private()
int queueList::displayQ(){

  int temp = 0;

  email * current = rear->next; // holds the beginning of list

  temp = displayQ_private(current,rear);

  if(temp == -1)
  {
    cout << "List is Empty nothing to Display" << endl;
    return -1;
  }
  else
    return 1;

}
int queueList::displayQ_private(email * current,email * rear){

  if(!rear)
    return -1;
  else if(current == rear) // it is at beginning of list
  {
    cout << "tetst 1" << endl;
    cout << "Email Username: " << current->user << endl;
    return 1;
  }
  else if(current != rear)
  {
    cout << "test 2" << endl;
    cout << "Email Username: " << current->user << endl;
    displayQ_private(current->next,rear);
  }


}
// wrapper for buildQ
int queueList::enqueue(email & userData){

  buildQ(rear,userData);

  return 0;

}
// builds CLL from previous data
int queueList::buildQ(email *& rear, email & userData){

  if(!rear)
  {
    cout << "build 1" << endl;
    cout << "user data: " << userData.user << endl;
    rear = new email;
    rear->user = new char[strlen(userData.user)+1];
    strcpy(rear->user,userData.user);
    cout << "list data: " << rear->user << endl;
    rear->next = rear;

    return 2;
  }
  else
  {
    cout << "build 2" << endl;
    cout << "user data: " << userData.user << endl;
    email * hold = rear->next;
    rear->next = new email;
    rear->next->user = new char[strlen(userData.user)+1];
    strcpy(rear->next->user, userData.user);
    cout << "list data: " << rear->next->user << endl;
    

    rear = rear->next;
    rear->next = hold;
  

    return 1;

  }


}
// wrapper for pop function
int stack::deletePop(){

  int temp = 0;

  temp = pop(head);

  if(temp == 1)
    return 1;

  else return -1;

}
// deletes top of stack
int stack::pop(stackNode *& head){


  if(!head)
  {
    return -1;
  }
  if(top == 0 && !head->next)
  {
    cout << "in here now";
    return -1;
  }
  else if(top == 0)
  {
    stackNode * hold = head->next;
    head->next->entries[top + 4].user = NULL;
    head->next->entries[top + 4].body = NULL;
    head->next->entries[top + 4].topic = NULL;
    head->next->entries[top + 4].date = NULL;
    delete [] head;
    head = hold;
    if(head)
    {
      cout << "test 1" << endl;
      top = MAX-1;
      counter = MAX;
      return 1;
    }
    else
    {
      cout << "test 2" << endl;
      head = NULL;
      return -1;
    }
  }
  else if(top < MAX)
  {
    head->entries[top-1].user = NULL;
    head->entries[top-1].topic = NULL;
    head->entries[top-1].body = NULL;
    head->entries[top-1].date = NULL;
    --top;
    counter = top;
    return 1;
  }


}
// wrapper function for getter
email stack::get(){


  email temp;

  temp = getter(head);

  return temp; 
}
// gets the top of stack displays for client
email stack::getter(stackNode * headPeek){


  if(!head)
  {
    cout << "List is empty. " << endl;
    
  }
  if(top == 0)
  {
/*    cout << "Email Username: " << head->next->entries[top+4].user << endl;
    cout << "Topic: " << head->next->entries[top+4].topic << endl;
    cout << "Body: " << head->next->entries[top+4].body << endl;
    cout << "Date: " << head->next->entries[top+4].date << endl;
*/
    counter = MAX;

    return head->next->entries[top+4];
  }
  else if(top < MAX)
  {
/*    cout << "Email Username: " << head->entries[top-1].user << endl;
    cout << "Topic: " << head->entries[top-1].topic << endl;
    cout << "Body: " << head->entries[top-1].body << endl;
    cout << "Date: " << head->entries[top-1].date << endl;
*/
    counter = top;
    cout << counter << endl;
    

    return head->entries[top-1];

  }


}
int stack::peek(){

  int check = 0;

  check = peek_aboo(head);

  if(check == 1)
    return 1;

  else return -1;

}
int stack::peek_aboo(stackNode * headPeek){


  if(!head)
  {
    cout << "List is empty. " << endl;
    return -1;
    
  }
  if(top == 0)
  {
    if(!head->next)
    {
      cout << "in here bro" << endl;
      return -1;
    }
    cout << "Email Username: " << head->next->entries[top+4].user << endl;
    cout << "Topic: " << head->next->entries[top+4].topic << endl;
    cout << "Body: " << head->next->entries[top+4].body << endl;
    cout << "Date: " << head->next->entries[top+4].date << endl;

    counter = MAX;

    return 1;
  }
  else if(top < MAX)
  {
    cout << "Email Username: " << head->entries[top-1].user << endl;
    cout << "Topic: " << head->entries[top-1].topic << endl;
    cout << "Body: " << head->entries[top-1].body << endl;
    cout << "Date: " << head->entries[top-1].date << endl;

    counter = top;
    cout << counter << endl;
    

    return 1;

  }

}
// wrapper function for display_private
int stack::display(){

  int dispCheck = 0;

  dispCheck = display_private(head);

  if(dispCheck == -1)
  {
    counter = top;
    return -1;
  }

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
    cout << "Topic: " << head->entries[counter-1].topic << endl;
    cout << "Body: " << head->entries[counter-1].body << endl;
    cout << "Date: " << head->entries[counter-1].date << endl;
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

    head->entries[counter].user = new char[strlen(userData.user)+1];
    strcpy(head->entries[counter].user, userData.user);

    head->entries[counter].topic = new char[strlen(userData.topic)+1];
    strcpy(head->entries[counter].topic, userData.topic);

    head->entries[counter].body = new char[strlen(userData.body)+1];
    strcpy(head->entries[counter].body, userData.body);

    head->entries[counter].date = new char[strlen(userData.date)+1];
    strcpy(head->entries[counter].date, userData.date);

    cout << "test " << head->entries[counter].user << endl;
    ++counter;
    head->next = NULL;
  }
  else if(counter <  MAX-1)
  {
    cout << " in the middle " << endl;
    head->entries[counter].user = new char[strlen(userData.user)+1];
    strcpy(head->entries[counter].user, userData.user);

    head->entries[counter].topic = new char[strlen(userData.topic)+1];
    strcpy(head->entries[counter].topic, userData.topic);

    head->entries[counter].body = new char[strlen(userData.body)+1];
    strcpy(head->entries[counter].body, userData.body);

    head->entries[counter].date = new char[strlen(userData.date)+1];
    strcpy(head->entries[counter].date, userData.date);

    cout << "test " << head->entries[counter].user << endl;
    ++counter;

  }
  else if(counter == MAX-1)
  {

    head->entries[counter].user = new char[strlen(userData.user)+1];
    strcpy(head->entries[counter].user, userData.user);

    head->entries[counter].topic = new char[strlen(userData.topic)+1];
    strcpy(head->entries[counter].topic, userData.topic);

    head->entries[counter].body = new char[strlen(userData.body)+1];
    strcpy(head->entries[counter].body, userData.body);

    head->entries[counter].date = new char[strlen(userData.date)+1];
    strcpy(head->entries[counter].date, userData.date);


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
queueList::~queueList(){

}
email::~email(){

}
