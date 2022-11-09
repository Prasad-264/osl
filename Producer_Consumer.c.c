#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<unistd.h>

void *consumer();
void *producer();

pthread_t p, c; 
sem_t empty, full; 
pthread_mutex_t mutex; 
pthread_attr_t attr; 
int counter = 0;
int buffer[5]; 

//initialize all variables
void init() {

	pthread_attr_init(&attr); 
	sem_init(&full, 0, 0); 
	sem_init(&empty, 0, 5); 
	pthread_mutex_init(&mutex, NULL);
}

int main() {
	int np,nc,i;
	init();
   	printf("Enter no of producers : ");
	scanf("%d", &np);
	printf("Enter no of consumers : ");
	scanf("%d", &nc);

	
	for(i=0; i<np; i++) {	
		pthread_create(&p, &attr, producer, NULL);
	}
	for(i=0; i<nc; i++) {
		pthread_create(&c, &attr, consumer, NULL);
	}
	for(i=0; i<np; i++) pthread_join(p, NULL);
	for(i=0; i<nc; i++) pthread_join(c, NULL);	
	return 0;
}

void *producer() {
	int item = rand()%100;
	if(counter>=5) printf("buffer full..Error\n");
    sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	
	if(counter<5) {
    	buffer[counter] = item;
		counter++;
		printf("Producer produced %d\n", item);
	}
	pthread_mutex_unlock(&mutex);
	sem_post(&full);

	sleep(1);
	pthread_exit(0);
}

void *consumer() {
	int item;
	if(counter==0) {
		printf("buffer empty..Error\n");	
		return 0;
	}
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	
	if(counter>0) {
		item = buffer[counter-1];
		counter--;
		printf("Consumer consumed %d\n", item);
	}
		
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);

	sleep(1);
	pthread_exit(0);
}
