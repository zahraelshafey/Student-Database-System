#include<stdio.h>
#include"SDB.h"
#define MAX 10
student database[MAX];
uint8 studentcount = 0;
bool SDB_IsFull(void){
    if (studentcount>=MAX)
        return true;
        else
           return false;
    }

uint8 SDB_GetUsedSize(){
    return studentcount;
}
bool SDB_AddEntry()
{
    if(SDB_IsFull())
    {
        printf("OverFlow\n");
        return 0;
    }

    student s;
    printf("Enter Student ID: ");
    scanf("%u", &s.Student_ID);
    if(SDB_IsIdExist(s.Student_ID))
    {
        printf("ID already exist\n");
        return 0;
    }
    printf("Enter Student Year: ");
    scanf(" %u", &s.Student_year);
    printf("Enter Course1 ID and Grade: ");
    scanf(" %u %u", &s.Course1_ID, &s.Course1_grade);
    printf("Enter Course2 ID and Grade: ");
    scanf(" %u %u", &s.Course2_ID, &s.Course2_grade);
    printf("Enter Course3 ID and Grade: ");
    scanf(" %u %u", &s.Course3_ID, &s.Course3_grade);
    database[studentcount] = s;
    studentcount++;

    return 1;
}
void SDB_DeletEntry (uint32 id){
int flag=0;
int i=0;
for(i = 0; i < studentcount; i++)
    {
        if(database[i].Student_ID == id)
        {
            flag=1;
     for(int j = i; j < studentcount - 1; j++)
            {
            database[j] = database[j + 1];
            }
            studentcount--;
            printf("Student with ID %u deleted\n", id);
            break;
        }
    }
    if(flag==0){
       printf("Student with ID %u not found\n", id);
    }
}
bool SDB_ReadEntry(uint32 id)
{
    for(int i = 0; i < studentcount; i++)
    {
        if(database[i].Student_ID == id)
        {
            printf("Student ID %u\n", database[i].Student_ID);
            printf("Student Year %u\n", database[i].Student_year);
            printf("Course1 ID %u, Grade: %u\n", database[i].Course1_ID, database[i].Course1_grade);
            printf("Course2 ID %u, Grade: %u\n", database[i].Course2_ID, database[i].Course2_grade);
            printf("Course3 ID %u, Grade: %u\n", database[i].Course3_ID, database[i].Course3_grade);
            return 1;
        }
    }
    printf("Student with ID %u not found\n", id);
    return 0;
}
 void SDB_GetList(uint8 *count, uint32 *list)
{
    for(int i = 0; i < studentcount; i++)
    {
        list[i] = database[i].Student_ID;
    }

    *count= studentcount;
}

bool SDB_IsIdExist(uint32 id){
for(int i=0;i<studentcount;i++){
    if(database[i].Student_ID==id)
       return 1;//Found
    else
        return 0;//NotFound
}}
float SDB_CalculateGPA(uint32 id) {
    for (int i = 0; i < studentcount; i++) {
        if (database[i].Student_ID == id) {
            float sum = database[i].Course1_grade + database[i].Course2_grade + database[i].Course3_grade;
            return sum / 3.0;
        }
    }
    return -1;
}

