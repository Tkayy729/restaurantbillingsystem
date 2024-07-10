#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct items
{
    char item[20];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[20];
    int numberOfItems;
    struct items itm[50];
};

void generateBillHeader(char name[50], char date[30])
{
    printf("\n\n");
    printf("\t    TKAYY. Restaurant");
    printf("\n\t   -----------------");
    printf("\nDate: %s ", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n---------------------------------------");
    printf("\n\n");
}

void generateBillBody(char item[30], int qty, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}

void generateBillFooter(float total)
{
    printf("\n");
    float dis = 0.1 * total;
    float netTotal = total - dis;
    float cgst = 0.09 * netTotal, grandTotal = netTotal + 2 * cgst; // netTotal + cgst + sgst
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n---------------------------------------\n");
}

void displayDashbord()
{
    // dashboard
    printf("\t==========TKAYY. RESTAURANT==========");
    printf("\n\nPlease select yout preferred operation\t");
    printf("\n\n1. Generate Invoice");
    printf("\n\n2. Show all Invoices");
    printf("\n\n3. Search Invoice");
    printf("\n\n4. Exit");
}
int main()
{
    int option;
    struct orders ord;
    struct orders order;
    int n;
    float total;
    FILE *fp;
    char saveBill = 'y';


    displayDashbord();

    printf("\n\nYour choice: \t");
    scanf("%d", &option);

    fgetc(stdin);
    switch (option)
    {
    case 1:
        system("clear");
        printf("\nPlease enter the name of the customer:\t");
        fgets(ord.customer, 50, stdin);
        ord.customer[strlen(ord.customer) - 1] = 0;
        strcpy(ord.date, __DATE__);
        printf("\nPlease enter the number of the items:\t");
        scanf("%d", &n);
        ord.numberOfItems = n;
        for (int i = 0; i < n; i++)
        {
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d: \t", i + 1);
            fgets(ord.itm[i].item, 20, stdin);
            ord.itm[i].item[strlen(ord.itm[i].item) - 1] = 0;
            printf("\nPlease enter the quantity:\t");
            scanf("%d", &ord.itm[i].qty);
            printf("\nPlease enter the unit price: \t");
            scanf("%f", &ord.itm[i].price);
            total += ord.itm[i].price * ord.itm[i].qty;
        }
        generateBillHeader(ord.customer, ord.date);
        for(int i = 0; i < ord.numberOfItems; i++)
        {
            generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
        }
        generateBillFooter(total);

        printf("\nDo you want to save the invoice [y/n]:\t");
        scanf("%s",&saveBill);
        
        if(saveBill == 'y')
        {
            fp = fopen("RestaurantBill.dat", "a+");
            fwrite(&ord, sizeof(struct orders), 1, fp);
            if(&fwrite != 0)
                printf("\nSuccessfully saved");
            else
                printf("\nError saving");
            fclose(fp);
        }
        break;

        case 2:
            system("clear");
            fp = fopen("RestaurantBill.dat", "r");
            printf("\n *********Your Previous Invoives********");
            while(fread(&order, sizeof(struct orders), 1, fp))
            {
                float tot = 0;
                generateBillHeader(order.customer, order.date);
                for(int i =0; i < order.numberOfItems; i++)
                {
                    generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                    tot += order.itm[i].qty * order.itm[i].price;
                }
                generateBillFooter(tot);
            }
            fclose(fp);
            break;
    }


    printf("\n\n");
    return 0;
}