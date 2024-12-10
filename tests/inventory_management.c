#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define DATA_FILE "inventory.txt"

// Structure to hold an inventory item
typedef struct
{
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

// Function prototypes
void loadInventory(Item items[], int *count);
void saveInventory(Item items[], int count);
void addItem(Item items[], int *count);
void viewItems(Item items[], int count);
void updateItem(Item items[], int count);
void deleteItem(Item items[], int *count);
void sortItemsByName(Item items[], int count);
void searchItemByName(Item items[], int count);
void displayStatistics(Item items[], int count);

int main()
{
    Item items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    // Load inventory from file
    loadInventory(items, &itemCount);

    while (1)
    {
        printf("\nInventory Management System\n");
        printf("1. View Items\n");
        printf("2. Add Item\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Sort Items by Name\n");
        printf("6. Search Item by Name\n");
        printf("7. Display Inventory Statistics\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            viewItems(items, itemCount);
            break;
        case 2:
            addItem(items, &itemCount);
            break;
        case 3:
            updateItem(items, itemCount);
            break;
        case 4:
            deleteItem(items, &itemCount);
            break;
        case 5:
            sortItemsByName(items, itemCount);
            break;
        case 6:
            searchItemByName(items, itemCount);
            break;
        case 7:
            displayStatistics(items, itemCount);
            break;
        case 8:
            saveInventory(items, itemCount);
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to load inventory from file
void loadInventory(Item items[], int *count)
{
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL)
    {
        printf("No existing inventory found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%d %s %d %f", &items[*count].id, items[*count].name,
                  &items[*count].quantity, &items[*count].price) != EOF)
    {
        (*count)++;
    }

    fclose(file);
}

// Function to save inventory to file
void saveInventory(Item items[], int count)
{
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL)
    {
        printf("Error saving inventory!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d %s %d %.2f\n", items[i].id, items[i].name,
                items[i].quantity, items[i].price);
    }

    fclose(file);
}

// Function to add a new item to the inventory
void addItem(Item items[], int *count)
{
    if (*count >= MAX_ITEMS)
    {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);

    items[*count] = newItem;
    (*count)++;
}

// Function to view all items in the inventory
void viewItems(Item items[], int count)
{
    if (count == 0)
    {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\nID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%d\t\t%.2f\n", items[i].id, items[i].name,
               items[i].quantity, items[i].price);
    }
}

// Function to update an item's details
void updateItem(Item items[], int count)
{
    if (count == 0)
    {
        printf("No items in the inventory to update.\n");
        return;
    }

    int id, found = 0;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (items[i].id == id)
        {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", items[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &items[i].price);
            break;
        }
    }

    if (!found)
    {
        printf("Item with ID %d not found.\n", id);
    }
}

// Function to delete an item from the inventory
void deleteItem(Item items[], int *count)
{
    if (*count == 0)
    {
        printf("No items in the inventory to delete.\n");
        return;
    }

    int id, found = 0;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++)
    {
        if (items[i].id == id)
        {
            found = 1;
            for (int j = i; j < *count - 1; j++)
            {
                items[j] = items[j + 1];
            }
            (*count)--;
            break;
        }
    }

    if (!found)
    {
        printf("Item with ID %d not found.\n", id);
    }
}

// Function to sort items by name alphabetically
void sortItemsByName(Item items[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(items[i].name, items[j].name) > 0)
            {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    printf("Items sorted by name successfully.\n");
}

// Function to search for an item by name
void searchItemByName(Item items[], int count)
{
    char searchName[MAX_NAME_LEN];

    if (count == 0)
    {
        printf("No items in the inventory to search.\n");
        return;
    }

    printf("Enter the name of the item to search for: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(items[i].name, searchName) == 0)
        {
            printf("\nFound Item:\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",
                   items[i].id, items[i].name, items[i].quantity,
                   items[i].price);
            return;
        }
    }

    printf("No item with name '%s' found.\n", searchName);
}

// Function to display statistics about the inventory
void displayStatistics(Item items[], int count)
{

    if (count == 0)
    {
        printf("No Items exist currently \n");
        return;
    }

    int totalQuantity = 0;
    float totalCost = 0;

    for (int k = 0; k < count; k++)
    {
        totalQuantity += items[k].quantity;

        totalCost += items[k].quantity * items[k].price;
    }

    printf("Total Quantity:%d Total Cost %.2f ", totalQuantity, totalCost);
}
