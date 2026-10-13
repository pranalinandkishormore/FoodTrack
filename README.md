# Track_My_Food
# Food Delivery Order Tracking System

A modular Microproject developed in C Language to log, track, and process food delivery orders across a simulated network. The program manages structured databases and balances courier schedules using separate source modules.

---

## Project Requirements Implemented

This project fully satisfies all structural operations and assignment rules:
* **Structured Data Base:** Implements structured dynamic storage models to safely retain multiple distinct food records (struct FoodOrder tracking_list[MAX_ORDERS]).
* **Round-Robin Scheduling:** Automatically matches active pending orders to logistics agents sequentially from a dedicated courier list.
* **Invoice Adjustments:** Implements automated value checks to determine custom billing (5 percent platform fees combined with a standard 30 rupees delivery charge).
* **Personnel Filtering Log:** Traverses array indices using pointer matches to instantly isolate and list all packages assigned to a specific delivery agent.
* **Performance Analysis:** Runs dedicated linear comparisons to calculate and expose the highest value vendor based on accumulated total order sums.

---

## Architecture Layout

The system divides functions across individual files to keep logic clean and beginner-friendly:
* main.c - The interactive control terminal panel routing all choices.
* order.h & order.c - Defines structure boundaries and logs customer package inputs.
* driver.h & driver.c - Manages the circular assignment distribution routines and handles driver filters.
* billing.h & billing.c - Processes platform additions and outputs final printable summaries.
* vendor.h & vendor.c - Scans cumulative totals to find the top performing business.

---

## Compilation and Execution Guide

To build and run this multi-file program inside your terminal console, use these compiler commands:

```bash
gcc main.c order.c driver.c billing.c vendor.c -o track_app
./track_app
```
