//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  main.cpp           ASSIGNMENT #:  3             Grade: _________            *
//*                                                                                                   *
//*   PROGRAM AUTHOR:     __________________________________________                                  *
//*                                     Alexandru Andrei                                              *
//*                                                                                                   *
//*   COURSE #:  CSC 24400 11                              DUE DATE:  October 7, 2016                 *
//*                                                                                                   *
//*****************************************************************************************************

//***********************************  PROGRAM DESCRIPTION  *******************************************
//*                                                                                                   *
//*   PROCESS: This program is designed to read a list of data consisting of students IDs and test    *
//*   scores and then to sort them by grade and deteremine the highest and lowest grade.              *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     : getData – reads the data from the imput file and store a value in the array      *
//*                  scoreMin – finds the location in the array with the minimum value                *
//*                  scoreMax –finds the location in the array with the maximum value                 *
//*                  scoreAvg - finds the average score of the values in the array                    *
//*                  getGrade - this function separates the students id's and puts them in order      *
//*                             based on their test scores                                            *
//*                  print – prints the data stored in the array                                      *
//*                                                                                                   *
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#define StudentArrayConstant 50;
#define scoreConstant 50;

void getData(ifstream & infile, int StudentArray[],float score[],int & size);
void scoreMin(float score[], int size, int & minLocation);
void scoreMax(float score[], int size, int & maxLocation);
void scoreAvg(float score[], int size, float & average);
void sortMin(int StudentArray[], float score[], int size);
void sortMax(int StudentArray[], float score[], int size);
void print(ofstream & outfile, int StudentArray[], float score[], int size);
void Header(ofstream & outfile);
void Footer(ofstream & outfile);

int main (){
    ifstream infile;
    ofstream outfile;
    int studentID[50];
    int size=1;
    int minLocation;
    int maxLocation;
    float score [50];
    float average;
    
    infile.open("DATA3.TXT",ios::in);
    outfile.open("Resut.txt", ios::out);
    
        //set precision for outfile
    outfile.setf(ios::fixed);
    outfile.precision(2);
    
        //prints out the header
    Header(outfile);
        //reads the student ID and the test score and calculates the number of students
    getData(infile, studentID, score, size);
    
    
    outfile<<"The original list of test scores is:"<<endl<<endl;
    outfile<< setw(3)<< "STUDENT ID #"<<setw(10)<< "TEST SCORE"<< endl;
    
        // prints out the student IDs and their Test score as read from the file
    print(outfile,studentID,score,size);
    
    
    outfile<<"The test scores sorted highest to lowest are : "<< endl <<endl;
    outfile<< setw(3)<< "STUDENT ID #"<<setw(10)<< "TEST SCORE"<< endl;
    
        //sort the students based on their score from high to low
    sortMax(studentID, score, size);
    
    for (int i=0; i< size; i++) {
        outfile<< setw(8)<<studentID[i]<<setw(13)<< score[i]<<endl;
    }
    
    //sort the students based on their score from low to high
    sortMin(studentID, score, size);
    
    outfile<<"The test scores sorted lowest to highest are : "<< endl <<endl;
    outfile<< setw(3)<< "STUDENT ID #"<<setw(10)<< "TEST SCORE"<< endl;
    for (int i=0; i< size; i++) {
        outfile.precision(2);
        outfile<< setw(8)<<studentID[i]<<setw(13)<< score[i]<<endl;
    }
    
        //calculates the location of the lowest score
    scoreMin(score, size, minLocation);
    
        //calculates the location of the highest score
    scoreMax(score, size, maxLocation);
    
        //calculates the score average
    scoreAvg(score, size, average);
    
        //prints 2 blank lines
    outfile<<endl<<endl;
    
        //prints out the lowest score and its student ID
    outfile<<"The lowest score was : "<< score[minLocation] << " achieved by student # "<<
    studentID[minLocation]<<endl<<endl;
    
        //prints out the highest score and its student ID
    outfile<<"The highest score was : "<< score[maxLocation] << " achieved by student # "<<
    studentID[maxLocation]<<endl<<endl;
    
        //prints out the average score
    outfile<<"The average test score for the group is : "<<average<<endl;
    
        //prints out the footer
    Footer(outfile);
    
}





//***************************************    getData   ************************************************

void getData(ifstream & infile, int StudentArray[],float score[],int & size){
        // Receives – the output file, the array of students and scores and the size of them
        // Task - Reads the file and creates 2 arrays, one with the student IDs and one with the scores
        // Returns - Nothing
    
    int studentID;
    infile>> studentID;
    size=0;
    while (studentID>0){
        StudentArray[size]= studentID;
        infile>> score[size];
        size++;
        infile>> studentID;
    }
    return;
}
//*************************************************************************************************








