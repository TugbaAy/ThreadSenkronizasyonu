  #include <stdio.h>
  #include <stdlib.h>
  #include <pthread.h>
  #include <semaphore.h>

  sem_t lockAmp;
  sem_t lockDolar;
  sem_t lockBirlesim;
  sem_t lockMakine;
  int amp = 0;
  int dolar = 0;
  int sayac = 1;

  void makina();
  void makinaAmp();
  void makinaDolar();
  void makinaBirlestir();


  int main(int argc, char **argv){

    pthread_t mAmp, mDolar, mBirlestir;
    void *retval;
    if (sem_init(&lockAmp,0,0) != 0) {
      printf("semafor hatası\n");
    }
    
    sem_init(&lockDolar,0,1);
    sem_init(&lockMakine,0,1);
    sem_init(&lockBirlesim,0,1);

    pthread_create(&mAmp, NULL, makinaAmp, NULL);
    pthread_create(&mDolar, NULL, makinaDolar, NULL);
    pthread_create(&mBirlestir, NULL, makinaBirlestir, NULL);
    pthread_join(mAmp, &retval);
    pthread_join(mDolar, &retval);
    pthread_join(mBirlestir, &retval);

    sem_destroy(&lockAmp);
    sem_destroy(&lockDolar);
    sem_destroy(&lockBirlesim);
    sem_destroy(&lockMakine);

  return 0;
  }

  void makina(){
      sem_wait(&lockMakine);
  }

  void makinaAmp(){
    while (1) {
      makina();
      sleep(3);
      amp = 1;
      sem_post(&lockMakine);
      sem_post(&lockBirlesim);
      printf("&\n");
      sem_wait(&lockAmp);
    }
  }

  void makinaDolar(){
   while (1) {
    makina();
    sleep(5);
    dolar = 1;
    sem_post(&lockMakine);
    sem_post(&lockBirlesim);
    printf("$\n");
    sem_wait(&lockDolar);
   }
  }


  void makinaBirlestir(){
    char ilk,iki;
    while(1){
      if (amp == 1 || dolar == 1) { // hangisi daha önce üretildi onu kontrol ediyor.
        if (dolar == 1) {
          ilk = '$';
          iki = '&';
          // önce gelen diğerini bekliyor.
          sem_wait(&lockBirlesim);
        }
        else if (amp == 1) {
          ilk = '&';
          iki = '$';
          sem_wait(&lockBirlesim);
        }
      }
      if (amp == 1 && dolar == 1) {
        sleep(4);
        printf("%d_%c%c\n", sayac,ilk,iki);
        sem_post(&lockAmp);
        sem_post(&lockDolar);
        amp = 0;
        dolar = 0;
        sayac++;
  }
  }
  }
