/* 
 Name: ismail Sherifat Omotola
 Matric No: 222477
 Course : CSC 235
 Level: 200 lvl 
 
 Title : Duplicate files
 This program removes duplicate files from a list of files 
 */


#include<stdio.h>
#include<stdlib.h>

 int main(){
     
     //This opens the file
     FILE *read_file = fopen("duplicate.txt", "r"); 
     
     //This reads the fike line of the file and stores it as the number of test cases
     int numOfTestCases;
     fscanf(read_file, "%d", &numOfTestCases);
    
    // This loops through each test cases and reads the number of files in it
     for (int n=0; n<numOfTestCases; n++){
         int numOfFiles;
         fscanf(read_file, "%d", &numOfFiles);
         
         //  This two variables were declared to storethe file names and the index for each test case
         char fileNames[numOfFiles][500];
         int filePosition[numOfFiles];
         
         // athis loops through each file and stores the file names and their indexes in the corresponding varaiables we previously declared
         for (int j=0; j<numOfFiles; j++){
             fscanf(read_file,"%s" "%d", fileNames[j], &filePosition[j]);
             
             }
         
         // This is an array that stores the output which is the  lowest for each file
         int output[numOfFiles];
         // Thie loops through each file name and sets the intitial index to the current file index
         for (int k=0; k<numOfFiles; k++){
             int lowest_index = filePosition[k];
             
             //This loops through each file again and checjs if the files are the same and also if tge index of the inner file loop is lower than the index of the outer file loop 
             for(int m=0; m<numOfFiles; m++){
                 if ((strcmp(fileNames[k], fileNames[m]) == 0) && (filePosition[m] < filePosition[k])){
                     lowest_index = filePosition[m]; 
                     
                     // it then sets the lowest index for that file to the current inner loop index if the condition is fufilled if the condition is fufilled
                 }
                 }
                 
             // This now goes ahead and store the lowest index for each file
             output[k] = lowest_index;
         }
                     
         // This loops through the files and prints out the lowest index for each file
         for (int i=0; i<numOfFiles; i++){
             
             printf("%d\n", output[i]);
         }
                                              
         printf("\n\n");
         
         }
         
 return 0;
     
     
}
  