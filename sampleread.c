// Punzalan, Kurt Brian Daine B.
// Vergara, Marian Stephanie C.
// CMSC 142 - EF6L
// Exercise 8 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include <sys/time.h> 
#include <unistd.h>
#include <sched.h>

// #define N 7
#define MAX_LINE_LENGTH 100
#define MAX_ELEMENTS 100


int main(){

    double t;
    FILE *file;
    int num_set, i, j;
    char line[MAX_LINE_LENGTH];
    int numElements[MAX_ELEMENTS];

    // open file
    file = fopen("input.txt", "r");

    // check if file exists
    if (file == NULL) {

        printf("Error: could not open file. \n");
        exit(1);

    }

    // read number of sets
    // expect: num_set = 2
    fscanf(file, "%d", &num_set);
    // printf("%d == ", num_set);
    

    // read how many elements per set
    for (i = 0; i <= num_set; i++) {
        
        numElements[i] = 0;
        fgets(line, sizeof(line), file);
        if (i != 0) {
            int len=strlen(line);
            for (int j=0; j<len; j++) if(line[j]==' ')numElements[i]++;         
            numElements[i]++;          
            // expect: 7 and 8 (elements per set)
            // printf("%d == ", numElements[i]);
            
        }

    }

    fseek(file, 0, SEEK_SET);

    // read number of sets based on first line of input again
    // expect: num_set = 2
    fscanf(file, "%d", &num_set);

    // process each set based on how many elements based on numElements
    // read elements of each set
    for (i=0; i<=num_set; i++) {

        int set[numElements[i]];
        for (j=0; j<numElements[i]; j++) {
            fscanf(file, "%d", &set[j]);
            //expect: 3 7 1 2 4 5 8 AND 13 17 12 8 14 6 20 10
            // printf("%d == ", set[j]);

        }

        if (i!=0){
            printf("\n------------------ [SET %d] ------------------\n\n", i);
            
            /* START CLOCK*/
            // struct timeval stop, start; //initialization 
            // gettimeofday(&start, NULL); //start timer 
            // mainpartition(numElements[i], set);
            
            // gettimeofday(&stop, NULL); //stop timer 
            // printf("Time Elapsed:  %f\n", (double)((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000000); 
            // printf("%d == ", numElements[i]);
        }
        
    }
}