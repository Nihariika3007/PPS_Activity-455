#include <stdio.h>
#include <string.h>
#define MAX 100

/* Structure definition to store feedback details */
struct Feedback
{
    int studentID;
    char courseCode[20];
    int rating;    // Rating between 1 and 5
};

int main()
{
    struct Feedback fb[MAX];
    int n, i;

    float totalRating = 0.0;
    float averageRating;

    int highestRating = 0;
    char highestRatedCourse[20];

    int lowRatedCount = 0;

    printf("============================================\n");
    printf("   STUDENT COURSE FEEDBACK ANALYSIS SYSTEM\n");
    printf("============================================\n");

    /* Ask number of feedback entries */
    printf("\nEnter number of feedback entries: ");
    scanf("%d", &n);

    /* Input validation */
    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of entries.\n");
        return 0;
    }

    /* Input feedback records */
    for (i = 0; i < n; i++)
    {
        printf("\n----- Enter Feedback %d -----\n", i + 1);

        printf("\nEnter Student ID: ");
        scanf("%d", &fb[i].studentID);

        printf("\nEnter Course Code: ");
        scanf("%s", &fb[i].courseCode);

        /* Rating validation loop */
        do
        {
            printf("\nEnter Rating (1 to 5): ");
            scanf("%d", &fb[i].rating);

            if (fb[i].rating < 1 || fb[i].rating > 5)
            {
                printf("Invalid rating! Please enter between 1 and 5.\n");
            }
        }
        while (fb[i].rating < 1 || fb[i].rating > 5);

        /* Sum of ratings */
        totalRating += fb[i].rating;

        /* Count low-rated courses */
        if (fb[i].rating <= 2)
        {
            lowRatedCount++;
        }

        /* Find highest-rated course */
        if (fb[i].rating > highestRating)
        {
            highestRating = fb[i].rating;
            strcpy(highestRatedCourse, fb[i].courseCode);
        }
    }

    /* Calculate average rating */
    averageRating = totalRating / n;

    /* Display all feedback records */
    printf("\n============================================\n");
    printf("             FEEDBACK RECORDS\n");
    printf("\n============================================");

    for (i = 0; i < n; i++)
    {
        printf("Record %d:\n", i + 1);
        printf("Student ID   : %d\n", fb[i].studentID);
        printf("Course Code  : %s\n", fb[i].courseCode);
        printf("Rating       : %d\n", fb[i].rating);
        printf("\n--------------------------------------------");
    }

    /* Display analysis results */
    printf("\n============================================\n");
    printf("            FEEDBACK ANALYSIS\n");
    printf("\n============================================");

    printf("Total Feedback Entries   : %d\n", n);
    printf("Average Course Rating    : %2f\n", averageRating);
    printf("Highest Rated Course     : %s\n", highestRatedCourse);
    printf("Highest Rating Value     : %d\n", highestRating);
    printf("Low Rated Courses Count  : %d\n", lowRatedCount);

    printf("\n============================================\n");
    printf("        PROGRAM EXECUTION COMPLETED\n");
    printf("\n============================================");

    return 0;
}

/*  OUTPUT
============================================
   STUDENT COURSE FEEDBACK ANALYSIS SYSTEM
============================================

Enter number of feedback entries: 4

----- Enter Feedback 1 -----

Enter Student ID: 453

Enter Course Code: 12345

Enter Rating (1 to 5): 2

----- Enter Feedback 2 -----

Enter Student ID: 454

Enter Course Code: 12345

Enter Rating (1 to 5): 3

----- Enter Feedback 3 -----

Enter Student ID: 455

Enter Course Code: 12345

Enter Rating (1 to 5): 4

----- Enter Feedback 4 -----

Enter Student ID: 456

Enter Course Code: 12345

Enter Rating (1 to 5): 5

============================================
             FEEDBACK RECORDS

============================================Record 1:
Student ID   : 453
Course Code  : 12345
Rating       : 2

--------------------------------------------Record 2:
Student ID   : 454
Course Code  : 12345
Rating       : 3

--------------------------------------------Record 3:
Student ID   : 455
Course Code  : 12345
Rating       : 4

--------------------------------------------Record 4:
Student ID   : 456
Course Code  : 12345
Rating       : 5

--------------------------------------------
============================================
            FEEDBACK ANALYSIS

============================================Total Feedback Entries   : 4
Average Course Rating    : 3.500000
Highest Rated Course     : 12345
Highest Rating Value     : 5
Low Rated Courses Count  : 1

============================================
        PROGRAM EXECUTION COMPLETED

============================================*/






















































