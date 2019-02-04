
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "base.h"
#include "define_my.h"
#include "menu.h"

extern int CurrentCnt;
void OutputAll(GoodList *L)
{
     GoodList *p=L;
     
	 for(;p!=NULL;p=p->next)
	 {
		Goodprint(p);
 	 }
 	 
	 /**
     * 1.对链表内容进行读取，然后输出商品信息
     */
        
}

void info_change(GoodList **L)
{
	 GoodList *p;
	  
	 printf("输入需要修改的商品ID（-1退出查找）：");
	 p=info_search(*L);
	 if(p==NULL)
       return NULL;
     printf("输入新的商品信息: \n");
	 printf("商品ID: ");
	 scanf("%s",p->data.good_id);
	 printf("商品名称:");                 
	 scanf("%s",p->data.good_name);
	 printf("商品价格: ");
	 scanf("%d",&(p->data.good_price));
	 printf("商品折扣: ");
	 scanf("%s",p->data.good_discount);
	 printf("商品数量: ");
	 scanf("%d",&(p->data.good_amount));
	 printf("商品剩余: ");
	 scanf("%d",&(p->data.good_remain));
     
     printf("修改商品信息成功！修改后的商品为：\n");
     Goodprint(p);
}
	 
	     /**                
		 * 1.输入商品的名称，如果名称存在则打印商品信息
         * 2.然后用户输入新的商品信息
         * 3.如果要修改的商品存在并且信息输入结束后则出现修改成功并且重新打印出软件选择界面
         */       



void info_insert(GoodList **L)
{
	 GoodList *p=*L;
	 GoodList *pre=*L;
	 GoodList *new;
	 int location,i=0;
	 new=malloc(sizeof(GoodList));
	 
	 printf("输入您要插入的商品信息：\n");
	 printf("商品ID: ");
	 scanf("%s",new->data.good_id);
	 printf("商品名称: ");
	 scanf("%s",new->data.good_name);
	 printf("商品价格: ");
	 scanf("%d",&(new->data.good_price));
	 printf("商品折扣: ");
	 scanf("%s",new->data.good_discount);
	 printf("商品数量: ");
	 scanf("%d",&(new->data.good_amount));
	 printf("商品剩余: ");
	 scanf("%d",&(new->data.good_remain));
	 printf("输入数字表明你要插入的商品位置：0.商品列表尾部 1.商品列表头部 i.商品列表中间第i号位置");
	 scanf("%d",&location);
	 
	 if(location==1)
	   {new->next=*L;*L=new;printf("\n");}
	 else if(location==0)
	   {for(p=*L;(p->next)!=NULL;p=p->next);
	 	  p->next=new;
	      printf("\n");}
     else
 	 {for(i=1;i<location;i++)
		 	p=p->next;
	 	pre=pre_search(*L,p);
 		new->next=pre->next;
        pre->next=new;
		printf("\n");}
     CurrentCnt++;
}	
	
    /**
     * 1.接收输入的某一条商品的信息，包括ID、名称、价格、折扣、数量、剩余
     * 注：首先通过scanf()函数读入待插入的商品信息的每项数据以换行符来区分信息中的每个条目
     *    分配大小商品信息结构体的内存空间，然后将读入的数据分别拷贝到已分配得到的内存中，
     *    其中字符串的拷贝调用系统函数strcpy。
     *    另外：可以使用前面自定义的read_line函数进行行数据读取
     * 2.分别实现头插法、尾插法，中间位置插入三种，
     * 3.然后根据用户输入的插入方式进行相应的节点位置插入
     * 4.【选作】ID号在插入的时候需要进行查重，如果已经有该ID号了，提示重复
     */



void info_dele(GoodList **L)  
{
	char command,id[MAX_ID_LEN];
	GoodList *p,*pre;
	
	printf("输入需要删除的商品ID(-1退出删除)：");
	p=info_search(*L);
	if(p==NULL)
	 {printf("\n");return NULL;}
	strcpy(id,p->data.good_id);
	printf("是否删除该商品(Y/N):\n");
	scanf(" %c",&command);
	if(command=='y'||command=='Y')
	 {  if(p==*L)
  		{*L=(*L)->next;free(p);}
	  else 
	  {pre=pre_search(*L,p);
	   pre->next=p->next;
	   free(p);
	   printf("Tips:删除ID为%s的商品成功\n",id);
       printf("Tips:当前剩余商品%d个\n\n",CurrentCnt);}
      CurrentCnt--;}
    else
     return NULL;
}
     
     /**
     * 1.输入商品的名称，如果名称存在则删除商品信息，即释放对应指针所指向的内存，
     *   并且将该指针赋值为空，然后打印出删除成功的提示
     * 2.如果输入的商品名称不存在则出现商品不存在的提示
     */





