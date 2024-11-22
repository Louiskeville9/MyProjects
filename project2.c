#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 40
#define product_line_length 10
#define LENGTH 40

//Nested structure for batch date and time
struct batch {
    int day;
    int month;
    int hour;
    int min;
};

//Nested structure for issue code
struct code {
    int res_code;
    char description[LENGTH];

};

//Nested structure for issue code
struct data {
    int code;
    char description[LENGTH];
};

//Data Structure for Product Line
struct product_line {
    int line_code;
    int batch_code;
    int product_id;
    struct data issue_code[LENGTH];
    struct code resolution_code[LENGTH];
    int employee_id;
    struct batch date;
};

//Function Signatures
void display(struct product_line[]); //Display structure
void merge(struct product_line[], int , int , int ); //Merge function
void merge2(struct product_line[], int, int, int); //Second merge function
void mergeSort(struct product_line[], int, int); //MergeSort function
void mergeSort2(struct product_line[], int, int); //Second mergeSort fuction
struct node *createNode(int, int, int); //Create a new node for linked list
void insertNode(struct node**, int, int, int); //Insert node to linked list
void DisplayList(struct node*); //Display linked list
int IssueCount(struct product_line[], int); //Count issue codes
int binarySearch(struct product_line[], int, int, int); //Binary search
void displayTestData(struct product_line[], int); //Display the test data

//Create the linked list for Task 2
//Node structure
struct node {
    int issue_code;
    int product_id;
    int line_code;
    struct node *link;
};


