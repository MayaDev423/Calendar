#include <iostream>
#include <cmath>
#include <string>


using namespace std;

void display();
bool isLeapYear(int year);
int numDays(int year, int month);
int monthKeyValue(int month);
int firstDay(int Y, int m);
void printMonth(int year, int month);
void printYear(int year);



void display(){ //asks user what year and month it would like to see, uses that info to display corresponding calendar
    string input;
    cout <<"Would you like a year or month calendar? (y for year, m for month): ";
    cin >> input;

    if (input == "m"){
            int year;
            int month;
            cout << "Please enter the year you would like to see: ";
            cin >> year;
            cout << "Please enter the number value of the month you would like to see (January is 1): ";
            cin >> month;
        
            cout <<" "<<endl;
            printMonth(year, month);
    }
    else if (input == "y"){
        int year;
        cout <<"Please enter the year you would like to see: ";
        cin >> year;
        printYear(year);
    }

    else{
        cout <<"Invalid Input" << endl;
    }
    
   
  


}

bool isLeapYear(int year){ //checks if year is leap year
   
    if (year % 4 == 0 && year % 100 != 0){
        return true;
    }
    else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0){
        return true;
    }
    else{
        return false;
    }
}

int numDays(int year, int month){ //checks how many days are in each month - checks if year is a leapyear

   

    bool check = isLeapYear(year);
    int febDays = 28;
    if (check == true){
        febDays = 29;
    }
  

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    }
    else if (month == 2){
        return febDays;
    }
    else{
        return 30;
    }

    
    
}
int monthKeyValue(int month){  //checks key value of month
    if (month == 1 || month == 5){
        return 0;
    }
    else if (month == 2 || month == 6){
        return 3;
    }
    else if (month == 3 || month == 11){
        return 2;
    }
    else if (month == 4 || month == 7){
        return 5;
    }
    else if (month == 8){
        return 1;
    }
    
    else if (month == 9 || 12){
        return 4;
    }
    else if (month == 10){
        return 6;
    }



}



int firstDay(int Y, int m, int k){

   
    int g;
    int e = monthKeyValue(m);
    int W;
    int f;
    int C;
    

    //count jan and feb as months of preceding year

    if (m == 1 || m == 2){ 
        C = (Y-1)/100;
        g = (Y-1)-100*C;
    }
    
    else{
        C = Y/100;
        g = Y-100*C;
    }

    //find f
    if (C%4 == 0){ 
        f = 0; 
    } 
    else if (C%4 == 1){
        f = 5;
    }
    else if (C%4 == 2){
        f = 3;
    }
    else if (C%4 == 3){
        f = 1;
    }

    //combine to make algorithm
    W = (k+ e + f + g + floor(g/4));
    W = abs(W);
    W = fmod(W, 7);

   

    return W;

}



void printMonth(int year, int month){ 
    int days = numDays(year, month);
    int first = firstDay(year, month, 1);
    int index = month - 1;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    if (month >= 13 || month <= 0 || year < 0){
        cout << "That is not a valid input"<< endl;
        display();
    }
    else{

       //check if week has passed, check if 7 days have passed
     //decide amount of spacing depending on current day
  

                                                                
    cout <<months[index]<< " " << year << endl
    <<" S  M Tu  W Th  F  S"<< " " << endl;

      for (int i = 0; i < first; i++){ //print spaces depending on the starting day 
         cout <<"   ";
      }
          for (int i = 1; i <= 7-first; i++){ //print numbers to fill out the rest of the row 
           cout << " " << i << " ";
          }
          cout << " " << endl; //space for next row
          cout << " ";

        //print 7 numbers per line
        int count = 0;
         for (int i = (7-first) + 1; i <= days; i++){
           count++;
           if (i <= 8){
             cout << i << "  ";
           }
           else if (i == 9 && firstDay(year, month, 9) == 0){ //between 9 and 10 there is 1 less space so I made this case seperate
            cout << " " << i << " ";                          //spacing is different if 9 is on sunday
           }
           else if (i == 9){
            cout << i << " ";
           }
           else if (i > 9){  
            cout << i << " ";
           }
           
           if (count == 7){ //new line every 7 numbers
            cout << " " << endl;
            count = 0;
           }


         } cout << " " << endl;
       
   
    }
}

void printYear(int year){
    for (int i = 1; i <= 12; i++){
        printMonth(year, i);
    }
}






int main(){

    display();


    return 0;
}