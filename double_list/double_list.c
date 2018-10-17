#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>


typedef struct Student
{
    int  ID;
    char name[20];
    int  score;
    char phoneNum[14];
} str_student;

typedef struct Node
{
    str_student data;
    struct Node *prior;     //指向前驱结点
    struct Node *next;     //指向后继结点
}Node, *DLinkList;

// 初始化一个学生链表
DLinkList initDouLinkList()
{
    Node *L,*p,*r;
    char name[20];
    char phone[14];
    int score = 0;
    int id    = 0;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    r = L;
    r->next = NULL;

    while(1)
    {
        p = (Node *)malloc(sizeof(Node));
        printf("input name is out exit,input student name:\n");
        scanf("%s",name);
        if (strcmp(name,"out")==0)
        {
            break;
        }
        strcpy(p->data.name, name);
        
        printf("input student ID:");
        scanf("%d",&id);
        p->data.ID = id;
        
        printf("input student score:");
        scanf("%d",&score);
        p->data.score = score;

        printf("input student phone:");
        scanf("%s",phone);
        strcpy(p->data.phoneNum, phone);
                                                                   
                                                                    
        p->next = r->next;
        p->prior = r;
        r->next = p;
        r = p;                
        
    }
    r->next = NULL;
    return L;
}

//添加学生信息
DLinkList insertDouLinkListStuent(DLinkList L,int i,char *name, int score,char *phonenum)
{
    DLinkList p,s;
    p = L->next;
    int tempi;
    for(tempi = 1;tempi < i-1; tempi++)
        p = p->next;

    s = (Node *)malloc(sizeof(Node));
    s->data.score = score;
    strcpy(s->data.name,name);
    strcpy(s->data.phoneNum,phonenum);
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;

    return L;
}

// 查找学生信息
int findDouLinkListStudent(DLinkList L)
{
    DLinkList p;
    p = L->next;
    int i = 1;
    char name[20];

    printf("Please input the name of the student you are looking for:\n");
    scanf("%s",name);
       
        
    while(p != NULL && (strcmp(p->data.name, name)!=0))
    {
        ++i;
        p = p->next;
    }
    if(p == NULL)
    {
        printf("No student:%s \n", name);
        return 0;
    }
    else 
    {
        printf("%-20s %-20s %-20s %-20s\n", "ID","name", "score", "phoneNum");
        printf("%-20d %-20s %-20d %-20s\n", p->data.ID, p->data.name, p->data.score, p->data.phoneNum);
        return i;
    }
}

// 查找学生信息
int findDouLinkListStudentByID(DLinkList L)
{
    DLinkList p;
    p = L->next;
    int i = 1;
    int id = 0;

    printf("Please input the ID of the student you are looking for:\n");
    scanf("%d", &id);
       
        
    while(p != NULL && p->data.ID != id)
    {
        ++i;
        p = p->next;
    }
    if(p == NULL)
    {
        printf("No student:%d \n", id);
        return 0;
    }
    else 
    {
        printf("%-20s %-20s %-20s %-20s\n", "ID","name", "score", "phoneNum");
        printf("%-20d %-20s %-20d %-20s\n", p->data.ID, p->data.name, p->data.score, p->data.phoneNum);
        return id;
    }
}

// 移除一个学生
DLinkList removeDouLinkListStudent(DLinkList L)
{
    int tempi = 0;
    DLinkList p;
    p = L->next;
    int i =findDouLinkListStudentByID(L);

    while(p->data.ID != i && p != NULL)
    {
        p = p->next;
    }

    if(p == NULL)
    {
        printf("no list \n");
    }
    else if(p->next == NULL)
    {
        p->prior->next = NULL;
        free(p);
    }
    else
    {
        p->prior->next = p->next;
        p->next->prior = p->prior;
        free(p);
    }
    return L;
}


// 铺助打印信息
void printfInfo(DLinkList L)
{
    DLinkList p;
    p = L->next;
    printf("************************************************\n");
    printf("********************info************************\n");
    printf("************************************************\n");
    printf("%-20s %-20s %-20s %-20s\n", "ID", "name", "score", "phoneNum");
    while (p!=NULL)
    {
        printf("%-20d %-20s %-20d %-20s\n", p->data.ID, p->data.name, p->data.score, p->data.phoneNum);
        //printf("student name %s\n",p->data.name);
        //printf("student score %d\n",p->data.score);
        //printf("student phone %s\n",p->data.phoneNum);
        p=p->next;
    }
}


void main ()
{
    char name2[20]="hanmeimei";
    char phone2[14]="13612345678";
     
      
    DLinkList L =initDouLinkList();
    // 2.1 初始化学生双向链表数据
//    insertDouLinkListStuent(L,1,name2,99,phone2);
    printfInfo(L);
               
                
    // 2.2 查找学生zhangsan
    findDouLinkListStudent(L);
    //printfInfo(L);
                       
                        
    // 2.3 删除学生zhangsan
    removeDouLinkListStudent(L);
    printfInfo(L);
                               
                                
    // 2.4 添加学生zengteng
//    insertDouLinkListStuent(L,9,'zengteng',89,'13643345667');
//    printfInfo(L);
                                       
                                        
}

