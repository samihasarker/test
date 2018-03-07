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



char encryptor(int msg){
   double p = 3;
   double q = 7;
   double n=p*q;
   double count;
   double totient = (p-1)*(q-1);

   double e=2;

  
   while(1){
   count = gcd(e,totient);
        if(count==1)
            break;
        else
        e++;
   }
   double c = pow((double)msg,(double)e);
   c=fmod((double)c,(double)n);
   printf("%d ",(int) c);
   
        return (char)c;

}

int main ()
{
   FILE * fp;
   char in;
   int encryptedValue;
   char* filename = "h.txt";
  
   fp = fopen (filename,"r");
   FILE * fpout = fopen("out.txt","w");

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
            printf(" %d   \n",in);
            encryptedValue = encryptor(in);
            fprintf(fpout, "%d\n", encryptedValue);
      
    
   }
   
   fclose (fp);
   fclose(fpout);
        return 0;
}
