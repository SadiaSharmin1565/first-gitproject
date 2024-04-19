#include<stdio.h>
#include<string.h>

struct project{
    char name[50];
    float profit;
    int manpower;
    int equipment;
    float funds;
    int day;
};

int main(){
    struct project projects[50];
    int pnumber = 0;
    int option;
    int availableEm, availableEq, availableFd, availableDay;
   while(1){
        printf("\n****** Project Management System ******\n");
        printf("1. Add Project\n");
        printf("2. Display All Projects\n");
        printf("3. Display Projects by Profitability\n");
        printf("4. Display Projects by Time\n");
        printf("5. Recommanded Project:\n");
        printf("0. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nEnter details for Project %d:\n", pnumber + 1);
                printf("Enter project name: ");
                scanf("%s", projects[pnumber].name);
                printf("Enter required manpower: ");
                scanf("%d", &projects[pnumber].manpower);
                printf("Enter required equipment: ");
                scanf("%d", &projects[pnumber].equipment);
                printf("Enter required funds: ");
                scanf("%f", &projects[pnumber].funds);
                printf("Enter project complete days (in days): ");
                scanf("%d", &projects[pnumber].day);
                printf("Profitability: ");
                scanf("%f", &projects[pnumber].profit);

                pnumber++;
                printf("Project added successfully!\n");
                break;
            case 2:
                showProjects(projects, pnumber);
                break;
            case 3:
                sortByProfit(projects, pnumber);
                break;
            case 4:
                sortByDays(projects, pnumber);
                break;
            case 5:
                    printf("\nEnter total available manpower: ");
                    scanf("%d", &availableEm);
                    printf("Enter total available equipment: ");
                    scanf("%d", &availableEq);
                    printf("Enter total available funds: ");
                    scanf("%d", &availableFd);
                    printf("Enter total available days: ");
                    scanf("%d", &availableDay);
                    recommendProjects(projects, pnumber, availableEm, availableEq, availableFd, availableDay);
                break;
            case 0:
                printf("Exiting...\n");
                 return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    };

    return 0;
}



// Function to display projects
void showProjects(struct project projects[], int pnumber){
    if (pnumber==0){
        printf("There is no project.\n");
        return;
    }
    printf("\n****** Projects List *****\n");
    for(int i=0;i<pnumber;i++){
        printf("Project ID %d:\n", i + 1);
        printf("Project name: %s\n", projects[i].name);
        printf("Profitability: %.2f\n", projects[i].profit);
        printf("Required manpower: %d\n", projects[i].manpower);
        printf("Required equipment: %d\n", projects[i].equipment);
        printf("Required funds: %.2f\n", projects[i].funds);
        printf("Required days: %d days\n", projects[i].day);
        printf("*************************\n");
    }
}



void recommendProjects(struct project projects[], int pnumber, int availableEmp, int availableEq, int availableFd,int availableDays) {
    float totalProfit=0;
    if(pnumber==0){
        printf("There is no project.\n");
        return;
    }
    printf("Recommended Projects:\n");
      for(int i=0;i<pnumber; i++){
        if(availableEmp >= projects[i].manpower && availableEq >= projects[i].equipment && availableFd >= projects[i].funds && availableDays >= projects[i].day) {
            printf("Project name: %s\n", projects[i].name);
            totalProfit = totalProfit + projects[i].profit;
            availableEmp= availableEmp - projects[i].manpower;
            availableEq = availableEq - projects[i].equipment;
            availableFd = availableFd - projects[i].funds;
            availableDays = availableDays - projects[i].day;
        }
    }

    printf("Total profit of recommended projects: %.2f\n", totalProfit);
}



// Function to sort projects by profit
void sortByProfit(struct project projects[], int pnumber){
    for(int i = 0; i < pnumber - 1; i++){
        int max = i;
        for (int j = i + 1; j < pnumber; j++){
            if (projects[j].profit > projects[max].profit){
                max = j;
            }
        }
        if(max!=i){
            struct project temp = projects[i];
            projects[i] = projects[max];
            projects[max] = temp;
        }
    }

    printf("\n****** Projects sorted by profit *****\n");
    showProjects(projects, pnumber);
}

// Function to sort projects by days
void sortByDays(struct project projects[], int pnumber){
    for(int i=0; i<pnumber-1;i++){
        int min=i;
        for(int j=i+1;j<pnumber;j++){
            if(projects[j].day<projects[min].day){
                min=j;
            }
        }
        if(min!= i){
            struct project temp=projects[i];
            projects[i]=projects[min];
            projects[min]=temp;
        }
    }

    printf("\n******* Projects sorted by days ******\n");
    showProjects(projects, pnumber);
}



