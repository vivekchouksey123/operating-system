#Dinning Philosopher

#include<stdio.h>

#include<stdlib.h>

#include<pthread.h>

#include<semaphore.h>

#include<unistd.h>

sem_t chopstick[5];

void * philos(void *);

void eat(int);

int main()

{

int i,n[5];

pthread_t T[5];

for(i=0;i<5;i++)

sem_init(&chopstick[i],0,1);

for(i=0;i<5;i++){

n[i]=i;

pthread_create(&T[i],NULL,philos,(void *)&n[i]);

}

for(i=0;i<5;i++)

pthread_join(T[i],NULL);

}

void * philos(void * n)

{

int ph=*(int *)n;

printf("Philosopher %d wants to eat\n",ph);

printf("Philosopher %d tries to pick left chopstick\n",ph);

sem_wait(&chopstick[ph]);

printf("Philosopher %d picks the left chopstick\n",ph);

printf("Philosopher %d tries to pick the right chopstick\n",ph);

sem_wait(&chopstick[(ph+1)%5]);

printf("Philosopher %d picks the right chopstick\n",ph);

eat(ph);

sleep(2);

printf("Philosopher %d has finished eating\n",ph);

sem_post(&chopstick[(ph+1)%5]);

printf("Philosopher %d leaves the right chopstick\n",ph);

sem_post(&chopstick[ph]);

printf("Philosopher %d leaves the left chopstick\n",ph);

}

void eat(int ph)

{

printf("Philosopher %d begins to eat\n",ph);

}

Category 3 : Simulate the following Deadlock Avoidance algorithms in C++. a) Write a C++ program to simulate Bankers Algorithm for deadlock avoidance // Banker's Algorithm

#include <iostream>

using namespace std;

int main()

{

int n, m, i, j, k;

n = 5; // Number of processes

m = 3; // Number of resources

int alloc[5][3] = { { 0, 1, 0 },

{ 2, 0, 0 }, // P1

{ 3, 0, 2 }, // P2

{ 2, 1, 1 }, // P3

{ 0, 0, 2 } }; // P4

int max[5][3] = { { 7, 5, 3 },

{ 3, 2, 2 }, // P1

{ 9, 0, 2 }, // P2

{ 2, 2, 2 }, // P3

{ 4, 3, 3 } }; // P4

int avail[3] = { 3, 3, 2 };

int f[n], ans[n], ind = 0;

for (k = 0; k < n; k++) {

f[k] = 0;

}

int need[n][m];

for (i = 0; i < n; i++) {

for (j = 0; j < m; j++)

need[i][j] = max[i][j] - alloc[i][j];

}

int y = 0;

for (k = 0; k < 5; k++) {

for (i = 0; i < n; i++) {

if (f[i] == 0) {

int flag = 0;

for (j = 0; j < m; j++) {

if (need[i][j] > avail[j]){

flag = 1;

break;

}

}

if (flag == 0) {

ans[ind++] = i;

for (y = 0; y < m; y++)

avail[y] += alloc[i][y];

f[i] = 1;

}

}

}

}

cout << "Following is the SAFE Sequence" << endl;

for (i = 0; i < n - 1; i++)

cout << " P" << ans[i] << " ->";

cout << " P" << ans[n - 1] <<endl;

return (0);

}
