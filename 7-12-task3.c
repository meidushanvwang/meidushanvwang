#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cs50.h>
#define N 20

bool Luhn(string s);
int getLenth(string s);
void toArray(string s ,int arr[N]);
bool inSafe(int arr[N] ,int n);

int main(void)
{
    int n ,i ,IDcode[N];
    string ID;

    ID = get_string("Numbers:");//get card ID
    n = getLenth(ID);//get ID size
    toArray(ID,IDcode);//convert ID int IDcode(array)
    while(inSafe(IDcode,n) == false)
    {
        ID = get_string("Retry:");//get card ID
        n = getLenth(ID);//get ID size
        toArray(ID,IDcode);//convert ID int IDcode(array)
    }//Retry if input unsafe

    // printf("IDstr:%s\n",ID);
    // printf("convert result:%lu\n",strtol(ID, NULL, 10));
    // printf("IsLuhn?:%d\n",Luhn(ID));
    // printf("IDcode:");
    // for(i=0;i<N;i++)
    //     printf("%d ",IDcode[i]);
    // printf("sizeofIDcode:%d\n",n);
    // printf("\n");

    if(Luhn(ID) == 1/*condition of valid card*/)
    {
        if(n==15 && (IDcode[n-1]==3 && (IDcode[n-2]==4 || IDcode[n-2]==7))/*condition of AmericanExpress*/)
            printf("AMEX\n");
        else if(n==16 && (IDcode[n-1]==5 && (IDcode[n-2]>=1 && IDcode[n-2]<=5))/*condition of MasterCard*/)
            printf("MASTERCARD\n");
        else if((n==13 || n==16) && IDcode[n-1]==4/*condition of Visa*/)
            printf("VISA\n");
        else
            printf("UNKNOW\n");
    }
    else
    {
        printf("INVALID\n");
    }// recognize the type of card

    return 0;
}

bool Luhn(string s)
{
     int oddSum=0,evenSum=0;
     int i;
     for(i=strlen(s)-1;i>=0;i-=2)
     {
         oddSum+=(s[i]-48);
     }
     for(i=strlen(s)-2;i>=0;i-=2)
     {
         int wenum=2*(s[i]-48);
         if(wenum>=10)
         {
             evenSum+=(wenum-9);
         }else{
             evenSum+=wenum;
         }
     }
     if((evenSum+oddSum)%10==0)
     {
         return 1;
     }else{
         return 0;
     }
}//luhn for string

int getLenth(string s)
{
    int n;
    n = strlen(s);
    return n;
}

void toArray(string s, int arr[N])
{

    for(int i=0 ; i<N ; i++)
    {
        arr[i] = s[i]-48;
    }
}

bool inSafe(int arr[N] ,int n)
{
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]<0 || arr[i]>9)
            return false;
    }
    return true;
}