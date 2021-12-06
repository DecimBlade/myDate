/**
Ellesia Truong 026588859
Program #2 - myDate
CECS 282-Sec 04
Due Date: September 28, 2021 11:59pm
I certify that this program is my own original work. I did not copy any part of this program from any other source.
I further certify that I typed each and every line of code in this program.
*/

#include <string>
#include <iostream>
using namespace std;

#ifndef myDate_H
#define myDate_H

class myDate{
  private:
    int Month;
    int Day;
    int Year;
    
  public:
    myDate();
    myDate(int M, int D, int Y);
    void display();
    void increaseDate(int N);
    void decreaseDate(int N);
    int daysBetween(myDate D);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
};

#endif