#ifndef DRIVER_H
#define DRIVER_H

#define MAX_DRIVERS 5

extern char personnel[MAX_DRIVERS][50];
extern int current_index;

void run_round_robin();
void filter_by_driver();

#endif
