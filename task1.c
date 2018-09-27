#include <stdio.h>
#include <stdlib.h>
int generateRandomNumber(){

  int randomNumber;

  randomNumber = (int) (10.0*rand()/(RAND_MAX + 1.0));

  return randomNumber;
};

int meanTest(){
  int meanArray[1000];
  int i;
  float mean;

  printf("begin mean test\n");

  for (i=1;i<=1000;i++){
    mean = mean + generateRandomNumber();
  }
  mean = mean/1000;
  printf("%f\n", mean);
return 0;
}

int frequencyTest(){
  int freqArray[10] = {0,0,0,0,0,0,0,0,0,0};
  int i;
  int r;
  printf("begin frequency test\n");
  for (i=1;i<=10000;i++){
    r = generateRandomNumber();
    freqArray[r]++;
  }

  for (i=1;i<=10;i++){
    printf("%d\n", freqArray[i-1]);
  }
return 0;
}

int oddsEvensTest(){
  int odd=0;
  int even=0;
  int i;
  int r;

  printf("begin odd-even test\n");

  for (i=1;i<=10000;i++){
    r = generateRandomNumber();
    if (r==0||r==2||r==4||r==6||r==8){
      even++;
    }else{
      odd++;
    }

  }
  printf("%d\n", odd);
  printf("%d\n", even);
  return 0;
}

int serialTest(){
  int i;
  int r1;
  int r2;
  float serialArray[100];
  int pair;

  printf("begin serial test\n");

  for (i=1;i<=100;i++){serialArray[i-1] = 0;}

  for (i=1;i<=10000;i++){
    r1 = generateRandomNumber();
    r2 = generateRandomNumber();
    r2 = r2*10;

    pair = r1+r2;
    serialArray[pair]++;

//    printf("%d\n", pair);
//    printf("%f\n", serialArray[pair]);
  }
  for (i=1;i<=100;i++){
    serialArray[i-1]=serialArray[i-1]/100;
    //printf("%f\n", serialArray[i-1]);
  }
return 0;
}

int gapTest(){
int i;
int counter=0;
float gapArray[7]={0,0,0,0,0,0,0};
int r;

printf("begin gap test\n");

  for (i=1;i<=10000;i++){
    r = generateRandomNumber();
    if (r!=4){
      counter++;
      if (counter>6){
        counter=6;
      }
    }else{
      gapArray[counter]++;
      //printf("Number 3 found - counter value: ");
      //printf("%d\n", counter);
      counter=0;
    }
  }
  printf("Gaps are as follows:\n");
  for(i=1;i<=7;i++){
    printf("%f\n", gapArray[i-1]);
  }
}







int main() {

  meanTest();
  frequencyTest();
  oddsEvensTest();
  serialTest();
  gapTest();
//  generateRandomNumber();




  return(0);
}
