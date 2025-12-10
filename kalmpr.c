#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef MAXK
    #define MAXK 5
#endif
#ifndef MINNUM
    #define MINNUM 2100000000
#endif
#ifndef MAXNUM
    #define MAXNUM 2101000000
#endif
#ifndef COMPUTATIONS
    #define COMPUTATIONS 20
#endif


int main()
{
    int n,k,temp,primedivisor,countk,count2,lastprimedivisor,firstprimedivisor,d,i,x,y,z;
    long curtime;
    printf("Checking numbers in [%d,%d]\n\n",MINNUM,MAXNUM);
    countk=0;                                                                        /*initialize count of k-almost-primes*/
    count2=0;                                                                        /*initialize count of semiprimes*/
    for (n=MINNUM;n<=MAXNUM;n++)                                                     /*for all numbers of given range*/ 
    {                                                                                   
        temp=n;                                                                      /*store the given number in temp which will be continuously divided*/                                                                         
        k=0;                                                                         /*initialize k(count of primedivisors)*/
        while(temp%2==0&&k<=MAXK - 1)                                                /*if temp (which initially is given number) is divided by 2 and the primedivisor count(k)<=MAXK-1*/
        {
            temp=temp/2;                                                             /*divide temp by 2 (factorize by 2)*/
            k++;                                                                     /*raise k by 1 because a primedivisor is found*/
            if(temp!=1 && k==1)                                                      /*if number is not yet factorized and when the first prime divisor is found*/     
            {   
                firstprimedivisor=2;                                                 /*store the first prime divisor (this will be used for showing the factors of semiprimes)*/
                lastprimedivisor=temp;                                               /*store the last temp which inevitably is prime divisor (as it is the first symmetrical divisor after the sqrt) w/o adding to k (this will be done later)*/
            }                                                                        
        }
        while(temp%3==0&&k<=MAXK - 1)                                                /*do the same for 3*/
        {
            temp=temp/3;
            k++;
            if(temp!=1 && k==1)
            {
                firstprimedivisor=3;
                lastprimedivisor=temp;
            }
        }
        primedivisor=5;                                                             /*move on to the next prime divisor*/
        while(primedivisor*primedivisor<=n && k<=MAXK-1)                            /*while primedivisor<=sqrt(n) and k does not exceed given range */       
        {
            while (temp%primedivisor==0 && k<=MAXK - 1)                             /*as long as (the already factorized number) is divided by the potential prime divisor */
            {
                k++;                                                                /*add 1 primedivisor*/
                temp=temp/primedivisor;                                             /*do the respective division*/
                if (temp!=1 && k==1)                                                            
                {                                                                   /*THIS IF IS FUNDAMENTAL FOR SEMIPRIMES*/
                  firstprimedivisor=primedivisor;                                   /*store the first prime divisor (this will be used for showing the factors of semiprimes)*/
                  lastprimedivisor=temp;                                            /*store the last temp which is proven to be primedivisor (as it is the first symmetrical divisor after the sqrt)*/
                }
            }
            while (temp%(primedivisor+2)==0 && k<=MAXK -1)                          /*do the same for primedivisor+2 (next potential primedivisor)*/
            {
                k++;
                temp=temp/(primedivisor+2);
                if (temp!=1 && k==1)
                {                                                                   /*THIS IF IS FUNDAMENTAL FOR SEMIPRIMES*/
                  firstprimedivisor=(primedivisor+2);
                  lastprimedivisor=temp;  
                }
            }
            primedivisor +=6;                                                       /*raise primedivisor by 6*/
        }                                                                                   
        if (temp!=1 && k<=MAXK -1)                                                  /*if number is not completely factorized and k is in whithin range*/
        {
            k++;                                                                    /*add the remaining prime divisor(after the process of factorizing the last temp is prime)*/
            temp=1;                                                                 /*temp=temp/temp(temp is the lastprimedivisor)*/
        }                                                                           
        if(temp==1 && k>=2 && k<=MAXK)                                              /*if temp is completely factorized and k within range*/
        {
            countk++;                                                               /*raise the total sum of k almost number by 1*/
            if (k==2)                                                               /*if number is semiprime*/
            {
                count2++;                                                           /*raise sum of semiprimes by 1*/
                d=lastprimedivisor-firstprimedivisor;                               /*store the distance between the prime divisors of the semiprime number*/
                if (d<=(0.01*lastprimedivisor) && lastprimedivisor!=firstprimedivisor)   /*if distance is no greater than the 1% of the "big"primedivisor and the 2 divisors are differnt*/
                {
                    printf("%d * %d = %d is an interesting semiprime\n",firstprimedivisor,lastprimedivisor,n);  /*print both the factors and the semiprime*/
                }
            }
        }
    }    
    printf("\nFound %d k-almost prime numbers (2<=k<=%d)\n",countk,MAXK);           /*print the sum od k-almost-primes*/
    printf("Found %d semiprimes\n",count2);                                         /*print the sum of semiprimes*/
    
    /*SECOND PHASE*//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
    
    curtime=time(NULL);                                                             /*unix time*/
    srand((unsigned int) curtime);                                                  /*seed is the unix time*/
    printf("\nCurrent time is %ld\n\n",curtime);                                    /*print the current unix time*/
    printf("Checking %d random numbers\n\n",COMPUTATIONS);                          /*message to be displayed*/
    for (i=1;i<=COMPUTATIONS;i++)                                                   /*for all numbers defined by computations*/
    {
        y=rand();                                                                   /*first random number*/
        z=rand();                                                                   /*second random number*/
        x=((y%32768)+1)*((z%32768)+1)+1;                                            /*final random number as described*/
        temp=x;                                                                     /*from now on follow the same process as above for the calculation of k*/
        k=0;
        while(temp%2==0)                                                            /*ONLY DIFFERENCE IS THAT K IS NOT BETWEEN A SPECIFIC RANGE*/
        {
            temp=temp/2;
            k++;
            if(temp!=1)
            {
                firstprimedivisor=2;
                lastprimedivisor=temp;
            }
        }
        while(temp%3==0)
        {
            temp=temp/3;
            k++;
            if(temp!=1)
            {
                firstprimedivisor=3;
                lastprimedivisor=temp;
            }
        }
        primedivisor=5;
        while(primedivisor*primedivisor<=n)
        {
            while (temp%primedivisor==0)
            {
                k++;
                temp=temp/primedivisor;
                if (temp!=1)
                {
                  firstprimedivisor=primedivisor;
                  lastprimedivisor=temp;  
                }
            }
            while (temp%(primedivisor+2)==0)
            {
                k++;
                temp=temp/(primedivisor+2);
                if (temp!=1)
                {
                  firstprimedivisor=(primedivisor+2);
                  lastprimedivisor=temp;  
                }
            }
            primedivisor +=6; 
        }
        if (temp!=1)
        {
            k++;
            temp=1;
        }
        printf("%d is a %d-almost prime number\n",x,k);
    }
    
}