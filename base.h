#ifndef BASE_H
#define BASE_H


#include "define_my.h"



void Goodprint(GoodList *p);

GoodList *info_search(GoodList *L);

GoodList *pre_search(GoodList *L,GoodList *p);

void DestroyGoods(GoodList **L);


#endif