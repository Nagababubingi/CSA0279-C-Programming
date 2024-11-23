#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPLAINTS 100
#define MAX_LENGTH 256

typedef struct {
    int id;
    char customerName[MAX_LENGTH];
    char complaintType[MAX_LENGTH];
    char description[MAX_LENGTH];
    char status[MAX_LENGTH];
    char feedback[MAX_LENGTH]; // New field for feedback
} Complaint;

void registerComplaint(Complaint complaints[], int *count) {
    printf("\n--- Register a Complaint ---\n");
    if (*count >= MAX_COMPLAINTS) {
        printf("Error: Complaint limit reached.\n");
        return;
    }

    complaints[*count].id = *count + 1;
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", complaints[*count].customerName);
    printf("Enter Complaint Type (Product/Service): ");
    scanf(" %[^\n]", complaints[*count].complaintType);
    printf("Enter Complaint Description: ");
    scanf(" %[^\n]", complaints[*count].description);
    strcpy(complaints[*count].status, "Pending");
    complaints[*count].feedback[0] = '\0'; // Initialize feedback as empty

    (*count)++;
    printf("Complaint Registered Successfully!\n");
}

void viewComplaints(Complaint complaints[], int count) {
    printf("\n--- View All Complaints ---\n");
    if (count == 0) {
        printf("No complaints registered.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Complaint ID: %d\n", complaints[i].id);
        printf("Customer Name: %s\n", complaints[i].customerName);
        printf("Complaint Type: %s\n", complaints[i].complaintType);
        printf("Description: %s\n", complaints[i].description);
        printf("Status: %s\n", complaints[i].status);

        if (strcmp(complaints[i].status, "Resolved") == 0) {
            printf("Feedback: %s\n", complaints[i].feedback);
        }

        printf("-------------------------\n");
    }
}

void updateStatus(Complaint complaints[], int count) {
    int id;
    printf("\n--- Update Complaint Status ---\n");
    printf("Enter Complaint ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (complaints[i].id == id) {
            printf("Enter New Status (Resolved/In Progress): ");
            scanf(" %[^\n]", complaints[i].status);

            if (strcmp(complaints[i].status, "Resolved") == 0) {
                printf("Enter Feedback for the Resolved Complaint: ");
                scanf(" %[^\n]", complaints[i].feedback);
            }

            printf("Status Updated Successfully!\n");
            return;
        }
    }
    printf("Error: Complaint ID not found.\n");
}

int main() {
    Complaint complaints[MAX_COMPLAINTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Consumer Complaint Handling System ---\n");
        printf("1. Register Complaint\n");
        printf("2. View Complaints\n");
        printf("3. Update Complaint Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerComplaint(complaints, &count);
                break;
            case 2:
                viewComplaints(complaints, count);
                break;
            case 3:
                updateStatus(complaints, count);
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}