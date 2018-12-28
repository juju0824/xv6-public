#include "types.h"
#include "user.h"
#include "date.h"
#include "stat.h"
#include "fs.h"
#include "fcntl.h"


void MakeDigit(int a[]);
void MakeDigit1(int a[]);
int InputGuess(int b[]);
void p_date();
int IsRightPosition(int magic[],int guess[]);
int IsRightDigit(int magic[],int guess[]);
int main1();
int main2();
void menu();
int exitMenu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    char c1;
    clear_screen();
    printf(1,"\n\n\n\n\n");
    printf(1,"\t\t|%c------------------------菜單------------------------%c|\n",15,15);
    printf(1,"\t\t|                                                      |\n");
    printf(1,"\t\t|                                                      |\n");
    printf(1,"\t\t|                      A 人機對戰                      |\n");
    printf(1,"\t\t|                      B 雙人模式                      |\n");
    printf(1,"\t\t|                                                      |\n");
    printf(1,"\t\t|                                                      |\n");
    printf(1,"\t\t|%c-------------------------%c-------------------------%c|\n\n",15,2,15);
    printf(1,"\t\t\t\t  %c選擇(A or B):\n",16);
    printf(1,"\n\n\n");
    printf(1,"\t\t%c規則：A人機對戰系統隨即設定一個各位互異的四位數，玩家根據電腦提示進行猜測!\n",16);
    printf(1,"\t\t       B雙人模式玩家1設定一個各位互異的四位數，玩家2根據玩家1或電腦提示進行猜測!\n");
    scanf(0,"%c",&c1);
    switch(c1)
    {
    case 'A':
        main1();
        break;
    case 'B':
        main2();
        break;
    default:
        menu();
    }

}
int main1()
{
    int a[10];
    int b[4];
    int count;
    int rightDigit;
    int rightPosition;
    int level;
    MakeDigit(a);
    printf(1,"\n");
    printf(1,"%c----------------------%c%c HELLO，歡迎來到猜數字遊戲!-----------------------%c\n",15,2,2,15);
    printf(1,"                                  人機對戰\n");
    printf(1,"\n");

    printf(1,"%c%c 請輸入你想猜的次數：",3,3);
    scanf(0,"%d",&level);
    count=0;
    do
    {
        printf(1,"\n");
        printf(1," %c%c  第%d次!\n",2,2,count+1);
        p_date();
        printf(1,"請輸入一個四位相異的數字：");
        if(InputGuess(b)==0)
        {
            continue;
        }
        count++;
        rightPosition=IsRightPosition(a,b);
        rightDigit=IsRightDigit(a,b);
        rightDigit=rightDigit-rightPosition;
        printf(1,"%d個數對了，而且位置正確\n",rightPosition);
        printf(1,"%d個數對了，但位置不正確\n",rightDigit);
    }
    while(count<level && rightPosition !=4);
    if(rightPosition==4)
    {
        printf(1,"\n");
        printf(1,"%c恭喜你，第%d次就猜對了!\n",2,count);
    }
    else
    {
        printf(1,"\n");
        printf(1," %c真可惜，下次見嘍！\n",2);
    }
    printf(1,"%c%c答案就是 %d%d%d%d\n",2,2,a[0],a[1],a[2],a[3]);
    printf(1,"%c--------------------------拜拜～ %c%c%c------------------------------%c\n",15,2,2,2,15);
    return 0;
}
int main2()
{
    int a[4];
    int b[4];
    int count;
    int rightDigit;
    int rightPosition;
    printf(1,"\n");
    printf(1,"%c----------------------%c%c HELLO，歡迎來到猜數字遊戲！-----------------------%c\n",15,2,2,15);
    printf(1,"                                  雙人模式\n");
    printf(1,"\n");
    printf(1,"%c%c 請輸入你讓他猜的各位互異的四位數：",3,3);
	MakeDigit1(a);
    count=0;
    do
    {
        printf(1,"\n");
        printf(1," %c%c  第%d次!\n",2,2,count+1);
        p_date();
        printf(1,"\n");
        printf(1,"請輸入TA猜的數字：");
        if(InputGuess(b)==0)
        {
            continue;
        }
        count++;
        rightPosition=IsRightPosition(a,b);
        rightDigit=IsRightDigit(a,b);
        rightDigit=rightDigit-rightPosition;
        printf(1,"%d個數對了，而且位置正確\n",rightPosition);
        printf(1,"%d個數對了，但位置不正確\n",rightDigit);
    }
    while(rightPosition !=4);
    if(rightPosition==4)
    {
        printf(1,"\n");
        printf(1,"%c恭喜你，第%d次就猜對了!\n",2,count);
    }
    else
    {
        printf(1,"\n");
        printf(1,"%c真可惜，下次見嘍!\n",2);
    }
    printf(1," %c%c答案就是 %d%d%d%d\n",2,2,a[0],a[1],a[2],a[3]);
    printf(1,"輸入你的選擇：1 重玩   2 退出\n",2);
    exitMenu();
    return 0;
}
void MakeDigit(int a[])
{
    int j, k, temp;
    for(j=0; j<10; j++)
    {
        a[j]=j;
    }
    for(j=0; j<10; j++)
    {
        k=random(0,10000)%10;
        temp=a[j];
        a[j]=a[k];
        a[k]=temp;
    }
}
void MakeDigit1(int a[])
{
    int d,e;
    scanf(0,"%d",&d);
   for(int i=3;i>=0;i--)
   {
	   e=d%10;
	   d=d/10;
	   a[i]=e;
   }
}
int InputGuess(int b[])
{
    int i;
    for(i=0; i<4; i++)
    {
        scanf(0,"%d",&b[i]);
    }
    return 1;
}
int IsRightPosition(int magic[],int guess[])
{
    int rightPosition=0;
    int j;
    for(j=0; j<4; j++)
    {
        if(guess[j]==magic[j])
        {
            rightPosition=rightPosition+1;
        }
    }
    return rightPosition;
}
int IsRightDigit(int magic[],int guess[])
{
    int rightDigit=0;
    int j,k;
    for(j=0; j<4; j++)
    {
        for(k=0; k<4; k++)
        {
            if(guess[j]==magic[k])
            {
                rightDigit=rightDigit+1;
            }
        }
    }
    return rightDigit;
}
void p_date()
{
    struct rtcdate r;
    if (date(&r))
    {
        printf(2, "date failed\n");
        exit();
    }
    printf(1, "%d-%d %d:%d:%d \t%d\n", r.month, r.day, r.hour, r.minute, r.second, r.year);

    exit();
}
int exitMenu(){
    int choice;
        scanf(0,"%d",&choice);
        if(choice==1){
            menu();
        }else{
            printf(1,"%c--------------------------拜拜～%c%c%c------------------------------%c\n",15,2,2,2,15);
            exit();
        }
    return 0;
}