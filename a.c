// Punzalan, Kurt Brian Daine B.
// Vergara, Marian Stephanie C.
// CMSC 142 - EF6L
// Exercise 8 

#include <stdio.h>
#include <stdlib.h>
#define N 7

int main(){
	int start, move;
	int nopts[N+2]; //array of top of stacks
	int option[N+2][N+2]; //array of stacks of options
	int i, candidate;
	int is_valid = 0;
	int num_sets; // number of sets

	int main_set[100];
	FILE *file;



	file = fopen("input.txt", "r");	
	// fscanf(file, "%d", &num_sets);

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int num;
    int j = 0;
    while (fscanf(file, "%d", &num) == 1) {
        main_set[j] = num;
        j++;
    }

	for (int k = 0; k < j; k++) {
        printf("%d ", main_set[k]);
    }
    printf("\n");

    fclose(file);

	// printf("%d\n", num_sets);









	

	// printf("Number of sets: %d\n", num_sets);


	move = start = 0; 
	nopts[start]= 1;

	

	
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
						//! LOGIC OF THE PROJECT
						int first_sum = 0;
						for(i=1;i<move;i++)  {
							// printf("%2i", option[i][nopts[i]]);
							first_sum += option[i][nopts[i]];
						}

						int second_sum = 0;
						int second_set[N];
						int second_set_counter = 0;
						//! change this: gawing dynamic ang array and ang size
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
							printf("{ ");
							for (int k=1;k<move;k++) {
								printf("%d ", option[k][nopts[k]]);
							}
							printf(" }\t");
							
							// Second Set

							printf("{ ");
							for (int k=0;k<second_set_counter;k++) {
								printf("%d ", second_set[k]);
							}
							printf(" }\n");
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


}