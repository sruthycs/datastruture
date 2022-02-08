#include<stdio.h>
#include<stdlib.h>
void main()
{
    int m,n,ch;
    printf("Enter the length of set 1 : ");
    scanf("%d",&m);
    printf("Enter the length of set 2 : ");
    scanf("%d",&n);
    int a[m],b[n],NB[m],c[100],i;
    if(m==n)
    {
        printf("Enter the elements for set 1 (1 or 0) : ");
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        printf("Enter the elements for set 2 (1 or 0) : ");
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        do
        {
            printf("\n1. Intersection\n2. Union\n3. Difference\n4. exit\nEnter your Choice : ");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                printf("The Intersection of 2 sets are : {");
                for(i=0;i<m;i++)
                {
                    if(a[i]==1 && b[i]==1)
                    {
                        c[i]=1;
                    }
                    else
                    {
                        c[i]=0;
                    }
                    printf("%4d,",c[i]);
                }printf("}");
                break;

            case 2:
                printf("The Union of 2 sets are : {");
                for(i=0;i<m;i++)
                {
                    if(a[i]==1 || b[i]==1)
                    {
                        c[i]=1;
                    }
                    else
                    {
                        c[i]=0;
                    }
                    printf("%4d",c[i]);
                }
                printf("}");
                break;

            case 3:
                printf("The Difference of 2 sets are : {");
                for(i=0;i<m;i++)
                {
                    if(b[i]==1)
                        NB[i]=0;
                    else
                        NB[i]=1;
                }
                for(i=0;i<m;i++)
                {
                    if(a[i]==1 && NB[i]==1)
                        c[i]=1;
                    else
                        c[i]=0;
                    printf("%4d,",c[i]);
                }
                printf("}");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice made!.");
            }
        }while(ch!=4);
    }
    else
    {
        printf("size must be equal for bitwise operation!\nExiting...");
    }
}
