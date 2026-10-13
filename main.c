#include <stdio.h>
#include "order.h"
#include "driver.h"
#include "billing.h"
#include "vendor.h"

int main() {
    int user_selection;

    printf("============================================\n");
    printf("     FOOD DELIVERY ORDER TRACKING SYSTEM    \n");
    printf("============================================\n");

    do {
        printf("\n--- CORE MANAGEMENT MENU ---\n");
        printf("1. Create New Order Entry\n");
        printf("2. Run Round-Robin Driver Assignment\n");
        printf("3. Compute Order Invoice Details\n");
        printf("4. Filter Deliveries by Driver Name\n");
        printf("5. Find Highest Value Restaurant\n");
        printf("6. View Full System Logs\n");
        printf("7. Exit Tracking Console\n");
        printf("--------------------------------------------\n");
        printf("Choose Action (1-7): ");
        scanf("%d", &user_selection);

        switch (user_selection) {
            case 1: create_order(); break;
            case 2: run_round_robin(); break;
            case 3: process_final_bill(); break;
            case 4: filter_by_driver(); break;
            case 5: isolate_top_vendor(); break;
            case 6: display_all(); break;
            case 7: printf("\nClosing order system database. Goodbye!\n"); break;
            default: printf("\nInvalid input choice! Select between 1 and 7.\n");
        }
    } while (user_selection != 7);

    return 0;
}