void GoodSearch(GoodList *L)
{
	char name[MAX_NAME_LEN];
	GoodList *p;
	
	printf("输入需要查找的商品名称（-1退出查找）：");
	scanf("%s",name);
	if(strcmp(name,"-1")==0)
	   {printf("\n"); return NULL;}
	for(p=L;p!=NULL;p=p->next)  
	 {
 		if(strcmp(p->data.good_name,name)==0||strcmp(p->data.good_id,name)==0)
 		 {Goodprint(p); 
		  return NULL;} 
 	}
 	printf("您要查询的商品不存在！\n\n");
    /**
     * 1.输入商品的名称，如果名称存在则打印商品信息
     * 2.如果商品不存在则提示商品不存在
     */
}


void info_flush(GoodList **L) 
{
	FILE *fp;
	GoodList *p;
	int savecount=0;
	
	fp=fopen("goodinfo.txt", "w");
	for(p=*L;p!=NULL;p=p->next)
	{
		fprintf(fp,"\n%s\t%s\t%d\t%s\t%d\t%d",p->data.good_id,p->data.good_name,
       p->data.good_price,p->data.good_discount,p->data.good_amount,p->data.good_remain);
	        savecount++;
	}
	fclose(fp);
	DestroyGoods(L);
	CurrentCnt = 0;
    if(fp!=NULL)
	printf("Tips：%d个商品信息存入Goodinfo.txt文件\n",savecount);
    else 
	printf("Tips：未写入任何商品信息到Goodinfo.txt文件\n");
	exit(0);
}
	
	/**
     * 1.将链表内容写入到goodinfo.txt
     * 2.销毁链表
     * 3.商品数量置0
     * 文件信息的读写可参照fileIOreferrence函数
     */
    //    输出内容参考：
    //    if .... printf("提示：%d个商品信息存入Goodinfo.txt文件\n", savecount);
    //    else printf("提示：未写入任何商品信息到Goodinfo.txt文件\n");

void bubble_sort(GoodList **L)
{
	 GoodInfo temp;
	 GoodList *cur1=*L,*cur2,*later;

	 for(cur1=*L;(cur1->next)!=NULL;cur1=cur1->next){
	 	
 		for(cur2=*L;(cur2->next)!=NULL;cur2=later){
 			later=cur2->next;
	        if((cur2->data.good_price)>(later->data.good_price))
              {   temp=cur2->data;
	              cur2->data=later->data;
	              later->data=temp;
		      }
	    }
 	 } 
	 printf("当前链表中有%d个商品",CurrentCnt);
     OutputAll(*L);
}
	     
     /**
     * 1.采用冒泡排序对商品链表进行排序，按照价格从低到高进行排序
     * 2.然后输出排序后的商品链表
     */




void DelAll(GoodList **L) 
{
	FILE *fp;
	fp = fopen("goodinfo.txt", "w");
	fclose(fp);
	DestroyGoods(L);
	*L=malloc(sizeof(GoodList));
	 
    /**
     * 1.清空存储商品内容的文件
     * 2.清空商品链表，销毁已有的节点，并新建一个空链表头
     */
}


bool check_nullfile(void)
{
    FILE *fp = fopen("goodinfo.txt", "r");
    //file not exist
    if (!fp) {
        printf("商品信息初始化文件不存在！程序将为您新建一个.\n");
        FILE *fp = fopen("goodinfo.txt", "w");
        fclose(fp);
        return false;
    }
        //file already exist
    else {
        int temp;
        //res for try to read file if file null feof() can't determine whether file is null or not
        int res = fscanf(fp, "%s", &temp);
        fclose(fp);
        if (res <= 0)
            return false;
        else
            return true;
    }
}


void info_init(GoodList**L)
{
	FILE *fp;
	GoodList*cur=*L,*later;
	later=NULL;
    if(check_nullfile()){
	fp = fopen("goodinfo.txt", "r");
	for(;!feof(fp);)
 	  {
	 	fscanf(fp, "%s%s%d%s%d%d", 
	        cur->data.good_id,cur->data.good_name,&(cur->data.good_price),
	        cur->data.good_discount,&(cur->data.good_amount),&(cur->data.good_remain));
        later=malloc(sizeof(GoodList));
		cur->next=later;
        later=cur;
        cur=later->next;
        
        CurrentCnt++;
	  }
	  later->next=NULL;
    }
    
}
	/*printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
     /**
     * 1.判断goodinfo.txt是否存在，不存在则新建一个goodinfo.txt
     * 2.在未达到文件尾的情况下，从文件中读取商品信息
     * 3.然后新建链表
     * 文件信息的读写可参照fileIOreferrence函数
     */

