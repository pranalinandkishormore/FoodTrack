#include <stdio.h>
#include <string.h>
#include "order.h"
#include "driver.h"

char personnel[MAX_DRIVERS][50] = {"Karan", "Vijay", "Suresh", "Manish", "Deepak"};
int current_index = 0;

void run_round_robin() {
    int counter = 0;
    
    for (int i = 0; i < total_orders; i++) {
        if (strcmp(tracking_list[i].status, "Pending") == 0) {
            strcpy(tracking_list[i].courier_name, personnel[current_index]);
            strcpy(tracking_list[i].status, "Assigned");
            printf("Order %d successfully mapped to Agent: %s\n", tracking_list[i].id, tracking_list[i].courier_name);
            current_index = (current_index + 1) % MAX_DRIVERS;
            counter++;
        }
    }
    
    if (counter == 0) {
        printf("\nNo pending delivery assignments found.\n");
    } else {
        printf("\nAll pending tasks updated successfully.\n");
    }
}

void filter_by_driver() {
    char target[50];
    int flag = 0;
    
    getchar();
    printf("\nEnter Delivery Agent Name to scan: ");
    fgets(target, 50, stdin);
    target[strcspn(target, "\n")] = '\0';
    
    printf("\n--- Orders Managed by %s ---\n", target);
    for (int i = 0; i < total_orders; i++) {
        if (strcmp(tracking_list[i].courier_name, target) == 0) {
            printf("Order ID: %d | From: %s | Total: ₹%.2f | Status: %s\n", 
                   tracking_list[i].id, tracking_list[i].vendor, tracking_list[i].bill_amount, tracking_list[i].status);
            flag = 1;
        }
    }
    
    if (flag == 0) {
        printf("No matching tasks found for this agent.\n");
    }
}
