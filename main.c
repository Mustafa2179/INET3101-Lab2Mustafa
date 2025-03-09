#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int partNumber;
    char partName[100];
    float partSize;
    char partSizeMetric[10];
    float partCost;
} PartRecord;

PartRecord* addRecord(PartRecord* database, int* size, PartRecord newRecord) {
    PartRecord* temp = realloc(database, (*size + 1) * sizeof(PartRecord));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return database; // Return the original database if realloc fails
    }
    database = temp;
    database[*size] = newRecord;
    (*size)++;
    return database;
}

void deleteRecord(PartRecord* database, int* size) {
    if (*size > 0) {
        (*size)--;
        PartRecord* temp = realloc(database, (*size) * sizeof(PartRecord));
        if (temp == NULL && *size > 0) {
            printf("Memory reallocation failed\n");
            return;
        }
        database = temp;
    }
}

int main() {
    PartRecord* database = NULL;
    int size = 0, res;
    int choice;
    PartRecord newRecord;

    do {
        printf("MENU\n====\n1. Add record\n2. Delete record\n3. Print all records\n4. Exit\nEnter choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter part number, name, size, size metric, and cost:\n");
            res = scanf_s("%d %s %f %s %f", &newRecord.partNumber, newRecord.partName, (unsigned)_countof(newRecord.partName), &newRecord.partSize, newRecord.partSizeMetric, (unsigned)_countof(newRecord.partSizeMetric), &newRecord.partCost);
            if (res == 5) {
                database = addRecord(database, &size, newRecord);
            }
            else {
                printf("Invalid input. Please try again.\n");
            }
            break;
        case 2:
            deleteRecord(database, &size);
            break;
        case 3:
            for (int i = 0; i < size; i++) {
                printf("Part Number: %d, Name: %s, Size: %.2f, Size Metric: %s, Cost: %.2f\n",
                    database[i].partNumber, database[i].partName, database[i].partSize, database[i].partSizeMetric, database[i].partCost);
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(database); // Free memory before exiting
    return 0;
}

