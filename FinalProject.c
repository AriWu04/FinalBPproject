#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct studentInfo{
	char fullName[50];
    char lastName[20];
	char ID[10];
	char birthDate[11];
	float algebra;
	float calculus;
	float basicProgramming;
	float GPA;
};

// Task 5 - Highest, lowest GPA student and highest basic programming point 
struct studentInfo highest_gpa(struct studentInfo students[], int number) {
    struct studentInfo highest = students[0];
    for (int i = 1; i < number; i++) {
        if (students[i].GPA > highest.GPA) {
            highest = students[i];
        }
    }
    return highest;
}
struct studentInfo lowest_gpa(struct studentInfo students[], int number) {
    struct studentInfo lowest = students[0];
    for (int i = 1; i < number; i++) {
        if (students[i].GPA < lowest.GPA) {
            lowest = students[i];
        }
    }
    return lowest;
}
struct studentInfo bp_Point(struct studentInfo students[], int number) {
    struct studentInfo highest_bp_Point = students[0];
    for (int i = 1; i < number; i++) {
        if (students[i].basicProgramming > highest_bp_Point.basicProgramming) {
            highest_bp_Point = students[i];
        }
    }
    return highest_bp_Point;
}

//swap float numbers
// float swap_float (float *a, float *b) {
//     float temp = *a;
//     *a = *b;
//     *b = temp;
//     return *a, *b;
// }

//swap strings
// char swap_str (char *str1, char *str2) {
//     char temp[strlen(str1) + 1];
//     strcpy(temp, str1);
//     strcpy(str1, str2);
//     strcpy(str2, temp);
// }

//swap structure
void swap_students(struct studentInfo *students, int i, int p) {
    struct studentInfo temp = students[i];
    students[i] = students[p];
    students[p] = temp;
}