int main()
{
    // Test Data Initialization

    struct product_line Line1[product_line_length] = {
        {1, 10, 1300, {1111, "Motor Housing"}, {1122,"a"}, 92231, {9, 2, 10, 23}},
        {1, 11, 1124, {1112, "Gear/Shaft For motor"}, {1124,"a"}, 54432, {4, 2, 8, 12}},
        {1, 12, 1125, {1123, "Lever Bearing"}, {1130,"a"}, 44321, {19, 2, 9, 33}},
        {1, 13, 1128, {1213, "Engine S5"}, {1143,"a"}, 55378, {4, 2, 11, 31}},
        {1, 14, 1133, {1158, "Pilot Headset"}, {1149,"a"}, 58341, {23, 2, 14, 49}},
        {1, 15, 1141, {1167, "Drag Brace Bearing"}, {1153,"a"}, 92231, {1, 2, 12, 25}},
        {1, 16, 1116, {1112, "Steering Actuator Bearings"}, {1160,"a"}, 66893, {11, 2, 15, 33}},
        {1, 17, 1100, {1130, "Weather & Radar scanner"}, {1162,"a"}, 79233, {15, 2, 10, 21}},
        {1, 21, 1123, {1139, "Turbofan engine 1"}, {1168,"a"}, 44321, {21, 2, 13, 28}},
        {1, 22, 1160, {1144, "Main fuel tank"}, {1175,"a"}, 32214, {29, 2, 14, 53}}
    };

    struct product_line Line2[product_line_length] = {
        {2, 25, 1127, {1126, "Engine oil tank"}, {1142,"a"}, 58341, {12, 2, 16, 52}},
        {2, 33, 1014, {1103, "Engine S3"}, {1155,"a"}, 99338, {3, 2, 10, 19}},
        {2, 10, 1143, {1102, "Retracting landing wheel set"}, {1122,"a"}, 92231, {9, 2, 10, 23}},
        {2, 11, 1124, {1113, "Gear/Shaft For motor"}, {1124,"a"}, 54432, {4, 2, 8, 12}},
        {2, 12, 1125, {1129, "Lever Bearing"}, {1130,"a"}, 44321, {11, 2, 9, 33}},
        {2, 13, 1128, {1213, "Engine S5"}, {1143,"a"}, 55378, {1, 2, 11, 31}},
        {2, 14, 1133, {1299, "Pilot Headset"}, {1149,"a"}, 58341, {21, 2, 14, 49}},
        {2, 15, 1141, {1117, "Drag Brace Bearing"}, {1153,"a"}, 92231, {6, 2, 12, 25}},
        {2, 16, 1124, {1103, "Gear/Shaft For motor"}, {1160,"a"}, 66893, {10, 2, 15, 33}},
        {2, 17, 1100, {1151, "Weather & Radar scanner"}, {1162,"a"}, 79233, {18, 2, 10, 21}}
    };

    struct product_line Line3[product_line_length] = {
        {3, 21, 1127, {1188, "Engine oil tank"}, {1168,"a"}, 44321, {21, 2, 13, 28}},
        {3, 22, 1125, {1235, "Lever Bearing"}, {1175,"a"}, 32214, {29, 2, 14, 17}},
        {3, 25, 1143, {1023, "Retracting landing wheel set"}, {1142,"a"}, 58341, {12, 2, 16, 52}},
        {3, 33, 1116, {1146, "Steering Actuator Bearings"}, {1155}, 99338, {3, 2, 10, 19}},
        {3, 21, 1123, {1120, "Turbofan engine 1"}, {1168,"a"}, 44321, {10, 2, 13, 28}},
        {3, 22, 1160, {1221, "Main fuel tank"}, {1175,"a"}, 32214, {20, 2, 14, 7}},
        {3, 25, 1133, {1166, "Pilot Headset"}, {1142,"a"}, 58341, {12, 2, 12, 12}},
        {3, 33, 1116, {1149, "Steering Actuator Bearings"}, {1155}, 99338, {3, 2, 10, 52}},
        {3, 15, 1141, {1255, "Drag Brace Bearing"}, {1153,"a"}, 92231, {1, 2, 19, 13}},
        {3, 15, 1143, {1041, "Retracting landing wheel set"}, {1153}, 92231, {5, 2, 11, 25}}
    };

    struct product_line Line4[product_line_length] = {
        {4, 21, 1160, {1225, "Main fuel tank"}, {1168,"a"}, 44321, {21, 2, 9, 12}},
        {4, 22, 1125, {1297, "Lever Bearing"}, {1175,"a"}, 32214, {29, 2, 13, 10}},
        {4, 25, 1133, {1113, "Pilot Headset"}, {1142,"a"}, 58341, {12, 2, 16, 52}},
        {4, 33, 1128, {1253, "Engine S5"}, {1155,"a"}, 99338, {3, 2, 10, 19}},
        {4, 21, 1100, {1289, "Weather & Radar scanner"}, {1168,"a"}, 44321, {24, 2, 13, 28}},
        {4, 22, 1125, {1106, "Lever Bearing"}, {1175,"a"}, 32214, {11, 2, 14, 18}},
        {4, 25, 1133, {1198, "Pilot Headset"}, {1142,"a"}, 58341, {17, 2, 16, 52}},
        {4, 33, 1116, {1192, "Steering Actuator Bearings"}, {1155,"a"}, 99338, {19, 2, 10, 19}},
        {4, 15, 1014, {1184, "Engine S3"}, {1153,"a"}, 92231, {14, 2, 12, 25}},
        {4, 15, 1141, {1181, "Drag Brace Bearing"}, {1153,"a"}, 92231, {3, 2, 12, 25}}
    };

   

    struct product_line product[SIZE] = {
        {1, 10, 1300, {1111, "Motor Housing"}, {1122,"a"}, 92231, {9, 2, 10, 23}},
        {1, 11, 1124, {1112, "Gear/Shaft For motor"}, {1124,"a"}, 54432, {4, 2, 8, 12}},
        {1, 12, 1125, {1123, "Lever Bearing"}, {1130,"a"}, 44321, {19, 2, 9, 33}},
        {1, 13, 1128, {1213, "Engine S5"}, {1143,"a"}, 55378, {4, 2, 11, 31}},
        {1, 14, 1133, {1158, "Pilot Headset"}, {1149,"a"}, 58341, {23, 2, 14, 49}},
        {1, 15, 1141, {1167, "Drag Brace Bearing"}, {1153,"a"}, 92231, {1, 2, 12, 25}},
        {1, 16, 1116, {1112, "Steering Actuator Bearings"}, {1160,"a"}, 66893, {11, 2, 15, 33}},
        {1, 17, 1100, {1130, "Weather & Radar scanner"}, {1162,"a"}, 79233, {15, 2, 10, 21}},
        {1, 21, 1123, {1139, "Turbofan engine 1"}, {1168,"a"}, 44321, {21, 2, 13, 28}},
        {1, 22, 1160, {1144, "Main fuel tank"}, {1175,"a"}, 32214, {29, 2, 14, 53}},
        {2, 25, 1127, {1126, "Engine oil tank"}, {1142,"a"}, 58341, {12, 2, 16, 52}},
        {2, 33, 1014, {1103, "Engine S3"}, {1155,"a"}, 99338, {3, 2, 10, 19}},
        {2, 10, 1143, {1102, "Retracting landing wheel set"}, {1122,"a"}, 92231, {9, 2, 10, 23}},
        {2, 11, 1124, {1113, "Gear/Shaft For motor"}, {1124,"a"}, 54432, {4, 2, 8, 12}},
        {2, 12, 1125, {1129, "Lever Bearing"}, {1130,"a"}, 44321, {11, 2, 9, 33}},
        {2, 13, 1128, {1213, "Engine S5"}, {1143,"a"}, 55378, {1, 2, 11, 31}},
        {2, 14, 1133, {1299, "Pilot Headset"}, {1149,"a"}, 58341, {21, 2, 14, 49}},
        {2, 15, 1141, {1117, "Drag Brace Bearing"}, {1153,"a"}, 92231, {6, 2, 12, 25}},
        {2, 16, 1124, {1103, "Gear/Shaft For motor"}, {1160,"a"}, 66893, {10, 2, 15, 33}},
        {2, 17, 1100, {1151, "Weather & Radar scanner"}, {1162,"a"}, 79233, {18, 2, 10, 21}},
        {3, 21, 1127, {1188, "Engine oil tank"}, {1168,"a"}, 44321, {21, 2, 13, 28}},
        {3, 22, 1125, {1235, "Lever Bearing"}, {1175,"a"}, 32214, {29, 2, 14, 17}},
        {3, 25, 1143, {1023, "Retracting landing wheel set"}, {1142,"a"}, 58341, {12, 2, 16, 52}},
        {3, 33, 1116, {1146, "Steering Actuator Bearings"}, {1155}, 99338, {3, 2, 10, 19}},
        {3, 21, 1123, {1120, "Turbofan engine 1"}, {1168,"a"}, 44321, {10, 2, 13, 28}},
        {3, 22, 1160, {1221, "Main fuel tank"}, {1175,"a"}, 32214, {20, 2, 14, 7}},
        {3, 25, 1133, {1166, "Pilot Headset"}, {1142,"a"}, 58341, {12, 2, 12, 12}},
        {3, 33, 1116, {1149, "Steering Actuator Bearings"}, {1155}, 99338, {3, 2, 10, 52}},
        {3, 15, 1141, {1255, "Drag Brace Bearing"}, {1153,"a"}, 92231, {1, 2, 19, 13}},
        {3, 15, 1143, {1041, "Retracting landing wheel set"}, {1153}, 92231, {5, 2, 11, 25}},
        {4, 21, 1160, {1225, "Main fuel tank"}, {1168,"a"}, 44321, {21, 2, 9, 12}},
        {4, 22, 1125, {1297, "Lever Bearing"}, {1175,"a"}, 32214, {29, 2, 13, 10}},
        {4, 25, 1133, {1113, "Pilot Headset"}, {1142,"a"}, 58341, {12, 2, 16, 52}},
        {4, 33, 1128, {1253, "Engine S5"}, {1155,"a"}, 99338, {3, 2, 10, 19}},
        {4, 21, 1100, {1289, "Weather & Radar scanner"}, {1168,"a"}, 44321, {24, 2, 13, 28}},
        {4, 22, 1125, {1106, "Lever Bearing"}, {1175,"a"}, 32214, {11, 2, 14, 18}},
        {4, 25, 1133, {1198, "Pilot Headset"}, {1142,"a"}, 58341, {17, 2, 16, 52}},
        {4, 33, 1116, {1192, "Steering Actuator Bearings"}, {1155,"a"}, 99338, {19, 2, 10, 19}},
        {4, 15, 1014, {1184, "Engine S3"}, {1153,"a"}, 92231, {14, 2, 12, 25}},
        {4, 15, 1141, {1181, "Drag Brace Bearing"}, {1153,"a"}, 92231, {3, 2, 12, 25}},
    };

    int i = 0;
    int issue_code, product_id = 0;    

    //Display the production line data
    display(product);


    //Task 1 Sort by Date & Time, using Merge Sort
    mergeSort(product, 0, SIZE - 1); //Call mergeSort function

    printf("\n\nTASK 1\nSorted by Date and Time\n"); //Print the sorted data
    for (i = 0; i < SIZE; i++)
    {
        printf("\nDate & Time: %d/%d %d:%d\n", product[i].date.day, product[i].date.month, product[i].date.hour, product[i].date.min);
        printf("Product ID: %d\n", product[i].product_id);
        printf("Issue code: %d | %s\n", product[i].issue_code->code, product[i].issue_code->description);
    }

    //Task 2 create a linked list of product id, issue codes and line ids
    mergeSort2(product, 0, SIZE - 1); //Sorts by product id
    printf("\nTASK 2\n");
    struct node *head = NULL;

    //Fill the linked list
    for (int i = 0; i < SIZE; i++) //Outer for
    {
        for (int j = 0; j < 1; j++) //Nested for
        {
            //Copy the values from data to the linked list
            int issue_code = product[i].issue_code[j].code;
            int product_id = product[i].product_id;
            int line_code = product[i].line_code;

            if (issue_code != 0) //Make sure the code is valid
            {
                insertNode(&head, issue_code, product_id, line_code);
            }
        } //End nested for
    }

    //Print the linked list
    printf("\nLinked List of Issue Codes:\n");
    DisplayList(head);



    //Task 3 : Provide a facility to search for the earliest occurrence of an issue code for a given product id across all production lines 
    printf("\nTASK 3\n");   
    printf("\nPlease enter the Product ID: ");
    scanf("%d", &product_id); //scan desired Product Id

    int result1 = binarySearch(product, 0, SIZE - 1, product_id);
    
    if (result1 == -1)
    {
        printf("Couldn't find product id");
    }
    else 
    {
        printf("\nIssue code: %d\n", result1); //Print the found issue code
    }



    //Task 4
    printf("\nTASK 4\n");
    printf("Please enter the Product ID: "); 
    scanf("%d", &product_id); //Get desired Product ID

    int result2 = IssueCount(product, product_id); //Call function to count issues

    printf("\nNumber of issues: %d\n", result2); //Print the result

    return 0;
}

