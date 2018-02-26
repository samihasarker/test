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

int encryptor(int msg){
   double p = 3;
   double q = 7;
   double n=p*q;
   double count;
   double totient = (p-1)*(q-1);

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
   double c = pow((double)msg,(double)e);
   c=fmod((double)c,(double)n);
   printf("%lf", c);
   return (int)c;

}

int main ()
{
   FILE * fp;
   char in;
   int encryptedValue;
   //char* filename = "/home/iit/Desktop/input.txt";
   /*open the file for writing*/
   fp = fopen ("/home/iit/Desktop/s.txt","r");
   FILE * fpout = fopen("/home/iit/Desktop/v.txt","w");

   if (fp == NULL){
        printf("Could not open file %s","/home/iit/Desktop/s.txt");
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
      encryptedValue = encryptor((int)in);
      fprintf(fpout, "%c", encryptedValue);
   }
   /* write 10 lines of text into the file stream*/
   
 
   /* close the file*/  
   fclose (fp);
   return 0;
}
