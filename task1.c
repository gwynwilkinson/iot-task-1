#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int generateRandomNumber(){

  int randomNumber;

  randomNumber = (int) (10.0*rand()/(RAND_MAX + 1.0));

  return randomNumber;
};

int generateRandomAscii(){

  int randomAscii;

  randomAscii = (int) (128.0*rand()/(RAND_MAX + 1.0));

  return randomAscii;
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



int pokerTest(){

  int r1, r2, r3, r4;
  int none = 0;
  int doubles = 0;
  int pairs = 0;
  int triples = 0;
  int quads = 0;

  int i;

  printf("begin poker test\n");

  for (i=1; i<=1000; i++){
    r1 = generateRandomNumber();
    r2 = generateRandomNumber();
    r3 = generateRandomNumber();
    r4 = generateRandomNumber();

    if( r1==r2 && r2==r3 && r3==r4 ){
      quads++;
      }else if( (r1==r2 && r2==r3) || (r2==r3 && r3==r4) || (r1==r2 && r2==r4) || (r1==r3 && r3 == r4) ){
      triples++;
      }else if( (r1==r2 && r3==r4) || (r2==r3 && r4==r1) || (r1==r3 && r2==r4) ){
      pairs++;
      }else if( r1==r2 || r1==r3 || r1==r4 || r2==r3 || r2==r4 || r3==r4){
      doubles++;
      }else{
      none++;
      }
    }

    printf("No. of quads: ");
    printf("%d\n", quads);
    printf("No. of triples: ");
    printf("%d\n", triples);
    printf("No. of pairs: ");
    printf("%d\n", pairs);
    printf("No. of doubles: ");
    printf("%d\n", doubles);
    printf("No. of nones: ");
    printf("%d\n", none);

  }



int maximumTest(){
  int count=0;
  int i;
  int r1, r2, r3;

  printf("begin maximum test\n");

  for (i=1; i<=1000; i++){
    r1 = generateRandomNumber();
    r2 = generateRandomNumber();
    r3 = generateRandomNumber();

    if(r2>r1 && r2>r3){
      count++;
    }
  }
  printf("Count of times middle number was highest: ");
  printf("%d\n", count);
}


int couponTest(){
  bool collected [10] = {false, false, false, false, false, false, false, false, false, false};
  bool win = false;
  int r;
  int i;
  int count = 0;


  while ( !win ) {
    count++;
    r = generateRandomNumber();
    if ( collected [r] == false ){
      collected [r] = true;
      win = true;
      for (i = 1; i<=10; i++){
        if (collected [i-1] == false){
          win = false;

        }
      }
    }
  }
  printf("Number generated before we got one of each digit: ");
  printf("%d\n", count);
}

int processASCII(){
  int rASCII;
  int i;



  int r1, r2, r3, r4;

  FILE *fp;
  int fileSize = 0;
  int filePlace = 0;

  int temp;

  char *tempStr;

  fp = fopen("ASCIIfile.txt", "w");

  for (i=1;i<=4000;i++){
    rASCII = generateRandomAscii();
    fprintf(fp, "%d %s", rASCII, " ");
    //printf("%d", i);
  }


  rewind(fp);

  if( fscanf(fp, "%d %*s", &temp) == EOF){
    printf("EOF!\n");
  }






}





int main() {

  meanTest();
  frequencyTest();
  oddsEvensTest();
  serialTest();
  gapTest();
  pokerTest();
  maximumTest();
  couponTest();
  processASCII();
//  generateRandomNumber();




  return(0);
}