//Display function to display the structure
void display(struct product_line product[])
{   
    for (int i = 0; i < SIZE; i++)
    {
        printf("\nLine code: %d\n", product[i].line_code);
        printf("Batch code: %d\n", product[i].batch_code);
        printf("Product ID: %d\n", product[i].product_id);
        printf("Issue code: %d\n", product[i].issue_code[0].code);
        printf("Resolution code: %d\n", product[i].resolution_code[0].res_code);
        printf("Employee ID: %d\n", product[i].employee_id);
        printf("Date and time: %d/%d %d:%d\n", product[i].date.day, product[i].date.month, product[i].date.hour, product[i].date.min);
    }
}

//Merge sort algorithm for Task 1 to sort by Date & Time
void merge(struct product_line product[], int l, int m, int r) 
{
    int i = 0;
    int j = 0;
    int k = 0;
    int n1 = m - l + 1; //middle
    int n2 = r - m; //second half

    //Create temporary arrays
    struct product_line L[n1];
    struct product_line R[n2];

    //Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
    {
        L[i] = product[l + i];
    }    
    for (j = 0; j < n2; j++)
    {
        R[j] = product[m + 1 + j];
    }

    //Merge the temporary arrays back into product
    i = 0; // left 
    j = 0; // right 
    k = l; // merged

    while (i < n1 && j < n2) 
    {
        //Compare dates by month then by day hour and minute
        if (L[i].date.month < R[j].date.month ||
            (L[i].date.month <= R[j].date.month && L[i].date.day < R[j].date.day) ||
            (L[i].date.month <= R[j].date.month && L[i].date.day <= R[j].date.day && L[i].date.hour < R[j].date.hour) ||
            (L[i].date.month <= R[j].date.month && L[i].date.day <= R[j].date.day && L[i].date.hour <= R[j].date.hour && L[i].date.min < R[j].date.min)) 
        {
            product[k] = L[i];
            i++;
        } 
        else 
        {
            product[k] = R[j];
            j++;
        
        }

         k++;
      
    }

    //Copy the remaining elements of L
    while (i < n1) 
    {
        product[k] = L[i];
        i++;
        k++;
    }

    //Copy the remaining elements of R
    while (j < n2) 
    {
        product[k] = R[j];
        j++;
        k++;
    } 
}

