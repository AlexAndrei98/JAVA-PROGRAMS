//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  main.cpp           ASSIGNMENT #:  4             Grade: _________            *
//*                                                                                                   *
//*   PROGRAM AUTHOR:     __________________________________________                                  *
//*                                     Alexandru Andrei                                              *
//*                                                                                                   *
//*   COURSE #:  CSC 24400 11                              DUE DATE:  October 24, 2016                *
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
void getData(int rollno[],float score[][5],int & size);
void updateGrades (float score[][5], char grade[], int size);
void addTestAverage(float score[][5], int size);
void sortHighToLow(int rollno[], float score[][5], int size);
void sortAverage(int rollno[], float score[][5], int size);
void printArray(ofstream & outfile , int rollno[], float score[][5], char grade[], int size);
void Header(ofstream & outfile);
void Footer(ofstream & outfile);

int main (){
    ifstream infile;
    ofstream outfile;
    outfile.open("Resut.txt", ios::out);
    
    int studentID[50];
    float score[50][5]= {0};
    int size= 0;
    char grade[50];
    
        //get thhe data
    getData(studentID, score, size);
        //print the header
    Header(outfile);
    
    
    
    
    outfile << "The original student data is:"<<endl;
    outfile << "Student ID     Test 1  Test 2  Test 3  Test 4"<<endl;
    outfile << "------------   ------  ------  ------  ------"<<endl;
        //print the array
    printArray(outfile, studentID, score, grade, size);
    
   
    
    
    outfile << "The sorted student data is:"<<endl;
    outfile << "Student ID     Test 1  Test 2  Test 3  Test 4"<<endl;
    outfile << "------------   ------  ------  ------  ------"<<endl;
        //sort the array from highest to lowest score
    sortHighToLow( studentID,score,size );
        //print the array
    printArray(outfile, studentID, score, grade, size);
   
    
    
    
    outfile << "The list of students with their test average and grade course is:"<<endl;
    outfile<< "                                                  Test   Course"<<endl;
    outfile << "Student ID     Test 1  Test 2  Test 3  Test 4  Average  Grade"<<endl;
    outfile << "------------   ------  ------  ------  ------  -------  ------"<<endl;
        //creates another column with the test averages
    addTestAverage(score, size);
        // update the grade
    updateGrades(score, grade, size);
        //print the array
    printArray(outfile, studentID, score, grade, size);
   
    
    
    outfile << "The list of students with their test average high to low are:"<<endl;
    outfile<< "                                                  Test   Course"<<endl;
    outfile << "Student ID     Test 1  Test 2  Test 3  Test 4  Average  Grade"<<endl;
    outfile << "------------   ------  ------  ------  ------  -------  ------"<<endl;
        // sort the score by average
    sortAverage(studentID, score, size);
        // update the grade
    updateGrades(score, grade, size);
        // print the array
    printArray(outfile, studentID, score, grade, size);
    
    
    
        //prints out the footer
    Footer(outfile);
    
}






//***************************************    getData   ************************************************

void getData(int rollno[],float score[][5],int & size){
        // Receives – the text file,
        // Task - Reads the file and creates 2 arrays, one with the student IDs and one with the scores
        // Returns - student IDs' and scores and the number of elements used
    ifstream infile("DATA4.TXT",ios::in);
    size=0;
    for (int i=0; i<50; i++) {
        infile >> rollno[i];
        for (int j=0; j<4; j++) {
            infile >> score [i][j];
        }
        if (rollno[i]<0)
            i=51;
        else
            size++;
    }
    
    return;
}
//*************************************************************************************************






//************************************  updateGrades  *********************************************
void updateGrades (float score[][5], char grade[], int size){
        // Receives – the the data from the array,
        // Task - updates an array with course grades
        // Returns - updated array
    for (int i=0; i<size; i++){
        
        if (score[i][4]>= 90)
            grade[i]='A';
        else if(score[i][4]>= 80)
            grade[i]='B';
        else if(score[i][4]>= 70)
            grade[i]='C';
        else if(score[i][4]>= 60)
            grade[i]='D';
        else
            grade[i]='F';
    }
    return;
}
//*************************************************************************************************







