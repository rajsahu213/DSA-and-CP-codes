#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAXCHAIRS 5
#include<unistd.h>
sem_t customer, barber, donecutting;
pthread_mutex_t lock;
int nowaiting = 0;
void  *Barber(void *Arg)
{
    while (1)
    {
        sem_wait(&customer);  //wait for customer to become available
        printf("Barber is allocated\n");
        sem_post(&barber);  //signal to client that barber is ready
        printf("Barber is cutting hair\n");
        sleep(2);
        sem_post(&donecutting);  //signal done
        pthread_mutex_lock(&lock);  //access no of waiting chairs and lock it
        nowaiting--;
        pthread_mutex_unlock(&lock);  //unlock the access to count of waiting  clients
    }
}
void  *Customer(void *Arg)
{
    pthread_mutex_lock(&lock);  //chair mutex is locked
    if (nowaiting < MAXCHAIRS)
    {
        nowaiting++;
        printf("Customer is sitting\n");
        pthread_mutex_unlock(&lock);  //free mutex lock on chairs count
        sem_post(&customer);  //signal that customer is ready
        sem_wait(&barber);    //wait for barber
        sem_wait(&donecutting);  //wait till service is done
        printf("Customer exiting after getting service \n");
    }
    else
    {
        pthread_mutex_unlock(&lock); //free lock on chair count
    }
}
int main()
{
    pthread_t Thread[40];
    //initialize semaphores
    sem_init(&customer, 0, 0);
    sem_init(&barber, 0, 0);
    sem_init(&donecutting, 0, 0);
    pthread_create(&Thread[0], NULL, Barber, NULL); //creating barber thread
    for (int i = 1; i < 40; i++)
    {
        pthread_create(&Thread[i], NULL, Customer, NULL); //client threads creation
    }
    for (int i = 1; i < 40; i++)
    {
        pthread_join(Thread[i], NULL);
    }
}