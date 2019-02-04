#ifndef MENU_H
#define MENU_H

void OutputAll(GoodList *L);


void info_change(GoodList **L);

void info_insert(GoodList **L);

void info_dele(GoodList **L);  

void GoodSearch(GoodList *L);


void info_flush(GoodList **L); 

void bubble_sort(GoodList **L);

void DelAll(GoodList **L); 


bool check_nullfile(void);

void info_init(GoodList**L);

#endif