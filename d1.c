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
 
   
   double e=2;

   
   while(1){
   count = gcd(e,totient);
   if(count==1)
     break;
   else
     e++;
   }

    
    double k = 2;
 
    
    d = (1 + (k*totient))/e;
    
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
   
   printf("starting to read file\n");
  
   while((in= fgetc(fp))!=EOF){
  
      decryptedValue = decryptor((int)in);
      fprintf(fpout, "%d", decryptedValue);
    
   }
  
 
  
   fclose (fp);
   fclose(fpout);
   return 0;
}
