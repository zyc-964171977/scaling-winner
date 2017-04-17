#include <stdio.h>
#include <stdlib.h>
#include <string.h>            //支持字符串操作
#define  MAX  18               //表示妃子最大数量
int main()
{
    int i,j,temp;              //循环变量和临时变量
    int searchIndex = -1;      //用来存放要查找的元素的下标
    int count = 12;            //当前未打入冷宫的妃子个数
    int choice;                //皇帝的选择1~4
    char emperor[50];          //皇帝的名字
    char temp_imperial_concubine[20];//临时数组
    char imperial_concubine[MAX][20] = {"西施","杨玉环","貂蝉","王昭君","冯小怜","雏田","苏妲己","赵飞燕","郑旦","褒姒","天天","红莲"};//imperial concubine 皇妃
    printf("请输入皇帝的名字:\n");
    scanf("%s",emperor);
    printf("%s陛下驾到\n\n",emperor);
    //printf("请输入妃子的名称:%s\n",imperial_concubine[20][20]);
    //scanf("%s",imperial_concubine[20][20]);
    char imperial_concubine_level[MAX][10] = {"淑女","选侍","贵人","才子","美人","婕妤","昭仪","嫔","妃","贵妃","皇贵妃","皇后"};//妃子的级别
    int levels[MAX] = {0,1,2,3,4,5,6,7,8,9,10,11,12,-1}; //用来存放每位妃子的级数。每个数组元素对应每个妃子的当前级数
    int loves[MAX] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,-1};      //妃子的好感度，初始值为100

    printf("当前嫔妃的级别为:\n");
    printf("姓名\t\t级别\t\t好感度\n");
    for(i = 0;i < count;i++)
    {
    printf("%s\t\t%s\t\t%d\n",imperial_concubine[i],imperial_concubine_level[levels[i]],loves[i]);
    }

    printf("\n");
    printf("陛下，您改该翻牌了:\n");
    printf("1、皇帝下旨选妃\t\t（增加状态）\n");
    printf("2、翻牌宠幸\t\t(修改状态)\n");
    printf("3、打入冷宫\t\t(删除功能)\n");
    printf("4、单独召见爱妃\n\n");
    printf("陛下请选择:\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1://皇帝下旨选妃\t\t（增加状态）
        //1、增加前需要判断数组有没有空间
        //2、增加数组元素（imperial_concubine、levels、loves）
        if(count < MAX)         //如果当前妃子的数量小于系统的最大值
        {
            //执行添加操作
            printf("陛下，请输入娘娘的名讳：\n");
            scanf("%s",imperial_concubine[count]);
            //将第count个元素初始化
            levels[count]=0;            //级别初始化0
            loves[count]=100;           //好感度初始化100
            count++;                    //添加完元素后，记得添加计数器
        }
        else
        {
            printf("陛下，请注意龙体！\n");
        }
        break;
    case 2://翻牌宠幸\t\t(修改状态)
        //1、找到要宠幸的妃子的下标
        //2、修改这个妃子的状态   好感度+10、级别+1
        //3、修改其他妃子的状态   好感度-10
        printf("陛下，请输入要宠幸的妃子的名讳:\n");
        scanf("%s",temp_imperial_concubine);
        //字符串的查找strcmp,需要引入<string.h>
        //strcmp(temp_imperial_concubine,"abc")  0-两个字符串相等；1-前一个大于后一个； -1-前一个小于后一个
        for(i = 0;i <count; i++)
        {
            if(strcmp(temp_imperial_concubine,imperial_concubine[i])==0)//如果输入的姓名刚好等于数组中的某个名字
            {
                loves[i] += 10;
                levels[i] =levels[i]>= 10 ? 10 : levels[i]+1;
            }
            else
            {
                loves[i] -= 10;
            }
        }
        break;
    case 3://打入冷宫\t\t(删除功能)
        //1、查找要删除的妃子的名字
        //2、后面一个赋给前面一个
        //3、总数--
        printf("请输入要打入冷宫的妃子的名讳:\n");
        scanf("%s",temp_imperial_concubine);
        //循环查找
        for(i = 0;i < count; i++)
        {
            if(strcmp(temp_imperial_concubine,imperial_concubine[i])==0)
            {
                searchIndex = i;
                break;
            }
        }
        if(-1 == searchIndex)//如果searchIndex的值为初值，表示没有找到
        {
            printf("皇宫中没有这位妃子！\n");
        }
        else
        {
            for(i = searchIndex;i < count - 1;i++)
            {
                //imperial_concubine[i] = imperial_concubine[i+1];
                //因为是字符数组，C语言中不支持数组的直接赋值
                //需要用strcpy函数来实现数组的赋值
                strcpy(imperial_concubine[i],imperial_concubine[i + 1]);
                levels[i] = levels[i+1];
                loves[i] = loves[i+1];
            }
            count--;
        }
        break;
    case 4://单独召见爱妃
        //1、查找
        //2、增加好感度
        //3、吟诗几首
        printf("陛下下密旨，单独召见妃子：\n");
        scanf("%s",temp_imperial_concubine);
        for(i = 0;i < count;i++)
            if(strcmp(temp_imperial_concubine,imperial_concubine[i])==0)
        {
            levels[i]+=10;
            loves[i]+=10;
            printf("关关雎鸠，在河之洲。窈窕淑女，君子好逑。\n");
        }
        break;
    default:
        printf("君无戏言，请陛下重新选择:\n");
    }
    //打印所有妃子的状态前，以级别进行排序，使用冒泡排序
    for(i = 0;i < count-1;i++)
    {
        for(j = 0;j < count - i -1;j++)
        {
            if(levels[j]==levels[j + 1])
            {
            //需要交换三个：姓名、级别、好感度
            strcpy(temp_imperial_concubine,imperial_concubine[j]);
            strcpy(imperial_concubine[j],imperial_concubine[j + 1]);
            strcpy(imperial_concubine[j + 1],temp_imperial_concubine);

            temp = levels[j];
            levels[j] = levels[j + 1];
            levels[j + 1] = temp;

            temp = loves[j];
            loves[j] = loves[j + 1];
            loves[j + 1] = temp;
            }
        }
    }

    printf("当前嫔妃的级别为:\n");
    printf("姓名\t\t级别\t\t好感度\n");
    for(i = 0;i < count;i++)
    {
    printf("%s\t\t%s\t\t%d\n",imperial_concubine[i],imperial_concubine_level[levels[i]],loves[i]);
    }
    printf("\n今日就到这了，众爱妃一个一个来\n");
    system("pause");
    return 0;
}
