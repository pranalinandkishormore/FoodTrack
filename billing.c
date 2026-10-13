#include <stdio.h>
#include "order.h"
#include "billing.h"

void process_final_bill() {
    int target_id, flag = 0;
    printf("\nEnter Order ID to calculate invoice: ");
    scanf("%d", &target_id);

    for (int i = 0; i < total_orders; i++) {
        if (tracking_list[i].id == target_id) {
            flag = 1;
            double fee = tracking_list[i].bill_amount * 0.05;
            double total = tracking_list[i].bill_amount + fee + 30.0;
            
            printf("\n--- INVOICE REPORT FOR ORDER %d ---\n", target_id);
            printf("Base Food Items Cost: ₹%.2f\n", tracking_list[i].bill_amount);
            printf("Platform Fee (5%%): ₹%.2f\n", fee);
            printf("Delivery Charges: ₹30.00\n");
            printf("----------------------------------\n");
            printf("Net Final Amount Payable: ₹%.2f\n", total);
            break;
        }
    }
    
    if (flag == 0) {
        printf("Order ID not found in system storage.\n");
    }
}
