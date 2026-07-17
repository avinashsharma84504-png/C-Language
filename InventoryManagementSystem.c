#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure Definition
struct Product
{
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product p[MAX];
int count = 0;

// Function Declarations
void addProduct();
void displayProducts();
void searchProduct();
void updateProduct();
void sortByPrice();
void totalInventoryValue();

int main()
{
    int choice;

    do
    {
        printf("\n===== Inventory Management System =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Sort Products by Price\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateProduct();
                break;

            case 5:
                sortByPrice();
                printf("Products sorted by price successfully.\n");
                break;

            case 6:
                totalInventoryValue();
                break;

            case 7:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 7);

    return 0;
}

// Function to Add Product
void addProduct()
{
    if(count >= MAX)
    {
        printf("Inventory is Full!\n");
        return;
    }

    printf("\nEnter Product ID: ");
    scanf("%d", &p[count].id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", p[count].name);

    printf("Enter Price: ");
    scanf("%f", &p[count].price);

    printf("Enter Quantity: ");
    scanf("%d", &p[count].quantity);

    count++;

    printf("Product Added Successfully!\n");
}

// Function to Display Products
void displayProducts()
{
    int i;

    if(count == 0)
    {
        printf("No Products Available!\n");
        return;
    }

    printf("\n------------------------------------------------------------\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("------------------------------------------------------------\n");

    for(i = 0; i < count; i++)
    {
        printf("%d\t%-15s%.2f\t%d\n",
               p[i].id,
               p[i].name,
               p[i].price,
               p[i].quantity);
    }
}

// Function to Search Product
void searchProduct()
{
    int id, i;

    printf("Enter Product ID to Search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(p[i].id == id)
        {
            printf("\nProduct Found\n");
            printf("ID       : %d\n", p[i].id);
            printf("Name     : %s\n", p[i].name);
            printf("Price    : %.2f\n", p[i].price);
            printf("Quantity : %d\n", p[i].quantity);
            return;
        }
    }

    printf("Product Not Found!\n");
}

// Function to Update Product
void updateProduct()
{
    int id, i;

    printf("Enter Product ID to Update: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(p[i].id == id)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", p[i].name);

            printf("Enter New Price: ");
            scanf("%f", &p[i].price);

            printf("Enter New Quantity: ");
            scanf("%d", &p[i].quantity);

            printf("Product Updated Successfully!\n");
            return;
        }
    }

    printf("Product Not Found!\n");
}

// Function to Sort Products by Price
void sortByPrice()
{
    int i, j;
    struct Product temp;

    for(i = 0; i < count - 1; i++)
    {
        for(j = i + 1; j < count; j++)
        {
            if(p[i].price > p[j].price)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to Calculate Total Inventory Value
void totalInventoryValue()
{
    int i;
    float total = 0;

    for(i = 0; i < count; i++)
    {
        total += p[i].price * p[i].quantity;
    }

    printf("Total Inventory Value = %.2f\n", total);
}