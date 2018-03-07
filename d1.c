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
char decryptor(int msg){

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
   while(1){
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
    printf("%d ",(int) m);
    return (char)m;
   }



int main ()
{
   FILE * fp;
   char in;
   int decryptedValue;
   char* filename = ("out.txt");
   /*open the file for writing*/
   fp = fopen (filename,"r");
   FILE * fpout = fopen("input1.txt","w");

   if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    if (fpout == NULL){
        printf("Could not open output file");
        return 1;
    }
    //while (fgets(str, LEN, fp) != NULL)
      //  printf("%s", str);
   printf("starting to read file\n");
  
   while((in= fgetc(fp))!=EOF){
  
      decryptedValue = decryptor((int)in);
      fprintf(fpout, "%d", decryptedValue);
    
   }
   /* write 10 lines of text into the file stream*/
   
 
   /* close the file*/  
   fclose (fp);
   fclose(fpout);
   return 0;
}
