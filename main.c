#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define PHILOSOPHERS_COUNT 5

#define THINKING_STATUS 2
#define HUNGRY_STATUS 1
#define EATING_STATUS 0

sem_t philosophersSem[PHILOSOPHERS_COUNT];
#define FIRST_FORK ((philosopherId + 4) % PHILOSOPHERS_COUNT)
#define SECOND_FORK ((philosopherId + 1) % PHILOSOPHERS_COUNT)
int philosophers[PHILOSOPHERS_COUNT];
int forksStates[PHILOSOPHERS_COUNT];
pthread_mutex_t lock;

void eating(int philosopherId) {
  printf("Philosopher %d takes fork %d and %d\n",
         philosopherId + 1, FIRST_FORK + 1, philosopherId + 1);
  printf("Philosopher %d eats\n", philosopherId + 1);
  sleep(1);
}

void eatIfForksFree(int philosopherId) {
  if (forksStates[philosopherId] == HUNGRY_STATUS
      && forksStates[FIRST_FORK] != EATING_STATUS
      && forksStates[SECOND_FORK] != EATING_STATUS) {
    forksStates[philosopherId] = EATING_STATUS;
    eating(philosopherId);
    sem_post(&philosophersSem[philosopherId]);
  }
}

void takeForkAndEat(int philosopherId) {
  pthread_mutex_lock(&lock);
  forksStates[philosopherId] = HUNGRY_STATUS;
  printf("Philosopher %d is Hungry\n", philosopherId + 1);
  eatIfForksFree(philosopherId);
  pthread_mutex_unlock(&lock);
  sem_wait(&philosophersSem[philosopherId]);
  sleep(1);
}

void putForkAndThink(int philosopherId) {
  pthread_mutex_lock(&lock);
  forksStates[philosopherId] = THINKING_STATUS;
  printf("Philosopher %d putting fork %d and %d down\n",
         philosopherId + 1, FIRST_FORK + 1, philosopherId + 1);
  printf("Philosopher %d is thinking\n", philosopherId + 1);
  eatIfForksFree(FIRST_FORK);
  eatIfForksFree(SECOND_FORK);
  pthread_mutex_unlock(&lock);
  sleep(1);
}

_Noreturn void *philosopherLiveCycle(void *num) {
  int *i = num;
  printf("Philosopher %d is thinking\n", *i + 1);
  while (1) {
    takeForkAndEat(*i);
    putForkAndThink(*i);
  }
}

int main() {
  int i;
  pthread_t philosopherThreads[PHILOSOPHERS_COUNT];
  pthread_mutex_init(&lock, NULL);

  for (i = 0; i < PHILOSOPHERS_COUNT; i++) {
    sem_init(&philosophersSem[i], 0, 0);
    philosophers[i] = i;
  }
  for (i = 0; i < PHILOSOPHERS_COUNT; i++) {
    pthread_create(&philosopherThreads[i], NULL,
                   philosopherLiveCycle, &philosophers[i]);
  }

  for (i = 0; i < PHILOSOPHERS_COUNT; i++)
    pthread_join(philosopherThreads[i], NULL);
}
