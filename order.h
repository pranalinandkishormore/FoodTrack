#ifndef ORDER_H
#define ORDER_H

#define MAX_ORDERS 500

struct FoodOrder {
    int id;
    char customer[50];
    char vendor[50];
    char items[200];
    double bill_amount;
    char courier_name[50];
    char status[30];
};

extern struct FoodOrder tracking_list[MAX_ORDERS];
extern int total_orders;

void create_order();
void display_all();

#endif
