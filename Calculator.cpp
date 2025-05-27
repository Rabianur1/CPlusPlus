#include <iostream>
using namespace std;

int main()
{ int operation; 
 double num1, num2;

 while (true) {
   cout << "**** MY MENU ****\n";
   cout << "1. Addition\n";
   cout << "2. Subtraction\n";
   cout << "3. Division\n";
   cout << "4. Multiplication\n";
   cout << "5. Modulo\n";
   cout << "6. Exit\n";
   cout << "Enter your choice: ";
   cin >> operation;

   if (operation == 6){
     cout << "Thanks. Goodbye!\n";
     break;
   }
   
   cout << "Enter two integers: ";
   cin >> num1 >> num2;

   if (operation == 1) {
     cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
   }
   else if (operation == 2) {
     cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
   }
   else if (operation == 3) {
     if (num2 != 0) {
         cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
     } else {
         cout << "Error! Numbers cannot be divided by zero.\n";
     }
   }
   else if (operation == 4) {
     cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
   }
   else if (operation == 5) {
     if (num2 != 0) {
         cout << "Result: " << num1 << " % " << num2 << " = " << (int(num1) % int(num2)) << endl; //Numbers must be integers to receive a mode. 
     } else {
         cout << "Error! Modulo by zero is undefined.\n";
     }
   }
   else {
     cout << "Please select the specified options.\n"; //From 1 to 6
   }
    cout << "***********************\n\n"; 
 }
 return 0;
}