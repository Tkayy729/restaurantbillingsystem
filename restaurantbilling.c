#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void generateBillHeader(char name[50],char date[30]){
    printf("\n\n");
        printf("\t    TKAYY. Restaurant");
        printf("\n\t   -----------------");
        printf("\nDate:%s",date);
        printf("\nInvoice To: %s",name);
        printf("\n");
        printf("---------------------------------------\n");
        printf("Items\t\t");
        printf("Qty\t\t");
        printf("Total\t\t");
        printf("\n---------------------------------------");
        printf("\n\n");
}

void generateBillBody(char item[30],int qty, float price){
    printf("%s\t\t",item); 
        printf("%d\t\t",qty); 
        printf("%.2f\t\t",qty * price); 
        printf("\n");
}

void generateBillFooter(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;//netTotal + cgst + sgst
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n---------------------------------------\n");
}

int main()
{
    int option;
    // dashboard
    printf("\t==========TKAYY. RESTAURANT==========");
    printf("\n\n1. Generate Invoice");
    printf("\n\n2. Show all Invoices");
    printf("\n\n3. Search Invoice");
    printf("\n\n4. Exit");

    printf("\n\nPlease select yout preferred operation\t\t");
    scanf("%d", &option);
    
    printf("\n\n");
    return 0;
}