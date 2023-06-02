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

void mainpartition(int N, int *init);

int main(){

    double t;
    FILE *file;
    int num_set, i, j;
    char line[MAX_LINE_LENGTH];
    int numElements[MAX_ELEMENTS];

    // open file
    file = fopen("inputforruntime.txt", "r");

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
            printf("\n--------------- [SET %d] ---------------\n\n", i);
            
            /* START CLOCK*/
            struct timeval stop, start; //initialization 
            gettimeofday(&start, NULL); //start timer 
            mainpartition(numElements[i], set);
            
            gettimeofday(&stop, NULL); //stop timer 
            printf("Time Elapsed:  %f\n", (double)((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000000); 
            // printf("%d == ", numElements[i]);
        }
        
    }
}


void mainpartition(int N, int *init){
    int main_set[N];                                         
    memcpy(main_set, init, N * sizeof(int));

    int start, move;
    int nopts[N+2];
    int solnCounter = 0;
    move = start = 0; 
	nopts[start]= 1;
    int option[N+2][N+2]; //array of stacks of options
    int i, candidate;
	
	while (nopts[start] >0) //while dummy stack is not empty
	{
		if(nopts[move]>0) 
		{
			move++;
			nopts[move]=0; //initialize new move

			//moved the for loop in this if statement onto the else loop as another nested else and added a break
			if(move==N+1) //solution found!
			{
				
			}

			else if(move == 1){
				for(candidate = N; candidate >=1; candidate --) 
				{
					nopts[move]++;
					option[move][nopts[move]] = main_set[candidate-1];
					// printf("nopts[move] %i candidate %i:\n", nopts[move], candidate);           
				}
			}
			else{
				for(candidate=N;candidate>=1;candidate--)
				{
					for(i=move-1;i>=1;i--)
						if(main_set[candidate-1]==option[i][nopts[i]]) break;
					if(!(i>=1))
						option[move][++nopts[move]] = main_set[candidate-1];
					else{
						// stop getting combination. check if first element is still the first element per partition
						if(main_set[0] == option[1][nopts[1]]){
							//! LOGIC OF THE PROJECT
							int first_sum = 0;
							for(i=1;i<move;i++)  {
								// printf("%2i", option[i][nopts[i]]);
								first_sum += option[i][nopts[i]];
							}

							int second_sum = 0;
							int second_set[N];
							int second_set_counter = 0;
							for (int j = 0; j < N; j++) {
								int is_present = 0;
								for (int k=1;k<move;k++) {
									if (option[k][nopts[k]] == main_set[j]) {
										is_present = 1;
										break;
									}
								}
								if (!is_present) {
									second_sum += main_set[j];
									second_set[second_set_counter++] = main_set[j];
									// printf("%d ", main_set[j]);
								} 
							}
							if (first_sum == second_sum) {
								// printf("SUM: %d ", first_sum);
								// printf("{ ");
								// for (int k=1;k<move;k++) {
								// 	printf("%d ", option[k][nopts[k]]);
								// }
								// printf("}\t");
                                solnCounter++;
								
								// Second Set

								// printf("{ ");
								// for (int k=0;k<second_set_counter;k++) {
								// 	printf("%d ", second_set[k]);
								// }
								// printf("}\n");
							}

						}
                        break;							
					}
				}
			}
		}
		else 
		{
			move--;
			nopts[move]--;

		}
	}
    if (solnCounter == 0) {
		printf("\nThere are no solutions for this set of integers.\n");
	} else {
		printf("\nThere are %d solutions.\n", solnCounter);
	}
	
}