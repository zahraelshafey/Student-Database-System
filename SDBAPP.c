#include <stdio.h>
#include "SDB.h"
void SDB_APP(void){
uint8 choice;
while (1)
{
printf("\n 1- Add Entry\n");
printf("2- Get Used Size\n");
printf("3- Read Entry\n");
printf("4- Get List\n");
printf("5- Check ID Exist\n");
printf("6- Delete Entry\n");
printf("7- Is Full\n");
printf("8- Calculate gpa\n");
printf("0- Exit\n");
scanf("%d", &choice);
if (choice == 0)
    break;
SDB_action(choice);
}
}
void SDB_action(uint8 choice)
{
    uint32 id;
    uint8 count;
    uint32 list[10];

    switch(choice)
    {
        case 1:
            if (SDB_AddEntry())
                printf("Added Successfully\n");
            else
                printf("Failed to Add\n");
            break;

        case 2:
            printf("Used Size = %d\n", SDB_GetUsedSize());
            break;

        case 3:
            printf("Enter ID: ");
            if(scanf(" %u", &id) != 1) {
                printf("Invalid input!\n");
                 while(getchar() != '\n');}
             else{
            if (SDB_ReadEntry(id))
                printf("Data Found\n");
            else{
                printf("Not Found\n");}
             }
            break;

        case 4:
            SDB_GetList(&count, list);

            if(count == 0)
                printf("No IDs found.\n");
            else {
                printf("IDs List:\n");
                for (int i = 0; i < count; i++)
                    printf("%u\n", list[i]);
            }
            break;

        case 5:
            printf("Enter ID: ");
            if(scanf("%u", &id) != 1) {
                printf("Invalid input!\n");
                while(getchar() != '\n');
                break;
            }

            if (SDB_IsIdExist(id))
                printf("ID Exists\n");
            else
                printf("ID Not Exists\n");
            break;

        case 6:
            printf("Enter ID: ");
            if(scanf("%u", &id) != 1) {
                printf("Invalid input!\n");
                while(getchar() != '\n');
                break;
            }

            SDB_DeletEntry(id);
            break;

        case 7:
            if (SDB_IsFull())
                printf("Database is Full\n");
            else
                printf("Database is NOT Full\n");
            break;
    case 8:

    printf("Enter Student ID: ");
    scanf("%u", &id);
    float gpa = SDB_CalculateGPA(id);
    if (gpa >= 0)
        printf("Student GPA = %.2f\n", gpa);
    else
        printf("Student not found!\n");
    break;



       default:
            printf("Invalid Choice\n");
                }
}
