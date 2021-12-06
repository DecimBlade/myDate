/**
Ellesia Truong 026588859
Program #2 - myDate
CECS 282-Sec 04
Due Date: September 28, 2021 11:59pm
I certify that this program is my own original work. I did not copy any part of this program from any other source.
I further certify that I typed each and every line of code in this program.
*/

#include <iostream>
#include <string>
#include "myDate.h"
using namespace std;

// Computes the Julian date given the Gregorian Calender Date
int Greg2Julian (int MONTH, int DAY, int YEAR){                                          
  int I,J,K; 

  I = YEAR;                                                                  
  J = MONTH;                                                                 
  K = DAY;  

  int JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;

  return JD;                              
}

// Computes the Gregorian Calender Date given the Julien Date
void Julian2Greg (int &jd, int &month, int &day, int &year){
  int I,J,K,L,N; 

  L = jd+68569;                                                      
  N = 4*L/146097;                                                    
  L = L-(146097*N+3)/4;                                              
  I = 4000*(L+1)/1461001;                                             
  L = L-1461*I/4+31;                                                 
  J = 80*L/2447;                                                      
  K = L-2447*J/80;                                                   
  L = J/11;                                                        
  J = J+2-12*L;                                                     
  I = 100*(N-49)+I+L;

  year = I;                                                          
  month = J;                                                         
  day = K;
}

// Default Constructor (setting the date to May 11, 1959)
myDate::myDate(){
  Month = 5;
  Day = 11;
  Year = 1959;
}

// Overloaded Constructor
myDate::myDate(int M, int D, int Y){
  // Checks if there is a non existing Month or Day 
  // Had to place this check because of the Bogus Date
  if(M < 1 || M > 12 || D < 1 || D > 31){
    Month = 5;
    Day = 11;
    Year = 1959;
  }

  // If not, then sets the M,D,Y to the user's input
  else{
  Month = M;
  Day = D;
  Year = Y;
  }
}

// Display the date like: May 11, 1959
void myDate::display(){
  string monthName;
  
  if(Month == 1){
    monthName = "January";
  }
  else if(Month == 2){
    monthName = "Febuary";
  }
  else if(Month == 3){
    monthName = "March";
  }
  else if(Month == 4){  
    monthName = "April";
  }
  else if(Month == 5){
    monthName = "May";
  }
  else if(Month == 6){
    monthName = "June";
  }
  else if(Month == 7){
    monthName = "July";
  }
  else if(Month == 8){
    monthName = "August";
  }
  else if(Month == 9){
    monthName = "September";
  }
  else if(Month == 10){
    monthName = "October";
  }
  else if(Month == 11){
    monthName = "November";
  }
  else if(Month == 12){
    monthName = "December";
  }
  else{
    monthName = "NO MONTH NAME ERROR date doesn't exist ";
  }
  cout << monthName << " " << Day << ", " << Year;
}

// Increment the date by N days
void myDate::increaseDate(int N){
  int JD = Greg2Julian(Month, Day, Year);
  JD = JD + N;
  Julian2Greg(JD, Month, Day, Year);

}

// Decrement the date by N days
void myDate::decreaseDate(int N){
  int JD = Greg2Julian(Month, Day, Year);
  JD = JD - N;
  Julian2Greg(JD, Month, Day, Year);
}

// return the number of days between this date and the date D
// Positive int = future date, Negative int = past date
int myDate::daysBetween(myDate D){
  int D1, D2, diff;
  D1 = Greg2Julian(Month, Day, Year);
  D2 = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());

  diff = D2 - D1;
  return diff;
}

// Return the month in integer form
int myDate::getMonth(){
  return Month; 
}

// Return the day of the month
int myDate::getDay(){
  return Day;
}

// Return the year
int myDate::getYear(){
  return Year;
}

// return the number of days since the current year began
int myDate::dayOfYear(){
  int currDate, begDate, diff;
  // Start in the beginning of the year
  begDate = Greg2Julian(1, 0, Year);
  currDate = Greg2Julian(Month, Day, Year);

  diff = currDate - begDate;
  return diff;
}

// returns the day of the week
string myDate::dayName(){
  int JD, numDay;
  string dayName;
  JD = Greg2Julian(Month, Day, Year);
  numDay = JD % 7;

  if(numDay == 0){
    dayName = "Monday";
  }
  else if(numDay == 1){
    dayName = "Tuesday";
  }
  else if(numDay == 2){
    dayName = "Wednesday";
  }
  else if(numDay == 3){
    dayName = "Thursday";
  }
  else if(numDay == 4){
    dayName = "Friday";
  }
  else if(numDay == 5){
    dayName = "Saturday";
  }
  else if(numDay == 6){
    dayName = "Sunday";
  }
  return dayName;
}