#include<stdlib.h>
#include<stdio.h>
int main()
{
    int l;
    printf("enter the size of string \n");
    scanf("%d", &l);
    printf("enter the string \n");
    char c[l]; scanf("%s", c);
    int f; printf("FRAME SIZE  "); scanf("%d", &f);
    int cnt = 0;
    int arr[f]; int page_fault = 0;
    for (int i = 0; i < l; i++)
    {
        int p = (int)(c[i] - '0');
        //find page
        int fl = 0;
        for (int j = 0; j < cnt; j++)
        {
            if (arr[j] == p)
            {fl = 1; break;}
        }
        if (fl == 0)
        {
            //if empty
            if (f > cnt)
            {
                arr[cnt] = p;
                cnt++;
            }
            else
            {
                for (int j = 1; j < f; j++)
                    arr[j - 1] = arr[j];
                arr[f - 1] = p;
            }
            page_fault++;
        }
    }
    printf("page fault is %d", page_fault);
    printf("\n");
    return 0;
}