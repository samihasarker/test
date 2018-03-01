#include <stdio.h>
#include<math.h>


int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
int decryptor(int msg){

   double p = 3;
   double q = 7;
   double n=p*q;
   double count;
   double totient = (p-1)*(q-1);
   double d;
 
    //public key
   //e stands for encrypt
   double e=2;

   //for checking co-prime which satisfies e>1
   while(e<totient){
   count = gcd(e,totient);
   if(count==1)
     break;
   else
     e++;
   }

    //k can be any arbitrary value
    double k = 2;
 
    //choosing d such that it satisfies d*e = 1 + k * totient
    d = (1 + (k*totient))/e;
    //double msg1 = 12;
    double m = pow((double)msg,(double)d);
    m=fmod((double)m,(double)n);
    printf("%lf", m);
    return (int)m;
   }



int main ()
{
   FILE * fp;
   char in;
   int decryptedValue;
  // char* filename = ("/home/iit/Desktop/v.txt");
   /*open the file for writing*/
   fp = fopen ("/home/iit/Desktop/v.txt","r");
   FILE * fpout = fopen("/home/iit/Desktop/p.txt","w");

   if (fp == NULL){
        printf("Could not open file %s","/home/iit/Desktop/v.txt");
        return 1;
    }
    if (fpout == NULL){
        printf("Could not open output file");
        return 1;
    }
    //while (fgets(str, LEN, fp) != NULL)
      //  printf("%s", str);
   printf("starting to read file\n");
   while(1){
      in = fgetc(fp);
      if(feof(fp)) break;


      decryptedValue = decryptor((int)in);
      fprintf(fpout, "%c", decryptedValue);
   }
   /* write 10 lines of text into the file stream*/
   
 
   /* close the file*/  
   fclose (fp);
   return 0;
}