//Mergesort function for task 2, l is for left index (start) and r is right index (end)
void mergeSort(struct product_line product[], int l, int r) 
{
    if (l < r) {
        //Find the middle index
        int m = (l+r) / 2;

        //Sort first and second halves
        mergeSort(product, l, m);
        mergeSort(product, m + 1, r);

        //Merge the sorted halves
        merge(product, l, m, r);
    }
}

//Merge sort to sort by product id
void merge2(struct product_line product[], int l, int m, int r)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct product_line L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = product[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = product[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].product_id <= R[j].product_id)
        {
            product[k] = L[i];
            i++;
        }
        else 
        {
            product[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) 
    {
        product[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) 
    {
        product[k] = R[j];
        j++;
        k++;
    } 
}

void mergeSort2(struct product_line product[], int l, int r)
{
    if (l < r)
    {
       int m = (l + r) / 2;
       
       mergeSort2(product, l, m);
       mergeSort2(product, m + 1, r);
       merge2(product, l, m, r);
    }
}

//Function to create a new node for linked list task 2
struct node *createNode(int code, int id, int line)
{
    struct node *newNode = malloc(sizeof(struct node));

    if (newNode != NULL) //Malloc was successful
    {
        newNode -> issue_code = code;
        newNode -> product_id = id;
        newNode -> line_code = line;

        newNode -> link = NULL;
    }

    else {
        printf("Failed to allocate memory to pointer");
    }

    return newNode;
};

//Insert a new node at the end of the list
void insertNode(struct node** head, int code, int id, int line)
{
    struct node *newNode = createNode(code, id, line);
    struct node *temp = *head;

    if (*head == NULL) //List is empty
    {
        *head = newNode;
    }

    else
    {
        while (temp -> link != NULL) //Cycle through list
        {
            temp = temp -> link;
        }

        temp -> link = newNode;
    }
}

//Display the linked list
void DisplayList(struct node *head)
{
    struct node *current = head;

    while (current != NULL)
    {
        printf("\nProduct ID: %d |", current -> product_id);
        printf(" Issue Code: %d |", current -> issue_code);
        printf(" Line %d\n", current -> line_code);
        current = current -> link;
    }
};

//Binary search function for task 3
int binarySearch(struct product_line product[], int l, int r, int key)
{
    while (l <= r)
    {
        int m = (l + r) / 2; //Find middle of array

        if (product[m].product_id == key)
        {
            return product[m].issue_code[0].code; //Found product id, return issue code
        }
        else if (product[m].product_id < key)
        {
            l = m + 1; //Narrow search right half
        }
        else
        {
            r = m -1; //Narrow search left half
        }
    }
    return -1; //Not Found

}

//Function for task 4
int IssueCount(struct product_line product[], int product_id)
{
    int i;
    int count = 0;

    for (i = 0; i < SIZE; i++)
    {
        if(product_id == product[i].product_id)
        {
            count++;
        }
    }
    return count;
};
    

    
