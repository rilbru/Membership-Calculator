#include <iostream>
#include <iomanip>
using namespace std;

// Constants for menu choices
const int ADULT_CHOICE = 1,
            CHILD_CHOICE = 2,
            SENIOR_CHOICE = 3,
            QUIT_CHOICE = 4;

// Constants for membership rates
const double ADULT = 40.0,
            CHILD = 20.0,
            SENIOR = 30.0;

// Add function prototypes here
int MenuFunction();
int MonthsFunction (int choice);
void ChargesFunction(int choice, int months);

int main()
{  
   // Variables
   int choice = 0;         // Menu choice
   int months = 0;         // Number of months

   cout << fixed << showpoint << setprecision(2);
   
   do 
   {
   
   choice = MenuFunction();
   months = MonthsFunction(choice);
   ChargesFunction(choice, months);
   
   } while (choice != QUIT_CHOICE);

   return 0;
}

int MenuFunction()  {
  int choice = 0;
  // Display the menu.
  cout << "\n\t\tHealth Club Membership Menu\n\n"
        << "1. Standard Adult Membership\n"
        << "2. Child Membership\n"
        << "3. Senior Citizen Membership\n"
        << "4. Quit the Program\n\n"
        << "Enter your choice: ";
  cin >> choice;
  while (choice < ADULT_CHOICE || choice > QUIT_CHOICE)
  {
      cout << "Please enter a valid menu choice: ";
      cin >> choice;
  }
  return choice;
}

int MonthsFunction (int choice)  {
  int months = 0;
  if (choice != QUIT_CHOICE)
  {
    // Get the number of months.
    cout << "For how many months? ";
    cin >> months;

    // Validate the number of months.
    while (months < 0 || months > 60)
    {
      cout << "Please enter months between 0 and 60: ";
      cin >> months;
    }
  }
  return months;
}

void ChargesFunction(int choice, int months) {
if (choice != QUIT_CHOICE){
  double charges = 0.0;
  // Respond to the user's menu selection.
  switch (choice)
  {
    case ADULT_CHOICE:
      charges = months * ADULT;
      break;
    case CHILD_CHOICE:
      charges = months * CHILD;
      break;
    case SENIOR_CHOICE:
      charges = months * SENIOR;
      break;
  }
         
  // Display the monthly charges.
  cout << "The total charges are $"
        << charges << endl;
}
  
}