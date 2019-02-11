// This program will use two different data structures to 
// keep track of emails received from the user.  The first 
// data structure will be a linear linked list of arrays.  
// The second data structure will be a queue style circular
// linked list.



# include "sQ.h"


int main(){


  stack list;
  email temp;
  email temp2;
  stackNode create;
  queueList full_list;

  int stackCheck = 0;
  int popCheck = 0;

  char addEmail = ' ';
  char yesNo = ' ';

  bool emptyCheck = false;

  while(addEmail != 'N')
  {
    cout << "Please enter email account (e.g. person@gmail.com): ";
    temp.user = new char[100];
    cin.get(temp.user, 100);
    cin.ignore(100,'\n');

    cout << "Please enter the topic: ";
    temp.topic = new char[100];
    cin.get(temp.topic, 100);
    cin.ignore(100,'\n');

    cout << "Please enter the body of email: ";
    temp.body = new char[500];
    cin.get(temp.body, 500);
    cin.ignore(500, '\n');

    cout << "Please enter date of email: ";
    temp.date = new char[100];
    cin.get(temp.date, 100);
    cin.ignore(100,'\n');

    stackCheck = list.pushInfo(temp);

    cout << "Would you like to add another email? (y/n): ";
    cin >> addEmail;
    cin.ignore(100,'\n');
    addEmail = toupper(addEmail);
  }

  cout << "Would you like to display your email list? (y/n): ";
  cin >> yesNo;
  cin.ignore(100,'\n');
  yesNo = toupper(yesNo);

  if(yesNo == 'Y')
    list.display();

  yesNo = ' ';

  cout << "You want to peek at the top. (y/n): ";
  cin >> yesNo;
  cin.ignore(100,'\n');
  yesNo = toupper(yesNo);

  if(yesNo == 'Y')
    temp = list.peek();

  yesNo = ' ';

  while(yesNo != 'N')
  {
    cout << "Would you like to pop/delete the top of stack? (y/n): ";
    cin >> yesNo;
    cin.ignore(100,'\n');
    yesNo = toupper(yesNo);
    if(yesNo == 'Y')
    {
      popCheck = list.deletePop();
      if(popCheck == 1)
        cout << "Deleted Succesfully" << endl;
      else
        cout << "List is Empty" << endl << endl;
    }
  }

  list.display();

  yesNo = ' ';

  cout << "Now it is time to go through your list and decide which emails to keep. " << endl;
  while(emptyCheck != true)
  {
    if(list.display() == -1)
    {
      cout << "No Emails in List. " << endl;
      emptyCheck = true;
    }
    temp = list.peek();
    cout << "Would you like to keep this email? (y/n): ";
    cin >> yesNo;
    yesNo = toupper(yesNo);
    if(yesNo == 'Y')
    {
      full_list.enqueue(temp);
      list.deletePop();
    }
    else
      list.deletePop();

    emptyCheck = list.empty();

  }

    

      


  




  delete [] temp.user;

return 0;


}
