//
//  main.cpp
//  PRG-5-19-Budget-Analysis
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//
//  Write a program that asks the user to enter the amount that he or she has budgeted for
//  a month. A loop should then prompt the user to enter each of his or her expenses for
//  the month and keep a running total. When the loop finishes, the program should display
//  the amount that the user is over or under budget.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float fltBudgetMonth,
          fltBudgetRunningTotal = 0, // Initialize counter
          fltBudgetItem,
          fltBudgetDifference;
    
    char chrContinue;
    
    // Set precision for dollar amount
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "Please enter your monthly budget:\n";
    cin >> fltBudgetMonth;
    
    while(fltBudgetMonth <= 0 || fltBudgetMonth >= 10000)
    {
        cout << "Please enter a positive integer value less than $10,000:\n";
        cin >> fltBudgetMonth;
    }
    
    do
    {
        cout << "Please enter this expense's cost:\n";
        cin >> fltBudgetItem;
        
        while(!cin || fltBudgetItem < 0.0f || fltBudgetItem > 100.0f)
        {
            cout << "Please enter a positive value less than $100.00 for the expense cost:\n";
            cin.clear();
            cin.ignore();
            cin >> fltBudgetItem;
        }
        
        fltBudgetRunningTotal += fltBudgetItem;
        
        cout << "Do you have another item to enter?\n"
             << "Enter N to exit and view total budget:\n";
        cin >> chrContinue;
        
    } while(chrContinue != 'n' && chrContinue != 'N');
    
    cout << "With a monthly budget of $" << fltBudgetMonth << endl
         << "and expenses totalling $" << fltBudgetRunningTotal << endl;
    
    fltBudgetDifference = fltBudgetMonth - fltBudgetRunningTotal;
    
    if(fltBudgetDifference > 0)
    {
        cout << "You have $" << fltBudgetDifference << " remaining in your account.\n";
    }
    else
    {
        cout << "You are $" << fltBudgetDifference << " overdrawn.\n";
    }
    
    return 0;
}



