#include <stdio.h>
#include <stdlib.h>
#include <string.h>            //֧���ַ�������
#define  MAX  18               //��ʾ�����������
int main()
{
    int i,j,temp;              //ѭ����������ʱ����
    int searchIndex = -1;      //�������Ҫ���ҵ�Ԫ�ص��±�
    int count = 12;            //��ǰδ�����乬�����Ӹ���
    int choice;                //�ʵ۵�ѡ��1~4
    char emperor[50];          //�ʵ۵�����
    char temp_imperial_concubine[20];//��ʱ����
    char imperial_concubine[MAX][20] = {"��ʩ","����","����","���Ѿ�","��С��","����","��槼�","�Է���","֣��","���","����","����"};//imperial concubine ����
    printf("������ʵ۵�����:\n");
    scanf("%s",emperor);
    printf("%s���¼ݵ�\n\n",emperor);
    //printf("���������ӵ�����:%s\n",imperial_concubine[20][20]);
    //scanf("%s",imperial_concubine[20][20]);
    char imperial_concubine_level[MAX][10] = {"��Ů","ѡ��","����","����","����","��","����","��","��","����","�ʹ���","�ʺ�"};//���ӵļ���
    int levels[MAX] = {0,1,2,3,4,5,6,7,8,9,10,11,12,-1}; //�������ÿλ���ӵļ�����ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
    int loves[MAX] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,-1};      //���ӵĺøжȣ���ʼֵΪ100

    printf("��ǰ�����ļ���Ϊ:\n");
    printf("����\t\t����\t\t�øж�\n");
    for(i = 0;i < count;i++)
    {
    printf("%s\t\t%s\t\t%d\n",imperial_concubine[i],imperial_concubine_level[levels[i]],loves[i]);
    }

    printf("\n");
    printf("���£����ĸ÷�����:\n");
    printf("1���ʵ���ּѡ��\t\t������״̬��\n");
    printf("2�����Ƴ���\t\t(�޸�״̬)\n");
    printf("3�������乬\t\t(ɾ������)\n");
    printf("4�������ټ�����\n\n");
    printf("������ѡ��:\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1://�ʵ���ּѡ��\t\t������״̬��
        //1������ǰ��Ҫ�ж�������û�пռ�
        //2����������Ԫ�أ�imperial_concubine��levels��loves��
        if(count < MAX)         //�����ǰ���ӵ�����С��ϵͳ�����ֵ
        {
            //ִ����Ӳ���
            printf("���£���������������䣺\n");
            scanf("%s",imperial_concubine[count]);
            //����count��Ԫ�س�ʼ��
            levels[count]=0;            //�����ʼ��0
            loves[count]=100;           //�øжȳ�ʼ��100
            count++;                    //�����Ԫ�غ󣬼ǵ���Ӽ�����
        }
        else
        {
            printf("���£���ע�����壡\n");
        }
        break;
    case 2://���Ƴ���\t\t(�޸�״̬)
        //1���ҵ�Ҫ���ҵ����ӵ��±�
        //2���޸�������ӵ�״̬   �øж�+10������+1
        //3���޸��������ӵ�״̬   �øж�-10
        printf("���£�������Ҫ���ҵ����ӵ�����:\n");
        scanf("%s",temp_imperial_concubine);
        //�ַ����Ĳ���strcmp,��Ҫ����<string.h>
        //strcmp(temp_imperial_concubine,"abc")  0-�����ַ�����ȣ�1-ǰһ�����ں�һ���� -1-ǰһ��С�ں�һ��
        for(i = 0;i <count; i++)
        {
            if(strcmp(temp_imperial_concubine,imperial_concubine[i])==0)//�������������պõ��������е�ĳ������
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
    case 3://�����乬\t\t(ɾ������)
        //1������Ҫɾ�������ӵ�����
        //2������һ������ǰ��һ��
        //3������--
        printf("������Ҫ�����乬�����ӵ�����:\n");
        scanf("%s",temp_imperial_concubine);
        //ѭ������
        for(i = 0;i < count; i++)
        {
            if(strcmp(temp_imperial_concubine,imperial_concubine[i])==0)
            {
                searchIndex = i;
                break;
            }
        }
        if(-1 == searchIndex)//���searchIndex��ֵΪ��ֵ����ʾû���ҵ�
        {
            printf("�ʹ���û����λ���ӣ�\n");
        }
        else
        {
            for(i = searchIndex;i < count - 1;i++)
            {
                //imperial_concubine[i] = imperial_concubine[i+1];
                //��Ϊ���ַ����飬C�����в�֧�������ֱ�Ӹ�ֵ
                //��Ҫ��strcpy������ʵ������ĸ�ֵ
                strcpy(imperial_concubine[i],imperial_concubine[i + 1]);
                levels[i] = levels[i+1];
                loves[i] = loves[i+1];
            }
            count--;
        }
        break;
    case 4://�����ټ�����
        //1������
        //2�����Ӻøж�
        //3����ʫ����
        printf("��������ּ�������ټ����ӣ�\n");
        scanf("%s",temp_imperial_concubine);
        for(i = 0;i < count;i++)
            if(strcmp(temp_imperial_concubine,imperial_concubine[i])==0)
        {
            levels[i]+=10;
            loves[i]+=10;
            printf("�ع���𣚣�ں�֮�ޡ�����Ů�����Ӻ��ϡ�\n");
        }
        break;
    default:
        printf("����Ϸ�ԣ����������ѡ��:\n");
    }
    //��ӡ�������ӵ�״̬ǰ���Լ����������ʹ��ð������
    for(i = 0;i < count-1;i++)
    {
        for(j = 0;j < count - i -1;j++)
        {
            if(levels[j]==levels[j + 1])
            {
            //��Ҫ�������������������𡢺øж�
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

    printf("��ǰ�����ļ���Ϊ:\n");
    printf("����\t\t����\t\t�øж�\n");
    for(i = 0;i < count;i++)
    {
    printf("%s\t\t%s\t\t%d\n",imperial_concubine[i],imperial_concubine_level[levels[i]],loves[i]);
    }
    printf("\n���վ͵����ˣ��ڰ���һ��һ����\n");
    system("pause");
    return 0;
}
