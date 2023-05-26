// Punzalan, Kurt Brian Daine B.
// Vergara, Marian Stephanie C.
// CMSC 142 - EF6L
// Exercise 8 

#include <stdio.h>
#include <stdlib.h>
#define N 4

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
	fscanf(file, "%d", &num_sets);

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

	printf("%d\n", num_sets);









	

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
					option[move][nopts[move]] = candidate;
					printf("nopts[move] %i candidate %i:\n", nopts[move], candidate);           
				}
			}
			else{
				for(candidate=N;candidate>=1;candidate--)
				{
					for(i=move-1;i>=1;i--)
						if(candidate==option[i][nopts[i]]) break;
					if(!(i>=1))
						option[move][++nopts[move]] = candidate;
					else{
						for(i=1;i<move;i++)
							printf("%2i",option[i][nopts[i]]);
							printf("\n");
						break;

						// ! LOGIC OF THE PROJECT
						
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