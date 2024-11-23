#include<stdio.h>

int main()
{
    int vah;
    float hr,rate;

    printf(" for car press-1\n for bike press-2\n");
    scanf("%d",&vah);

    switch(vah)
    {
         case(1):
        printf("for how much long do you want to park your car\n");
        scanf("%f",&hr);
        rate= hr*10;
        printf("total fee- %f rs for %f hours\n",rate,hr);

        break;

         case(2):
        printf("for how much long do you want to park your bike\n");
        scanf("%f",&hr);
        rate= hr*5;
        printf("total fee- %f rs for %f hours\n",rate,hr);

        break;

    }



   return 0;
}
