#include <stdio.h>
#include <string.h>
#include "order.h"
#include "vendor.h"

void isolate_top_vendor() {
    if (total_orders == 0) {
        printf("\nNo order statistics recorded yet.\n");
        return;
    }

    char unique_hotels[MAX_ORDERS][50];
    double accumulated_sums[MAX_ORDERS] = {0};
    int unique_count = 0;

    for (int i = 0; i < total_orders; i++) {
        int index = -1;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(unique_hotels[j], tracking_list[i].vendor) == 0) {
                index = j;
                break;
            }
        }

        if (index != -1) {
            accumulated_sums[index] += tracking_list[i].bill_amount;
        } else {
            strcpy(unique_hotels[unique_count], tracking_list[i].vendor);
            accumulated_sums[unique_count] = tracking_list[i].bill_amount;
            unique_count++;
        }
    }

    int best_index = 0;
    for (int i = 1; i < unique_count; i++) {
        if (accumulated_sums[i] > accumulated_sums[best_index]) {
            best_index = i;
        }
    }

    printf("\n=== HIGHEST VALUE RESTAURANT ===\n");
    printf("Restaurant Name   : %s\n", unique_hotels[best_index]);
    printf("Total Order Value : ₹%.2f\n", accumulated_sums[best_index]);
}
