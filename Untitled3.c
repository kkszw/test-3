#include<stdio.h>
#include<string.h>

char q[10][10]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
char w[15][10]={"仟亿","佰亿","拾亿","亿","仟万","佰万","拾万","万","仟","佰","拾","元","角","分","整"};

void main()
{
    int a[12],b[2],temp,temp1,flag=0,zero_flag=0;
    double money=0,tmp,tmp1;
    char s[24][100]={""};
    printf("请输入人民币(0~999 999 999 999.99):");
    scanf("%lf",&money);
    if(money<0)
    {
        printf("不可小于0！\n");
        return;
    }
    temp=money;//取整
    tmp=money-temp;//取小数
    for(int i=0;i<2;i++)
    {
        b[i]=tmp*10;
        tmp=tmp*10-b[i];
    }
    for(int i=11;i>=0;i--)
    {
        a[i]=temp%10;
        temp=temp/10;
    }
    printf("人民币");

    for(int i=0;i<12;i++)
    {
        if(a[i]!=0)
            zero_flag=1;//找第一个不为0
        if(zero_flag==1)
        {
            if(i!=0)
                    strcat(s[i],s[i-1]);
            if(a[i]==0)
            {
                if(flag==1)//两个及以上都是0
                {
                    if(i==7&&a[i+1]!=0)//如果万位及以前是0但千位不是
                    {
                        strcpy(s[i],s[i-1]);//去0
                        strcat(s[i],w[7]);
                    }
                    else if(i==11&&b[0]!=0)//如果元位及以前是0但角不是
                    {
                        strcpy(s[i],s[i-2]);//去0
                        strcat(s[i],w[11]);
                    }
                    else
                    {
                        if(a[i+1]==0)
                        {
                            strcpy(s[i],s[i-2]);
                        }
                    }
                }
                else//只有一个是0
                {
                    if(i==11)//0在元
                    {
                        strcat(s[i],w[11]);
                    }
                    else if(i==7)//0在万
                    {
                        strcat(s[i],q[0]);
                    }
                    else
                        strcat(s[i],q[0]);
                }
                flag=1;
            }
            else
            {
                strcat(s[i],q[a[i]]);
                strcat(s[i],w[i]);
                flag=0;
            }

        }
    }
    if(zero_flag==0)
    {
        strcat(s[11],q[0]);
        strcat(s[11],w[11]);
    }
    if(b[0]==0&&b[1]==0)
        strcat(s[11],w[14]);
    else
    {
        if(b[0]==0)
        {
            strcat(s[11],q[0]);
        }
        else
        {
            strcat(s[11],q[b[0]]);
            strcat(s[11],w[12]);
        }
        if(b[1]!=0)
        {
            strcat(s[11],q[b[1]]);
            strcat(s[11],w[13]);
        }
    }
    printf("%s",s[11]);
}
