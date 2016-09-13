//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  main.cpp                                                                    *
//*                                                                                                   *
//*   PROGRAM AUTHOR:     __________________________________________                                  *
//*                                     Alexandru Andrei                                              *
//*                                                                                                   *
//*                                                                                                   *
//*****************************************************************************************************

//***********************************  PROGRAM DESCRIPTION  *******************************************
//*                                                                                                   *
//*   PROCESS: This program is designed to read a list of data consisting of the car type, entry      *
//*   time and exit time and then print out a ticket with the price of the parking fee.               *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     : ReadData – reads the car type, entry and exit time of the vehicle parked         *
//*                  calculateHours – calculates the number of hours of a vehicle parked              *
//*                  calculateRate – calculates the parking fee based on the hours and type of car    *
//*                  printTicket – prints the parking ticket with all the informations                *
//*                                                                                                   *
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void ReadData(ifstream & infile, char & CarType, int & entryTime, int & exitTime);
void printTicket(ofstream & outfile,char & CarType,int & entryTime,int & exitTime,float & rate,int & hours);
int calculateHours( int & entryTime, int & exitTime);
float calculateRate(char & CarType,int & hours);
void Header(ofstream &outfile);
void Footer (ofstream &outfile);

int main(){
    char CarType;
    int entryTime;
    int exitTime;
    int hours;
    float rate;
    ifstream infile ("DATA1.txt", ios::in);
    ofstream outfile ("Result.txt", ios::out);
    
    
    // prints out the Header
    Header(outfile);
    for (int i=0; i<8; i++) // runs all the functions for all the cars
    {
        // read CarType, entryTime, exitTime
        ReadData(infile, CarType, entryTime, exitTime);
        //calculate hours based on entryTime and exitTime
        hours=calculateHours(entryTime,exitTime);
        //calculate rate based on CarType and hours
        rate=calculateRate(CarType,hours);
        //print the data
        printTicket(outfile,CarType,entryTime,exitTime,rate,hours);
    }
    
    // prints out the Footer
    Footer(outfile);
    return 0;
}

//*************************************  FUNCTION HEADER  **********************************************
void Header(ofstream &outfile)
{       // Receives – the output file
    // Task - Prints the output preamble
    // Returns - Nothing
    outfile << setw(25) << "Alexandru Andrei"<<endl;
    outfile << setw(25) << "CSC 24000"<< endl;
    outfile << setw(25) << "Section 11" << endl;
    outfile << setw(25) << "Fall 2016"<< endl;
    outfile << setw(25) << "Assignment 1"<< endl;
    outfile << setw(25) << "-------------------------" << endl;
    outfile << setw(25) << "-------------------------" << endl;
    return;
}
//************************************* END OF FUNCTION HEADER  ****************************************




//***************************************   ReadData   ************************************************
void ReadData(ifstream & infile, char & CarType, int & entryTime, int & exitTime)
{       //Receive – the function receive a file, a character and two integers
    //Task – reads the car type and the entryTimea and exitTime
    //Output – it doesn't have an output but it assignes the 3 values to the variables
    infile >> CarType;
    infile >> entryTime;
    infile >> exitTime;
}
//*****************************************************************************************************




//************************************   calculateHours   *********************************************
int calculateHours( int & entryTime, int & exitTime)
{
    //Receive – the function receive two integers: and entry time and an exit time
    //Task – calculates the number of hours of a vehicle parked
    //Output – it outputs an int which is the numbers of parked hours of the vehicle
    int hours=1;
    if ((exitTime - entryTime)%60==0)               //Check if it is a whole hour or not
        return hours = (exitTime - entryTime)/60 ;
    else
        return hours += (exitTime - entryTime)/60;
}
//*****************************************************************************************************





//************************************   calculateRate    *********************************************
float calculateRate(char & CarType,int & hours)
{
    //Receive – the function receive a character and an integer
    //Task – calculates the parking fee based on the hours and type of car
    //Output – it outputs a float  which is the price of the ticket
    
    float rate;
    if (CarType== 'C') // if the carType is a Car it calculates the rate
    {
        if(hours<= 2)// Calculate rate for the first 2 hours
        {
            rate = 0.20 * hours;
        }
        else if (hours<=5)// Calculate rate Calculate rate for the next 3
        {
            rate=(0.20*2)+(hours-2)*0.15;
        }
        else //Calculate rate Calculate rate for the remaining hours
        {
            rate=(0.20*2)+(0.15*3)+(hours-5)*0.05;
        }
    }
    else if (CarType== 'T') // if the carType is a Truck it calculates the rate
    {
        if (hours<=1) // Calculate rate for the firs hours
        {
            rate= hours*0.40;
        }
        else if(hours<=4) // Calculate rate for the next 3 hours
        {
            rate = (0.40)+ (hours-1)*0.25;
        }
        else // Calculate rate for the remaining hours
        {
            rate = (0.40)+ (3*0.25)+ (hours-4)*.10;
        }
    }
    else // if the carType is a Senior Citizen it calculates the rate
    {
        rate = hours*0.12;
    }
    return rate;
}
//*****************************************************************************************************






//************************************    printTicket     *********************************************
void printTicket(ofstream & outfile,char & CarType,int & entryTime,int & exitTime,float & rate,int & hours)
{
    //Receive – 3 ints: entryTime,exitTime and hours, 1 char: CarType,1 float: rate
    //Task – prints the parking ticket with all the informations with the right format
    //Output – it does not have an output since it is a void function
    outfile<<"The input data was:" << endl;
    outfile<<CarType<< " "<< entryTime<<" "<<exitTime << endl;
    outfile<<"" << endl;
    outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    outfile<<"$                       $" << endl;
    outfile<<"$   MISSOURI WESTERN    $" << endl;
    outfile<<"$   UNIVERSITY          $" << endl;
    outfile<<"$                       $" << endl;
    outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    outfile<<"$     PARKING FEE       $" << endl;
    outfile<<"$                       $" << endl;
    outfile<<"$  Customer             $" << endl;
    outfile <<"$  Category:  ";
    if (CarType == 'C')
        outfile << "Car       $" << endl;// correct alignment for the word Car
    else if(CarType == 'T')
        outfile << "Truck     $" << endl;// correct alignment for the word Truck
    else
        outfile << "Senior    $" << endl;// correct alignment for the word Senior
    outfile<<"$                       $" << endl;
    outfile<< "$  Time:      ";
    if (hours<10)
        outfile<<hours<<"         $"<< endl;
    else outfile<<hours<<"        $"<< endl;
    outfile<<"$                       $" << endl;
    outfile<<"$  Amount               $" << endl;
    outfile<<"$  Paid:      $" <<fixed<<setprecision(2)<<rate<< "     $" << endl;
    outfile<<"$                       $" << endl;
    outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    
}
//*****************************************************************************************************






//*************************************  FUNCTION FOOTER  **********************************************
void Footer (ofstream &outfile)
{
    // Receives – the output file
    // Task - Prints the output salutation
    // Returns - Nothing
    outfile << endl;
    outfile << setw(25) << "-------------------------" << endl;
    outfile << setw(25) << "| END OF PROGRAM OUTPUT |" << endl;
    outfile << setw(25) << "-------------------------" << endl;
    
    
    return;
}
//************************************* END OF FUNCTION FOOTER  ****************************************
