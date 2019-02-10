// This program will use two different data structures to 
// keep track of emails received from the user.  The first 
// data structure will be a linear linked list of arrays.  
// The second data structure will be a queue style circular
// linked list.



# include "sQ.h"


int main(){


  stack list;
  email temp;

  int stackCheck = 0;

  char addEmail = ' ';

  while(addEmail != 'N')
  {
    cout << "Please enter email account (e.g. person@gmail.com): ";
    temp.user = new char[100];
    cin.get(temp.user, 100);
    cin.ignore(100,'\n');
    stackCheck = list.pushInfo(temp);

    cout << "Would you like to add another email? (y/n): ";
    cin >> addEmail;
    addEmail = toupper(addEmail);
  }

  






  delete [] temp.user;

return 0;


}