int main(){
	// Task1 - Enter student number
    int number;
    printf("Enter the number of students: ");
    scanf("%d", &number);

    while(number > 1000) {
        printf("Your number is too high. Maximum number of student is 1000. Please enter again: ");
        scanf("%d", &number);
    }

	//Task2 - get student info
	struct studentInfo students[number];
    
    for (int i = 0; i < number; i++) {
		printf("\nEnter data for student %d:\n", i+1);
        printf("Enter student %d name: ", i+1);
		getchar(); // consume the newline character left in the input stream
        fgets(students[i].fullName, sizeof(students[i].fullName), stdin); //use fgets instead of scanf
        students[i].fullName[strcspn(students[i].fullName, "\n")] = 0; // Remove trailing newline
 
        printf("Enter student %d ID: ", i+1);
        scanf("%s", students[i].ID);
        
        printf("Enter student %d birthdate: ", i+1);
        scanf("%s", students[i].birthDate);
       
        printf("Enter student %d Linear Algebra point: ", i+1);
        scanf("%f", &students[i].algebra);
        
        printf("Enter student %d Calculus point: ", i+1);
        scanf("%f", &students[i].calculus);
        
        printf("Enter student %d Basic Programming point: ", i+1);
        scanf("%f", &students[i].basicProgramming);
    }

	//Task3 - print student list
    printf("\nStudents list: \n");
    printf("| %-10s | %-20s | %-10s | %-7s | %-8s | %-16s | %-5s |\n",
           "ID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    printf("|%s|\n", "-------------------------------------------------------------------------------------------------");

    for (int i = 0; i < number; i++) {
        students[i].GPA = (students[i].algebra + students[i].calculus + students[i].basicProgramming)/3;
        printf("| %10s | %-20s | %10s | %7.2f | %8.2f | %17.2f | %4.2f |\n",
               students[i].ID,
               students[i].fullName,
               students[i].birthDate,
               students[i].algebra,
               students[i].calculus,
               students[i].basicProgramming,
               students[i].GPA);
    }

	//Task4 - print in text file
    FILE *studentList = fopen("D:\\Nhi Ari\\Code\\C\\Uni\\Final\\studentList.txt", "w");
    fprintf(studentList, "| %-10s | %-20s | %-10s | %-7s | %-8s | %-16s | %-5s |\n",
           "ID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    fprintf(studentList, "|%s|\n", "-------------------------------------------------------------------------------------------------");

    for (int i = 0; i < number; i++) {
        students[i].GPA = (students[i].algebra + students[i].calculus + students[i].basicProgramming)/3;
        fprintf(studentList, "| %10s | %-20s | %10s | %7.2f | %8.2f | %17.2f | %4.2f |\n",
               students[i].ID,
               students[i].fullName,
               students[i].birthDate,
               students[i].algebra,
               students[i].calculus,
               students[i].basicProgramming,
               students[i].GPA);
    }

    fclose(studentList);

    //Task5 - highest, lowest GPA, highest BP
    // float highestGPA = 0, lowestGPA = 20, highestBP = 0;
    // int kh, kl, j;
    // for (int i = 0; i < number; i++) {
    //     if (highestGPA < students[i].GPA) {
    //         highestGPA = students[i].GPA;
    //         kh = i;
    //     }
    //     if (lowestGPA > students[i].GPA) {
    //         lowestGPA = students[i].GPA;
    //         kl = i;
    //     }
    //     if (highestBP < students[i].basicProgramming) {
    //         highestBP = students[i].basicProgramming;
    //         j = i;
    //     }
    // }

    // printf("\nThe student with the highest GPA: %s - %s - GPA: %.2f\n",
    //            students[kh].fullName,
    //            students[kh].ID,
    //            students[kh].GPA);
	
    // printf("The student with the lowest GPA: %s - %s - GPA: %.2f\n",
    //            students[kl].fullName,
    //            students[kl].ID,
    //            students[kl].GPA);

    // printf("The student with the highest Basic Programming score: %s - %s - GPA: %.2f\n",
    //            students[j].fullName,
    //            students[j].ID,
    //            students[j].basicProgramming);

    //Task5 - using struct
    struct studentInfo highest_gpa_student = highest_gpa(students, number);
    printf("Student with highest GPA:\n %s\t%s\t%2.1f", highest_gpa_student.fullName, highest_gpa_student.ID, highest_gpa_student.GPA);
    struct studentInfo lowest_gpa_student = lowest_gpa(students, number);
    printf("\nStudent with lowest GPA:\n %s\t%s\t%2.1f", lowest_gpa_student.fullName, lowest_gpa_student.ID, lowest_gpa_student.GPA);
    struct studentInfo highest_bp_student = bp_Point(students, number);
    printf("\nStudent with highest BP mark:\n %s\t%s\t%2.1f", highest_bp_student.fullName, highest_bp_student.ID, highest_bp_student.basicProgramming);
    
    //Task6 - print last name
    for (int i = 0; i < number; i++) {
        char *last_space = strrchr(students[i].fullName, ' ');
        if (last_space != NULL) {
            strcpy(students[i].lastName, last_space + 1);
        }
    }

    printf("\n");

    for (int i = 0; i < number; i++) {
        printf("%s's last name is %s\n", students[i].fullName, students[i].lastName);
    }

    //Task10 - sort GPA (selection sort)

    //Swap GPA only
    // float arr[number];

    // for (int i = 0; i < number; i++)
    // {
    //     arr[i] = students[i].GPA;
    // }

    // for (int step = 0; step < (number - 1); step++)
    // {
    //     float max = arr[step];
    //     int p = step;
    //     for (int j = (step+1); j < number; j++)
    //     {
    //         if (max < arr[j])
    //         {
    //             max = arr[j];
    //             p = j;
    //         }
    //     }
    //     if (p != step)
    //         {
    //             float s = arr[step];
    //             arr[step] = max;
    //             arr[p] = s;
    //         }
    // }

    // printf("GPA list in decreasing order: ");
    // for (int i = 0; i < number; i++)
    // {
    //     printf("%.2f ", arr[i]);
    // }

    //Swap using swap float && swap string
    // for (int step = 0; step < (number - 1); step++)
    // {
    //     float max = students[step].GPA;
    //     int p = step;
    //     for (int j = (step+1); j < number; j++)
    //     {
    //         if (max < students[j].GPA)
    //         {
    //             max = students[j].GPA;
    //             p = j;
    //         }
    //     }
    //     if (p != step)
    //         {
    //             swap_float(&students[step].GPA, &students[p].GPA);
    //             swap_str(students[step].fullName, students[p].fullName);
    //             swap_str(students[step].ID, students[p].ID);
    //             swap_str(students[step].birthDate, students[p].birthDate);
    //             swap_float(&students[step].algebra, &students[p].algebra);
    //             swap_float(&students[step].calculus, &students[p].calculus);
    //             swap_float(&students[step].basicProgramming, &students[p].basicProgramming);
    //         }
    // }

    //Swap using swap structure
    for (int step = 0; step < (number - 1); step++)
    {
        float max = students[step].GPA;
        int p = step;
        for (int j = (step+1); j < number; j++)
        {
            if (max < students[j].GPA)
            {
                max = students[j].GPA;
                p = j;
            }
        }
        if (p != step)
            {
                swap_students(students, step, p);
            }
    }

    printf("\nStudents list in GPA decreasing order: \n");
    for (int i = 0; i < number; i++) {
        printf("| %10s | %-20s | %10s | %7.2f | %8.2f | %17.2f | %4.2f |\n",
               students[i].ID,
               students[i].fullName,
               students[i].birthDate,
               students[i].algebra,
               students[i].calculus,
               students[i].basicProgramming,
               students[i].GPA);
    }
    return 0;
}