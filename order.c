#include <stdio.h>
#include <string.h>
#include "order.h"

struct FoodOrder tracking_list[MAX_ORDERS];
int total_orders = 0;

void create_order() {
    if (total_orders >= MAX_ORDERS) {
        printf("\nSystem database limit full!\n");
        return;
    }

    printf("\n--- Book New Food Delivery ---\n");
    printf("Enter Order ID: ");
    scanf("%d", &tracking_list[total_orders].id);
    
    getchar();
    printf("Enter Customer Name: ");
    fgets(tracking_list[total_orders].customer, 50, stdin);
    tracking_list[total_orders].customer[strcspn(tracking_list[total_orders].customer, "\n")] = '\0';
    
    printf("Enter Restaurant Name: ");
    fgets(tracking_list[total_orders].vendor, 50, stdin);
    tracking_list[total_orders].vendor[strcspn(tracking_list[total_orders].vendor, "\n")] = '\0';
    
    printf("Enter Items Ordered: ");
    fgets(tracking_list[total_orders].items, 200, stdin);
    tracking_list[total_orders].items[strcspn(tracking_list[total_orders].items, "\n")] = '\0';
    
    printf("Enter Order Value: ₹");
    scanf("%lf", &tracking_list[total_orders].bill_amount);
    
    strcpy(tracking_list[total_orders].courier_name, "Unassigned");
    strcpy(tracking_list[total_orders].status, "Pending");
    
    total_orders++;
    printf("\nOrder created successfully!\n");
}

void display_all() {
    if (total_orders == 0) {
        printf("\nNo delivery orders available.\n");
        return;
    }
    
    printf("\n=== ACTIVE ORDER TRACKING LOGS ===\n");
    for (int i = 0; i < total_orders; i++) {
        printf("ID: %d | Customer: %s | Hotel: %s | Food: %s | Amount: ₹%.2f | Agent: %s | Status: %s\n",
               tracking_list[i].id, tracking_list[i].customer, tracking_list[i].vendor, 
               tracking_list[i].items, tracking_list[i].bill_amount, 
               tracking_list[i].courier_name, tracking_list[i].status);
    }
}
