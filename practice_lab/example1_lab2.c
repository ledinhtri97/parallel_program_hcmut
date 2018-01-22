#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

//case study 1

long taskids[NUM_THREADS];

//case study 2
 struct takskids2
 {
 	int tid;
 	int pid;
 };

//user-defined funcitons
void * user_def_func(void *threadID){
	//long TID;
	//TID = (long) threadID;

	struct takskids2 *task2 ;
	task2 = (struct takskids2) threadID;
	//printf("Hello World! from thread #%ld\n", TID);
	printf("tid = %d, pid = %d \n", task2.tid, task2.pid);
	pthread_exit(NULL);
}

int main(int argc, char* argv){
	pthread_t threads [NUM_THREADS];
//	int create_flag;
	int creation_flag;
	long i;

	struct *takskids2 task2;

	for(i = 0; i < NUM_THREADS; i++){

		//pass arguments
		taskids[i] = i;

		printf("In main: creating thread %ld\n", i);

		task2.tid = i;
		task2.pid = i+1;

//		creation_flag = pthread_create(&threads[i], NULL, user_def_func, (void *) taskids[i]);

		creation_flag = pthread_create(&threads[i], NULL, user_def_func, (void *) task2);

//		create_flag = pthread_create(&threads[i], NULL, user_def_func, (void *)i);


		if(create_flag){
			printf("ERROR: return code from pthread_create() is %d\n", create_flag);
			exit(-1);
		}
	}

	//free thread
	pthread_exit(NULL);
	return 0;
}
