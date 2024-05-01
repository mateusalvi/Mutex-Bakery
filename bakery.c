#include <bakery.h>

int choosing [N_THREADS];
int ticket [N_THREADS];

void lamport_mutex_init()
{
  for (int i = 0; i < N_THREADS; i++)
  {
    choosing[i] = 0;
    ticket[i] = 0;
  }
  
}

void lamport_mutex_lock (int thread_id)
{

}

void lamport_mutex_unlock (int thread_id)
{

}

void dormir() 
{
  usleep((rand() % 11) * 100000); /* dormir 0, 100, 200, ..., 1000 milissegundos */
}

int max_ticket()
{
  int i, max = ticket[0];

  for (i = 1; i < N_THREADS; i++)
    max = ticket[i] > max ? ticket[i] : max;
}

static void * thread_process(void *arg)
{
  int j, i = *((int *) arg);

  printf("Hello! I'm thread %d!\n", i);

  do{
    choosing[i] = 1;
    ticket[i] = max_ticket () + 1;
    choosing[i] = 0;

    for (j = 0; j < N_THREADS; j++) 
    {
      while (choosing[j])
        /* nao fazer nada */;
      while (ticket[j] != 0 && ((ticket[j] < ticket[i]) || (ticket[j] == ticket[i] && j < i)))
        /* nao fazer nada */;
    }

    printf("I'm thread %d and I'm entering my critical region!\n", i);
    dormir();
    printf("I'm thread %d and I'm leaving my critical region!\n", i);

    ticket[i] = 0; /* indicar que saimos da secao critica */

  }while (1);

  return NULL;
}

// int main(int argc, char **argv)
// {
//   int thread_num, ret;
//   int tinfo_id[N_THREADS];
//   pthread_t tinfo_process[N_THREADS];
//   pthread_attr_t attr;
//   void *res;

//   ret = pthread_attr_init(&attr);

//   for (thread_num = 0; thread_num < N_THREADS; thread_num++)
//   {
//     tinfo_id [thread_num] = thread_num;
//     ret = pthread_create(&tinfo_process[thread_num], &attr, &thread_process, &tinfo_id[thread_num]);
//   }

//   ret = pthread_attr_destroy(&attr);

//   for(thread_num = 0; thread_num < N_THREADS; thread_num++)
//   {
//     ret = pthread_join(tinfo_process[thread_num], &res);
//     printf("Joined with thread id %d\n", thread_num);
//     free(res);
//   }

//   exit(EXIT_SUCCESS);
// }