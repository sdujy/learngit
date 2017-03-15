//
//  main.cpp
//  example
//
//  Created by apple on 17/2/22.
//  Copyright © 2017年 apple. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include <ctype.h>
int main()
{
    int tot=0;
    while(true)
    {
        tot++;
        int r,c;
        int count=1;
        scanf("%d",&r);
        if(r==0)    break;
        scanf("%d",&c);
        char s[r][c+1];
        int a[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                a[i][j]=0;
        }
        if(r==0)    break;
        for(int i=0;i<r;i++)
        {
            scanf("%s",s[i]);
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i-1<0 && s[i][j]!='*')
                {
                    a[i][j]=count;
                    count++;
                }
                else
                {
                    if(j-1<0 && s[i][j]!='*')
                    {
                        a[i][j]=count;
                        count++;
                    }
                    else if((s[i][j-1]=='*'||s[i-1][j]=='*') && s[i][j]!='*')
                    {
                        a[i][j]=count;
                        count++;
                    }
                    
                }
            }
        }
        if(tot==1)
        {
             printf("puzzle #%d:\nAcross",tot);
        }
        else
        {
            printf("\npuzzle #%d:\nAcross",tot);

        }
        for(int i=0;i<r;i++)
        {
            int first=1;
            for(int j=0;j<c;j++)
            {
                if(first && isalpha(s[i][j]))
                {
                    if(a[i][j]<10)
                    {
                        printf("\n  %d.%c",a[i][j],s[i][j]);
                        first=0;
                    }
                    else
                    {
                        printf("\n %d.%c",a[i][j],s[i][j]);
                        first=0;
                    }
                }
                else if(isalpha(s[i][j]))
                {
                    printf("%c",s[i][j]);
                }
                else
                {
                    first=1;
                }
            }
            
        }
        printf("\nDown");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(isalpha(s[i][j]) && a[i][j]!=0)
                {
                    if(a[i][j]<10)
                    {
                        printf("\n  %d.%c",a[i][j],s[i][j]);
                    }
                    else
                    {
                        printf("\n %d.%c",a[i][j],s[i][j]);
                    }
                    int temp=i+1;
                    while(temp<r && s[temp][j]!='*')
                    {
                        printf("%c",s[temp][j]);
                        a[temp][j]=0;
                        temp++;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
