// This will implement all the functions of my class

# include "sQ.h"
queueList::queueList(){

  qHead = NULL;

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
// wrapper for buildQ
int queueList::enqueue(email & userData){

  //buildQ(qHead,userData);

  return 0;

}
// wrapper for is_empty
bool stack::empty(){

  bool temp = false;

  temp = is_empty(head);

  if(temp == true)
    return true;

  else
    return false;

}
// checks if list is empty
bool stack::is_empty(stackNode * head){

  if(!head)
    return true;

  else
    return false;
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
  else if(top == 0)
  {
    if(!head->next)
    {
      head = NULL;
      return -1;
    }
    stackNode * hold = head->next;
    head->next->entries[top + 4].user = NULL;
    head->next->entries[top + 4].body = NULL;
    head->next->entries[top + 4].topic = NULL;
    head->next->entries[top + 4].date = NULL;
    delete [] head;
    head = hold;
    if(head)
    {
      top = MAX-1;
      counter = MAX;
    }
    return 1;
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
// wrapper function for peek
email stack::peek(){


  email temp;

  temp = peek_aboo(head);

  return temp;



  
}
// finds the top of stack displays for client
email stack::peek_aboo(stackNode * headPeek){


  if(!head)
  {
    cout << "List is empty. " << endl;
    
  }
  if(top == 0)
  {
    cout << "Email Username: " << head->next->entries[top+4].user << endl;
    cout << "Topic: " << head->next->entries[top+4].topic << endl;
    cout << "Body: " << head->next->entries[top+4].body << endl;
    cout << "Date: " << head->next->entries[top+4].date << endl;

    return head->next->entries[top+4];
  }
  else if(top < MAX)
  {
    cout << "Email Username: " << head->entries[top-1].user << endl;
    cout << "Topic: " << head->entries[top-1].topic << endl;
    cout << "Body: " << head->entries[top-1].body << endl;
    cout << "Date: " << head->entries[top-1].date << endl;

    return head->entries[top-1];

  }


}
// wrapper function for display_private
int stack::display(){

  int dispCheck = 0;

  dispCheck = display_private(head);

  if(dispCheck == -1)
  {
    cout << "Emails Empty" << endl;
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
