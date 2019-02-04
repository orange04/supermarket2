#ifndef DEFINE_MY_H
#define DEFINE_MY_H 
//--------------------------------------------------------------------
//商品的最大数量
//--------------------------------------------------------------------
#define MAX 100
//--------------------------------------------------------------------
//商品信息结构的定义
//--------------------------------------------------------------------
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30

typedef struct {
    char	good_id[MAX_ID_LEN];
    char	good_name[MAX_NAME_LEN];
    int  	good_price;
    char	good_discount[MAX_DISCOUNT_LEN];
    int		good_amount;
    int		good_remain;
}GoodInfo;


//--------------------------------------------------------------------
//全局变量，存储当前商品的数量
//--------------------------------------------------------------------
extern int CurrentCnt;


//--------------------------------------------------------------------
//定义商品链表的结点
//--------------------------------------------------------------------
typedef struct node
{
    GoodInfo data;
    struct node *next;
}GoodList;

#endif