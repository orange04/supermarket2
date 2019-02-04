#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "define_my.h"
#include "menu.h"

int CurrentCnt=0;

int main()
{   
    int command;
    GoodList *L;
	CurrentCnt=0;
    L=malloc(sizeof(GoodList));
    if(L==NULL){
		printf("申请空间失败!");exit(0);
	}
 
 	memset(L, 0, sizeof(GoodList));
 	
    check_nullfile();
    info_init(&L);
    
    for(;;){
    	printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
    	printf("超市商品管理系统");
        printf("\n****************************************\n");
        printf("1.显示所有商品的信息：\n"
               "2.修改某个商品的信息：\n"
		       "3.插入某个商品的信息：\n"
		       "4.删除某个商品的信息：\n"
		       "5.查找某个商品的信息：\n"
		       "6.商品存盘并退出系统：\n"
		       "7.对商品价格进行排序：\n"
		       "8.（慎用）删除所有内容：\n"
		       "其他.不存盘并退出系统：\n");
        printf("****************************************\n");
        printf("输入您的选择：");
        scanf("%d",&command);

 switch (command){
     	   case 1: OutputAll(L);break;
     	   case 2: info_change(&L);break;
     	   case 3: info_insert(&L);break;
     	   case 4: info_dele(&L);break;
     	   case 5: GoodSearch(L);break;
     	   case 6: info_flush(&L);break;
     	   case 7: bubble_sort(&L);break;
     	   case 8: DelAll(&L);break;
     	   default: exit(0);
     }
    }
	return 0;
    
}