/* 
 Name: ismail Sherifat Omotola
 Matric No: 222477
 Course : CSC 235
 Level: 200 lvl 
 
 Title : Self describing numbers
 This program checis if a number is self describing or not
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char numberToString[100];
char self_describing_num= 'Yes';

// declaring variables to be used in the program
int numberAsArray[100];
int count = 0;
int numberOfTrials;
int testNumbers;

void selfDescribing(int testNumbers){
   // iterates through the string depending on the length of the string
   for (int i = 0; i< testNumbers; i++) {
       //iterates through each index of each number and counts the number of time the value of each index appears in the string
       for (int j = 0; j< testNumbers; j++) {
           if (numberAsArray[j] == i) count++;
       }
       
       //if the number of time the  index apears is equal to the number in each index, then the operation assisgns the string 'Yes' to the variable Self_describing_num
       if(count == numberAsArray[i]){
           self_describing_num= 'Yes';
       }
       //Else it assigns No to the self_describing_num and prints that the number is not self describing and breaks
       else{
           self_describing_num = 'No';
           printf("\n");
           printf("%s   The number is not self-describing\n", numberToString);
           break;
       }
       count = 0;
       
       // if 'Yes'' was assigned to the variable self_describing_num then the the operation prints out that the number is self describing and breaks
       if (self_describing_num == 'Yes'){
           printf("\n");
           printf("%s   The number is Self-describing\n", numberToString);
           break;
       }
   }
}



int main(){
   // this operation Opens the file 
   FILE * read_file = fopen("self.in.txt", "r");
   
   // Thie operation checks if the file is empty or not, if it is, it asks the user to input the number of trials
    if(fscanf(read_file, "%d", &numberOfTrials) != EOF) {
       printf("Input the number of trials: %d\n", numberOfTrials);
   }
//This operation reads the file, loops through each test number and stores each Test Number as a string
   for (int j = 0; j < numberOfTrials; j++) {
           fscanf(read_file, "%s", numberToString);
          // printf("\nEnter the number you want to check (not more than 100 integers):  %s\n", numberToString);
           printf("\n");
           testNumbers= strlen(numberToString);
       // This operation Converts the string to an individual number in an array
       for (int k = 0; k< testNumbers; k++) {
           numberAsArray[k] = numberToString[k] - '0';
       }
       // This Operation iterates through the array and gives the number of times each number appears in the Array
       for (int k = 0; k< testNumbers; k++) {
           printf("There are %d  %ds in this number \n", numberAsArray[k],k);
       }
       
       // This function now confirms if the function is self describing or not 
       selfDescribing(testNumbers);
       
   }
   //This operation closes the file after it us done performjng all the operation in the code
   fclose(read_file);
}

    