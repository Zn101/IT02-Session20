#include <stdio.h>
#include <string.h>

struct Product {
    char productID[20];
    char productName[50];
    float importPrice;
    float salePrice;
    int quantity;
};
typedef struct Product Product;

Product productList[100];
int productCount = 0;
float revenue = 0.0;

void inputProduct();
void displayProducts();
void insertProduct();
void updateProduct();
void sortProductsByPrice();
void searchProduct();
void sellProduct();
void displayRevenue();

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia (tang/gi?m)\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                inputProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                insertProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                sortProductsByPrice();
                break;
            case 6:
                searchProduct();
                break;
            case 7:
                sellProduct();
                break;
            case 8:
                displayRevenue();
                break;
            case 9:
                break;
        }
    } while (choice != 9);
    return 0;
}

void inputProduct() {
    printf("Nhap so luong san pham: ");
    scanf("%d", &productCount);
    getchar();
    for (int i = 0; i < productCount; i++) {
        printf("\nNhap thong tin san pham thu %d:\n", i + 1);
        printf("Ma san pham: ");
        fgets(productList[i].productID, sizeof(productList[i].productID), stdin);
        fflush(stdin);
        printf("Ten san pham: ");
        fgets(productList[i].productName, sizeof(productList[i].productName), stdin);
        fflush(stdin);
        printf("Gia nhap: ");
        scanf("%f", &productList[i].importPrice);
        getchar();
        printf("Gia ban: ");
        scanf("%f", &productList[i].salePrice);
        getchar();
        printf("So luong: ");
        scanf("%d", &productList[i].quantity);
        getchar();
    }
}

void displayProducts() {
    for (int i = 0; i < productCount; i++) {
        printf("\nSan pham %d:\n", i + 1);
        printf("Ma san pham: %s", productList[i].productID);
        printf("Ten san pham: %s", productList[i].productName);
        printf("Gia nhap: %.2f\n", productList[i].importPrice);
        printf("Gia ban: %.2f\n", productList[i].salePrice);
        printf("So luong: %d\n", productList[i].quantity);
    }
}

void insertProduct() {
    char productID[20];
    printf("Nhap ma san pham can them: ");
    fgets(productID, sizeof(productID), stdin);
    fflush(stdin);
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(productList[i].productID, productID) == 0) {
            printf("San pham da ton tai, tang so luong\n");
            printf("Nhap so luong can them: ");
            int quantity;
            scanf("%d", &quantity);
            productList[i].quantity += quantity;
            found = 1;
            break;
        }
    }
    if (found==0) {
        printf("Nhap thong tin san pham moi\n");
        printf("Ma san pham: ");
        fgets(productList[productCount].productID, sizeof(productList[productCount].productID), stdin);
        fflush(stdin);
        printf("Ten san pham: ");
        fgets(productList[productCount].productName, sizeof(productList[productCount].productName), stdin);
        fflush(stdin);
        printf("Gia nhap: ");
        scanf("%f", &productList[productCount].importPrice);
        getchar();
        printf("Gia ban: ");
        scanf("%f", &productList[productCount].salePrice);
        getchar();
        printf("So luong: ");
        scanf("%d", &productList[productCount].quantity);
        productCount++;
    }
}

void updateProduct() {
    char productID[20];
    printf("Nhap ma san pham can cap nhat: ");
    fgets(productID, sizeof(productID), stdin);
    fflush(stdin);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(productList[i].productID, productID) == 0) {
            printf("Cap nhat thong tin san pham:\n");
            printf("Ten san pham: ");
            fgets(productList[i].productName, sizeof(productList[i].productName), stdin);
            fflush(stdin);
            printf("Gia nhap: ");
            scanf("%f", &productList[i].importPrice);
            getchar();
            printf("Gia ban: ");
            scanf("%f", &productList[i].salePrice);
            getchar();
            printf("So luong: ");
            scanf("%d", &productList[i].quantity);
            getchar();
        }
    }
}

void sortProductsByPrice() {
    int choice;
    printf("Chon cach sap xep (1: Tang dan, 2: Giam dan): ");
    scanf("%d", &choice);
    getchar();
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = i + 1; j < productCount; j++) {
            if ((choice == 1 && productList[i].salePrice > productList[j].salePrice) || 
                (choice == 2 && productList[i].salePrice < productList[j].salePrice)) {
                Product temp = productList[i];
                productList[i] = productList[j];
                productList[j] = temp;
            }
        }
    }
}

void searchProduct() {
    char productName[50];
    printf("Nhap ten san pham can tim: ");
    fgets(productName, sizeof(productName), stdin);
    fflush(stdin);
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strstr(productList[i].productName, productName) != NULL) {
            printf("\nSan pham %d:\n", i + 1);
            printf("Ma san pham: %s", productList[i].productID);
            printf("Ten san pham: %s", productList[i].productName);
            printf("Gia nhap: %.2f\n", productList[i].importPrice);
            printf("Gia ban: %.2f\n", productList[i].salePrice);
            printf("So luong: %d\n", productList[i].quantity);
            found = 1;
        }
    }
    if (found==0) {
        printf("Khong tim thay san pham\n");
    }
}

void sellProduct() {
    char productID[20];
    printf("Nhap ma san pham can ban: ");
    fgets(productID, sizeof(productID), stdin);
    fflush(stdin);
    int quantityToSell;
    printf("Nhap so luong can ban: ");
    scanf("%d", &quantityToSell);
    getchar();
    for (int i = 0; i < productCount; i++) {
        if (strcmp(productList[i].productID, productID) == 0) {
            if (productList[i].quantity == 0) {
                printf("San pham da het hang\n");
            } else if (productList[i].quantity < quantityToSell) {
                printf("Khong con du hang de ban\n");
            } else {
                productList[i].quantity -= quantityToSell;
                revenue += productList[i].salePrice * quantityToSell;
                printf("Ban thanh cong %d san pham\n", quantityToSell);
            }
        }
    }
}

void displayRevenue() {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}
