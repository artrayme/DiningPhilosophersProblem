//#include <pthread.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>//Header file for sleep(). man 3 sleep for details.
//#define PHILOSOPHERS_COUNT 2
//
//int chopsticks[PHILOSOPHERS_COUNT];
//
//void hungry(int philosopherNumber);
//void startEating(int philosopherNumber);
//void thinking(int philosopherNumber);
//void endEating(int philosopherNumber);
//
//_Noreturn _Noreturn void *philosopherLiveCycle(void *id) {
//  int philosopherNumber = *((int *) id);
//
//  while (1) {
//    thinking(philosopherNumber);
//
//    hungry(philosopherNumber);
//
//    while (1) {
//
//      if (chopsticks[philosopherNumber] == 1)
//        continue;
//      if (chopsticks[(philosopherNumber + 1) % PHILOSOPHERS_COUNT] == 1)
//        continue;
//
//      chopsticks[philosopherNumber] = 1;
//      chopsticks[(philosopherNumber + 1) % PHILOSOPHERS_COUNT] = 1;
//
//      startEating(philosopherNumber);
//
//      chopsticks[philosopherNumber] = 0;
//      chopsticks[(philosopherNumber + 1) % PHILOSOPHERS_COUNT] = 0;
//
//      endEating(philosopherNumber);
//      break;
//    }
//  }
//}
//void endEating(int philosopherNumber) { printf("PID : (%ld)  Philosopher %d puts #%d and #%d chopsticks down\n", pthread_self(), philosopherNumber + 1, philosopherNumber + 1, 1 + ((philosopherNumber + 1) % PHILOSOPHERS_COUNT)); }
//
//void startEating(int philosopherNumber) {
//  printf("PID : (%ld)  Philosopher %d lock #%d and #%d forks\n", pthread_self(), philosopherNumber + 1, philosopherNumber + 1, 1 + ((philosopherNumber + 1) % PHILOSOPHERS_COUNT));
//  printf("PID : (%ld)  Philosopher %d is startEating books\n", pthread_self(), philosopherNumber + 1);
//  sleep(1);
//}
//void hungry(int philosopherNumber) {
//  printf("PID : (%ld)  Philosopher %d is Hungry\n", pthread_self(), philosopherNumber + 1);
//}
//
//void thinking(int philosopherNumber) {
//  printf("PID : (%ld)  Philosopher %d is THINKING_STATUS\n", pthread_self(), philosopherNumber + 1);
//  sleep(1);
//}
//
//int main() {
//  pthread_t threadIds[PHILOSOPHERS_COUNT];
//  int philosopher_numbers[PHILOSOPHERS_COUNT];
//
//  for (int i = 0; i < PHILOSOPHERS_COUNT; i++) {
//    philosopher_numbers[i] = i;
//    chopsticks[i] = 0;
//    pthread_create(&threadIds[i], NULL, philosopherLiveCycle, (void *) &philosopher_numbers[i]);
//  }
//
//  for (int i = 0; i < PHILOSOPHERS_COUNT; i++) {
//    pthread_join(threadIds[i], NULL);
//  }
//
//  exit(0);
//}