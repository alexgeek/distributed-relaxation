#ifndef __thread_h__
#define __thread_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include "image.h"
#include "matrix.h"

#define ERR_BARRIER       1
#define ERR_COND          2
#define ERR_MUTEX         3
#define ERR_PARAMS        4
#define ERR_THREAD_CREATE 5
#define ERR_MEM_COPY      6
#define ERR_MALLOC        7

typedef struct {
  pthread_barrier_t start_barrier;
  pthread_cond_t finished_cond;
  pthread_mutex_t finished_mutex;
  int threads;
  int completed;
  int relaxed;
  int dimension;
  num precision;
  num* current;
  num* next;
} global;

typedef struct {
  global* g;
  int from;
  int to;
} params;

global* create_globals(int dimension, num precision, int threads);
void free_globals(global* globals);
params* create_params(global* g, int from, int to);
void free_params(params* p);
int partition_size(int n, int num_threads);
num check_precision(num new, num old, num p);
num relax(num left, num right, num up, num down);
int swap_grid(num* current, num* next, int n);
int sync_repeat(pthread_barrier_t* barr, global* g);
int sync_continue(pthread_cond_t* cond, pthread_mutex_t* mtx, int* completed,
  int* threads, int* relaxed, int thread_relaxed);
int relax_row(num* current, num* next, int row, int length, num precision);
void *relax_thread(void* arg);
void start_threads(pthread_t* threads, global* g);
void join_threads(pthread_t* threads, int thread_count);
num* relax_grid(int dimension, num precision, int threads);

#endif
