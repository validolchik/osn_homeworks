#include <stdio.h>
#include <stdlib.h>

FILE *file;

int n_proc = 0, n_sources = 0;

int check_existance(int *arr_exist, int **arr_current){
	int *temp = (int *) calloc(n_sources, sizeof(int));

	for (int i = 0; i < n_proc; ++i){
		for (int y = 0; y < n_sources; ++y){
			temp[y] += arr_current[i][y];
		}
	}

	for (int i = 0; i < n_sources; ++i){
		if(temp[i] > arr_exist[i]){
			free(temp);
			return 0;
		}
	}
	free(temp);
	return 1;
}

int main(int argc, char const *argv[]){
	// char input[] = "input_ok.txt";
	// char output[] = "output_ok.txt";

	char input[] = "input_dl.txt";
	char output[] = "output_dl.txt";

	file = fopen(input, "r");
	char c;
	int n_lines = 0;

	while((c = fgetc(file)) != EOF){
		// printf("%c", c);
		if(c == ' ') n_sources++;
		if(c == '\n'){
			n_lines++;
			n_sources = 0;
		}
	}
	n_lines++; // in case last line has not \n at the end
	n_sources++; // cause we count spaces, but number of sources one more
	// printf("number of lines = %d\n", n_lines);

	n_proc = (n_lines - 5)/2;

	// printf("number of processes = %d\n", n_proc);

	// printf("n_sources = %d\n", n_sources);

	fclose(file);

	// printf("%d %d\n", n_proc, n_sources);

	file = fopen(input, "r");

	int *arr_exist = (int *) calloc(n_sources, sizeof(int));
	int *arr_av = (int *) calloc(n_sources, sizeof(int));

	int **arr_current = (int **) calloc(n_proc, sizeof(int*));
	for (int i = 0; i < n_proc; ++i){
		arr_current[i] = (int *) calloc(n_sources, sizeof(int));
	}

	int **arr_req = (int **) calloc(n_proc, sizeof(int*));
	for (int i = 0; i < n_proc; ++i){
		arr_req[i] = (int *) calloc(n_sources, sizeof(int));
	}

	for (int i = 0; i < n_sources; ++i){
		int temp;
		fscanf(file, "%d", &temp);

		arr_exist[i] = temp;
	}

	for (int i = 0; i < n_sources; ++i){
		int temp;
		fscanf(file, "%d", &temp);
		arr_av[i] = temp;
	}

	for (int i = 0; i < n_proc; ++i){
		for (int y = 0; y < n_sources; ++y){
			int temp;
			fscanf(file, "%d", &temp);
			arr_current[i][y] = temp;
		}
	}


	for (int i = 0; i < n_proc; ++i){
		for (int y = 0; y < n_sources; ++y){
			int temp;
			fscanf(file, "%d", &temp);
			arr_req[i][y] = temp;
		}
	}


	// for (int i = 0; i < n_proc; ++i){
	// 	for (int y = 0; y < n_sources; ++y){
	// 		printf("%d ", arr_current[i][y]);
	// 	}
	// 	printf("\n");
	// }

	int status_existance = check_existance(arr_exist, arr_current);	


	// printf("check existance %d \n", status_existance);

	if(!status_existance){
		printf("error existance \n");
		return 0;
	}

	fclose(file);
	file = fopen(output, "w");

	for (int i = 0; i < n_proc; ++i){
		for (int y = 0; y < n_proc; ++y){
			int is_available_source = 1;
			for(int j = 0; j < n_sources; j++){
				if(arr_av[j] < arr_req[y][j]){
					is_available_source = 0;
					break;
				}
			}

			if(is_available_source){
				for(int j = 0; j < n_sources; j++){
					arr_av[j] += arr_current[y][j];
					arr_current[y][j] = 0;
				}
			}
		}
	}

	int is_free_cur = 1, print_dl = 0;;

	for (int i = 0; i < n_proc; ++i){
		for (int y = 0; y < n_sources; ++y){
			if(arr_current[i][y] != 0){
				is_free_cur = 0;
				print_dl = 1;
			}
		}
		if (print_dl){
			fprintf(file, "process %d deadlocked\n", i);
			print_dl = 0;
		}
	}

	if(is_free_cur) fprintf(file, "no deadlock detected\n");

	//free after all
	for (int i = 0; i < n_proc; ++i){
		free(arr_req[i]);
		free(arr_current[i]);
	}
	free(arr_req);
	free(arr_current);
	free(arr_av);
	free(arr_exist);

	return 0;
}