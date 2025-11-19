#include <stdio.h>
#include <string.h>

#define MAX 50

struct Transport {
    char type[10];
    char number[10];
    char source[20];
    char destination[20];
    char departure[10];
    char arrival[10];
    int delay;
    int seats;
};

void filterSchedule(struct Transport t[], int n);
void delayedServices(struct Transport t[], int n);
void availableSeats(struct Transport t[], int n);
void customQuery(struct Transport t[], int n);

int main() {
    struct Transport t[MAX] = {
        {"Flight", "AI202", "Delhi", "Bangalore", "10:00", "12:30", 0, 5},
        {"Train",  "12345", "Mumbai", "Pune",      "14:30", "20:00", 45, 0},
        {"Train",  "67890", "Delhi",  "Chennai",   "09:00", "14:00", 10, 25},
        {"Flight", "AI305", "Chennai","Delhi",     "18:45", "21:30", 0, 10},
        {"Flight", "AI410", "Delhi",  "Hyderabad", "06:00", "09:00", 20, 0}
    };

    int n = 5;
    int choice;

    while (1) {
        printf("\n====== TRANSPORT DATA TRACKER ======\n");
        printf("1. Filter by Schedule (Source & Destination)\n");
        printf("2. Show Delayed Services\n");
        printf("3. Show Services with Available Seats\n");
        printf("4. Custom Query\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: filterSchedule(t, n); break;
            case 2: delayedServices(t, n); break;
            case 3: availableSeats(t, n); break;
            case 4: customQuery(t, n); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

void filterSchedule(struct Transport t[], int n) {
    char src[20], dest[20];
    int found = 0;

    printf("Enter Source: ");
    scanf("%s", src);
    printf("Enter Destination: ");
    scanf("%s", dest);

    printf("\n--- Matching Transport Options ---\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(t[i].source, src) == 0 &&
            strcmp(t[i].destination, dest) == 0) {

            printf("%s %s | %s → %s | Dep: %s | Arr: %s | Delay: %d min | Seats: %d\n",
                t[i].type, t[i].number, t[i].source, t[i].destination,
                t[i].departure, t[i].arrival, t[i].delay, t[i].seats);
            found = 1;
        }
    }

    if (!found)
        printf("No matching schedule found.\n");
}

void delayedServices(struct Transport t[], int n) {
    int found = 0;

    printf("\n--- Delayed Services ---\n");
    for (int i = 0; i < n; i++) {
        if (t[i].delay > 0) {
            printf("%s %s | Delay: %d min\n", t[i].type, t[i].number, t[i].delay);
            found = 1;
        }
    }

    if (!found)
        printf("No delayed services.\n");
}

void availableSeats(struct Transport t[], int n) {
    int found = 0;

    printf("\n--- Services with Available Seats ---\n");
    for (int i = 0; i < n; i++) {
        if (t[i].seats > 0) {
            printf("%s %s | Seats Available: %d\n", t[i].type, t[i].number, t[i].seats);
            found = 1;
        }
    }

    if (!found)
        printf("No services with available seats.\n");
}

void customQuery(struct Transport t[], int n) {
    char type[10];
    int minSeats, maxDelay;
    int found = 0;

    printf("Enter type (Flight/Train): ");
    scanf("%s", type);
    printf("Enter minimum seats required: ");
    scanf("%d", &minSeats);
    printf("Enter maximum delay allowed: ");
    scanf("%d", &maxDelay);

    printf("\n--- Custom Query Results ---\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(t[i].type, type) == 0 &&
            t[i].seats >= minSeats &&
            t[i].delay <= maxDelay) {

            printf("%s %s | Seats: %d | Delay: %d min\n",
                   t[i].type, t[i].number, t[i].seats, t[i].delay);
            found = 1;
        }
    }

    if (!found)
        printf("No data matches your query.\n");
}
