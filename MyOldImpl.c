//#include <pthread.h>
//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>
//
//#define PHILOSOPHERS_COUNT 5
//#define FORK_FREE 0
//
//#define FORK_BUSY 1
//
//pthread_mutex_t lock;
//pthread_t philosopherThreads[PHILOSOPHERS_COUNT];
//int philosophers[PHILOSOPHERS_COUNT];
//int forksStates[PHILOSOPHERS_COUNT];
//
//int getRightFork(int philosopherId) {
//  return philosopherId;
//}
//
//int getLeftFork(int philosopherId) {
//  if (philosopherId + 1 == PHILOSOPHERS_COUNT) return 0;
//  return philosopherId + 1;
//}
//
//void eatBooks(int philosopherId) {
//  printf("Philosopher %d takes fork %d and %d\n", philosopherId,
//         getLeftFork(philosopherId), getRightFork(philosopherId));
//  printf("Philosopher %d eats\n", philosopherId);
//  sleep(2);
//  printf("Philosopher %d putting fork %d and %d down\n", philosopherId,
//         getLeftFork(philosopherId), getRightFork(philosopherId));
//}
//
//void getForkIfFree(int philosopherId) {
//  pthread_mutex_lock(&lock);
//  if (forksStates[getLeftFork(philosopherId)] == FORK_FREE
//      && forksStates[getRightFork(philosopherId)] == FORK_FREE){
//    forksStates[getLeftFork(philosopherId)] = FORK_BUSY;
//    forksStates[getRightFork(philosopherId)] = FORK_BUSY;
//    pthread_mutex_unlock(&lock);
//    eatBooks(philosopherId);
//    pthread_mutex_lock(&lock);
//    forksStates[getLeftFork(philosopherId)] = FORK_FREE;
//    forksStates[getRightFork(philosopherId)] = FORK_FREE;
//    printf("Philosopher %d is thinking\n", philosopherId);
//  }
//  pthread_mutex_unlock(&lock);
//}
//
//_Noreturn void *philosopherLiveCycle(void *num) {
//  int *i = num;
//  int id = *i;
//  printf("Philosopher %d is thinking\n", id);
//  while (1) {
//    getForkIfFree(id);
//    sleep(1);
//  }
//}
//
//int main() {
//  pthread_mutex_init(&lock, NULL);
//  int i = 0;
//
//  for (i = 0; i < PHILOSOPHERS_COUNT; i++) {
//    philosophers[i] = i;
//    forksStates[i] = FORK_FREE;
//  }
//
//  for (i = 0; i < PHILOSOPHERS_COUNT; i++) {
//    pthread_create(&philosopherThreads[i], NULL,
//                   philosopherLiveCycle, &philosophers[i]);
//  }
//
//  for (i = 0; i < PHILOSOPHERS_COUNT; i++)
//    pthread_join(philosopherThreads[i], NULL);
//}