//***********************************  addTestAverage  ********************************************

void addTestAverage(float score[][5], int size){
        // Receives – the the data stored in the score array,
        // Task - computes the average of the test scores
        // Returns - arrays of test scores and averages
    float total=0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<4; j++) {
            total += score[i][j];
        }
        score[i][4]= total/4;
        total=0;
    }
    return;
}
//*************************************************************************************************










//***********************************   sortHighToLow  ********************************************

void sortHighToLow(int rollno[], float score[][5], int size){
        // Receives – the the data stored in the score array,
        // Task - sorts the array based on their grades from high to low
        // Returns - the updated array
    
    float tempscore[4];
    int tempID, max;
    for (int i=0; i<size-1; i++) {
        max=i;
        for (int j=size-1; j>i; j--) {
            if(rollno[j]>rollno[max])
                max=j;
        }
        tempID=rollno[i];
        rollno[i]=rollno[max];
        rollno[max]=tempID;
        
        for (int a=0; a<4; a++) {
            tempscore[a]= score[i][a];
            score[i][a]= score[max][a];
            score[max][a] = tempscore[a];
        }
    }
    return;
}
//*************************************************************************************************










//***********************************   sortAverage   ********************************************

void sortAverage(int rollno[], float score[][5], int size){
        // Receives – the the data stored in the score array,
        // Task - sorts the array based on their averages
        // Returns - the updated array
    
    float tempscore[5];
    int tempID, max;
    
    for (int i=0; i<size-1; i++) {
        
        max=i;
        
        for (int j=size-1; j>i; j--) {
            
            if(score[j][4]>score[max][4])
                max=j;
        }
        
        
        tempID=rollno[i];
        rollno[i]=rollno[max];
        rollno[max]=tempID;
        
        for (int a=0; a<5; a++) {
            tempscore[a]= score[i][a];
            score[i][a]= score[max][a];
            score[max][a] = tempscore[a];
        }
    }
    return;
    
}
//*************************************************************************************************








//************************************   printArray   ********************************************

void printArray(ofstream & outfile , int rollno[], float score[][5], char grade[], int size){
    // Receives – the output file
    // Task - Prints the array
    // Returns - Nothing

    
    for (int i=0; i<size; i++) {
        outfile<< setw(8)<< rollno[i];
        outfile<< "    ";
        for (int j=0; j<4; j++) {
            outfile<<setw(8)<< fixed<< setprecision(2)<<score[i][j];
        }
        if (score[i][4] !=0) {
            outfile<<setw(9)<< fixed<< setprecision(2)<<score[i][4];
            outfile<<setw(8)<<grade[i];
        }
        outfile <<endl;
    }
    
    
    
    
    
}
//*************************************************************************************************











//*************************************  FUNCTION HEADER  **********************************************

void Header(ofstream &outfile)
{       // Receives – the output file
    // Task - Prints the output preamble
    // Returns - Nothing
    outfile << setw(30) << "Alexandru Andrei";
    outfile << setw(17) << "CSC 24000";
    outfile << setw(15) << "Section 11" << endl;
    outfile << setw(30) << "Fall 2016";
    outfile << setw(20) << "Assignment 4"<< endl;
    outfile << setw(35) << "-----------------------------------";
    outfile << setw(35) << "-----------------------------------" << endl<<endl;
    return;
}
//************************************* END OF FUNCTION HEADER  ****************************************





//*************************************  FUNCTION FOOTER  **********************************************
void Footer (ofstream &outfile)
{
    // Receives – the output file
    // Task - Prints the output salutation
    // Returns - Nothing
    outfile << endl;
    outfile << setw(35) << "-----------------------------------" << endl;
    outfile << setw(35) << "|      END OF PROGRAM OUTPUT      |" << endl;
    outfile << setw(35) << "-----------------------------------" << endl;
    
    return;
}
//************************************* END OF FUNCTION FOOTER  ****************************************
