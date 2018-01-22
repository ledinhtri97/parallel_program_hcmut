#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

//case study 1

long taskids[NUM_THREADS];

//case study 2
 typedef struct taskthreads
 {
 	pthread_t tid;
 	int pid;
 } TaskThread;

//user-defined funcitons
void * user_def_func(void * tthread){
	//long TID;
	//TID = (long) threadID;
	//printf("Hello World! from thread #%ld\n", TID);

	TaskThread * mytask = (TaskThread *) tthread;

	int order=mytask->pid;
   	printf("%i) before num T: %i\n",order, mytask->pid);
   	
   	mytask->pid=4;
  	printf("%i) after assignment num T: %i\n",order ,mytask->pid);
	
	pthread_exit(NULL);
}

int main(int argc, char* argv){
	//pthread_t threads [NUM_THREADS];
	//int create_flag;
	
	TaskThread t_thread[NUM_THREADS];

	int creation_flag;
	long i;

	
	for(i = 0; i < NUM_THREADS; i++){

		//pass arguments
		//taskids[i] = i;

		t_thread[i].tid = i;
		t_thread[i].pid = 1000+i;

		printf("In main: creating thread %ld\n", i);

//		creation_flag = pthread_create(&threads[i], NULL, user_def_func, (void *) taskids[i]);


		creation_flag = pthread_create(&(t_thread[i].tid), NULL, user_def_func, (void *) (t_thread + i));


//		create_flag = pthread_create(&threads[i], NULL, user_def_func, (void *)i);

		//printf("pid = %i\n", creation_flag);
		if(creation_flag){
			printf("ERROR: return code from pthread_create() is %d\n", creation_flag);
			exit(-1);
		}
	}

	//free thread
	pthread_exit(NULL);
	return 0;
}
