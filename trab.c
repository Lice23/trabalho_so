#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void *func(void *var){
	int *x = (int *)var;
	while(++(*x) < 100);
	
	return NULL;
}

int main(){

	printf("CREATING THREADS.\n");

	int var1 = 0, var2 = 0;

	printf("Var1 = %d. Var2 = %d.\n", var1, var2);

	pthread_t increment_thread;

	if(pthread_create(&increment_thread, NULL, func, &var1)) { //creates thread with func passing &var1

		fprintf(stderr, "Error creating thread\n");
		return 1;

	}

	while(var2 != 100) var2++;

	if(pthread_join(increment_thread, NULL)) { //waits for the created thread to finish

		fprintf(stderr, "Error joining thread\n");
		return 2;

	
}
	printf("Var1 = %d. Var2 = %d.\n", var1, var2);

	printf("CREATING PROCESSES.\n");

	pid_t pid = fork();
	
	printf("Hello! This is process = %d.\n", getpid());

	return 0;
}