//***************************************    print   *************************************************

void print(ofstream & outfile, int StudentArray[], float score[], int size){
        // Receives – the output file, the array of students and scores and the size of them
        // Task - Prints student IDs and scores as read from the file
        // Returns - Nothing
    for (int i=0; i<size; i++) {
        outfile<< setw(8)<< StudentArray[i]<< setw(13)<<score[i]<<endl;
    }
}

//*****************************************************************************************************





//***************************************   scoreMin   ************************************************
void scoreMin(float score[], int size, int & minLocation){
        // Receives – the array with the scores and the number of student in the array
        // Task - Find the location of the lowest score in the array
        // Returns - Nothing
    minLocation=0;
    float minValue=101;
    for (int i=0; i<size; i++) {
        if (minValue>score[i]) {
            minValue = score[i];
            minLocation = i;
        }
    }
    return;
    
}
//*****************************************************************************************************








//***************************************   scoreMax   ************************************************
void scoreMax(float score[], int size, int & maxLocation){
        // Receives – the array with the scores and the number of student in the array
        // Task - Find the location of the highest score in the array
        // Returns - Nothing
    maxLocation=0;
    float maxValue=0;
    for (int i=0; i<size; i++) {
        if (maxValue<score[i]) {
            maxValue = score[i];
            maxLocation = i;
        }
    }
    return;
}
//*****************************************************************************************************








//***************************************   scoreAvg   ************************************************

void scoreAvg(float score[], int size, float & average){
        // Receives – the array with the scores and the number of student in the array
        // Task - finds the average score in the array
        // Returns - Nothing
    
    float total=0;
    for (int i=0; i<size; i++) {
        total = total + score[i];
        average = total/size;
        
    }
    return;
    
}
//*****************************************************************************************************







//***************************************   sortMin    ************************************************

void sortMin(int StudentArray[], float score[], int size ){
        // Receives – the array with the scores and the number of student in the array
        // Task - sorting the arrays from  minimum score to maximum
        // Returns - the new sorted array
    
    int tempID=0;
    float tempScore=0;
    for(int j=0; j<size; j++)
        for(int i=0; i<(size)-1; i++) {
            if (score[i] > score[i+1]) {
                
                tempID = StudentArray[i];
                StudentArray[i]= StudentArray[i+1];
                StudentArray[i+1] = tempID;
                
                tempScore = score[i];
                score[i]= score[i+1];
                score[i+1] = tempScore;
            }
        }
    return;
}
//*****************************************************************************************************





//***************************************   sortMax    ************************************************

void sortMax(int StudentArray[], float score[], int size ){
        // Receives – the array with the scores and the number of student in the array
        // Task - sorting the arrays from maximum score to minimum
        // Returns - the new sorted array
    
    float tempID;
    int max;
    int tempScore;
    for (int i =0; i<size-1; i++) {
        max=i;
        for (int j=size-1; j>i; j--) {
            if (score[j]>score[max])
                max=j;
        }
        

        
        tempScore= StudentArray[i];
        StudentArray[i]= StudentArray[max];
        StudentArray[max]=tempScore;
        
        tempID=score[i];
        score[i]= score[max];
        score[max]=tempID;
        
        
        
    }
    return;
}
//*****************************************************************************************************






//*************************************  FUNCTION HEADER  **********************************************
void Header(ofstream &outfile)
{        // Receives – the output file
        // Task - Prints the output preamble
        // Returns - Nothing
    outfile << setw(30) << "Alexandru Andrei";
    outfile << setw(17) << "CSC 24000";
    outfile << setw(15) << "Section 11" << endl;
    outfile << setw(30) << "Fall 2016";
    outfile << setw(20) << "Assignment 3"<< endl;
    outfile << setw(35) << "-----------------------------------";
    outfile << setw(35) << "-----------------------------------" << endl<<endl;
    return;
}
//************************************* END OF FUNCTION HEADER  ****************************************





//*************************************  FUNCTION FOOTER  **********************************************
void Footer (ofstream &outfile)
{       // Receives – the output file
        // Task - Prints the output salutation
        // Returns - Nothing
    outfile << endl;
    outfile << setw(35) << "-----------------------------------" << endl;
    outfile << setw(35) << "|      END OF PROGRAM OUTPUT      |" << endl;
    outfile << setw(35) << "-----------------------------------" << endl;
    
    return;
}
//************************************* END OF FUNCTION FOOTER  ****************************************
