#include<iostream>
#include<iomanip>
using namespace std;

/**
   Computes the weekday of a given date.
   @param year the year
   @param month the month (1 = January ... 12 = December)
   @param day the day of the month
   @return the weekday (0 = Sunday ... 6 = Saturday)
*/
int day_of_week(int year, int month, int day)
{
   int y = year;
   int m = month - 1;
   if (month < 3) { y--; m = m + 4; }
   return (y + y / 4 - y / 100 + y / 400
      + 3 * m + 4 - (m - m / 8) / 2 + day) % 7;
}

void days()
{
   cout << setw(3) << "Su" << setw(3) << "Mo"  << setw(3) << "Tu"  << setw(3) <<  "We"  << setw(3) <<  "Th"  << setw(3) << "Fr"  << setw(3) << "Sa" << endl;
}

void rowPrinter(int year, int month, int day)
{
   int date = 1;
   int place = day_of_week(year, month, day);
   int count = place;
   bool found = false;
   while(!found){
      int wid;
      wid = (3 * count) + 3;
      if(count == 6){
         cout << setw(wid) << date << endl;
         count = 0;
      }
      else{
         cout << setw(wid) << date;
         count++;
      }
      date++;
      found = true;
   }
      
   for(int i = date; i <= 30; i++){
      if(count == 6){
         cout << setw(3) << date << endl;
         date++;
         count = 0;
      }
      else{
         cout << setw(3) << date ;
         count++;
         date++;
      }
   }
}
string explicitMonth(int month){
    string message = "";
    switch(month){
        case 1: message += "January"; break;
        case 2: message += "Feburary"; break;
        case 3: message += "March"; break;
        case 4: message += "April"; break;
        case 5: message += "May"; break;
        case 6: message += "June"; break;
        case 7: message += "July"; break;
        case 8: message += "August"; break;
        case 9: message += "September"; break;
        case 10: message += "October"; break;
        case 11: message += "November"; break;
        case 12: message += "December"; break;
    }
    return message;
}
int main()
{
   int month;
   int year;
   cout << "month: ";
   cin >> month;
   cout << "year: ";
   cin >> year;
   cout << endl << setw(10) << explicitMonth(month) << " " << year;
   cout << endl << endl;
    
   days();
   rowPrinter(year, month, 1);
   cout << endl << endl;
   return 0;
}
