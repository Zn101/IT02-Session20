#include <stdio.h>
#include <string.h>

struct Book {
    char bookID[20];
    char bookTitle[50];
    char author[50];
    float price;
    char category[30];
};
typedef struct Book Book;

Book bookList[100];
int bookCount;

void inputBook();
void displayBooks();
void insertBookAtPosition();
void deleteBookByID();
void updateBookByID();
void sortBooksByPrice();
void searchBookByTitle();

int main() {
    int choice;
    do {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
            inputBook();
            break;
            case 2:
            displayBooks();
            break;
            case 3:
            insertBookAtPosition(); 
            break;
            case 4:
            deleteBookByID(); 
            break;
            case 5:
            updateBookByID();
            break;
            case 6:
            sortBooksByPrice();
            break;
            case 7:
            searchBookByTitle(); 
            break;
            case 8:
            break;
        }
    } while (choice != 8);
    return 0;
}

void inputBook() {
    printf("Nhap so luong sach: ");
    scanf("%d", &bookCount);
    getchar();
    for (int i = 0; i < bookCount; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        fgets(bookList[i].bookID, sizeof(bookList[i].bookID), stdin);
        fflush(stdin);
        printf("Ten sach: ");
        fgets(bookList[i].bookTitle, sizeof(bookList[i].bookTitle), stdin);
        fflush(stdin);
        printf("Tac gia: ");
        fgets(bookList[i].author, sizeof(bookList[i].author), stdin);
        fflush(stdin);
        printf("Gia tien: ");
        scanf("%f", &bookList[i].price);
        getchar();
        printf("The loai: ");
        fgets(bookList[i].category, sizeof(bookList[i].category), stdin);
        fflush(stdin);
    }
}

void displayBooks() {
    for (int i = 0; i < bookCount; i++) {
        printf("\nSach %d:\n", i + 1);
        printf("Ma sach: %s", bookList[i].bookID);
        printf("Ten sach: %s", bookList[i].bookTitle);
        printf("Tac gia: %s", bookList[i].author);
        printf("Gia tien: %.2f\n", bookList[i].price);
        printf("The loai: %s\n", bookList[i].category);
    }
}

void insertBookAtPosition() {
    int position;
    printf("Nhap vi tri can them : ");
    scanf("%d", &position);
    getchar();
    for (int i = bookCount; i > position; i--) {
        bookList[i] = bookList[i - 1];
    }
    printf("Ma sach: ");
    fgets(bookList[position].bookID, sizeof(bookList[position].bookID), stdin);
    fflush(stdin);
    printf("Ten sach: ");
    fgets(bookList[position].bookTitle, sizeof(bookList[position].bookTitle), stdin);
    fflush(stdin);
    printf("Tac gia: ");
    fgets(bookList[position].author, sizeof(bookList[position].author), stdin);
    fflush(stdin);
    printf("Gia tien: ");
    scanf("%f", &bookList[position].price);
    getchar();
    printf("The loai: ");
    fgets(bookList[position].category, sizeof(bookList[position].category), stdin);
    fflush(stdin);
    bookCount++;
}

void deleteBookByID() {
    char bookIDToDelete[20];
    printf("Nhap ma sach can xoa: ");
    fgets(bookIDToDelete, sizeof(bookIDToDelete), stdin);
    fflush(stdin);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(bookList[i].bookID, bookIDToDelete) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                bookList[j] = bookList[j + 1];
            }
            bookCount--;
        }
    }
}

void updateBookByID() {
    char bookIDToUpdate[20];
    printf("Nhap ma sach can cap nhat: ");
    fgets(bookIDToUpdate, sizeof(bookIDToUpdate), stdin);
    fflush(stdin);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(bookList[i].bookID, bookIDToUpdate) == 0) {
            printf("Ten sach: ");
            fgets(bookList[i].bookTitle, sizeof(bookList[i].bookTitle), stdin);
            fflush(stdin);
            printf("Tac gia: ");
            fgets(bookList[i].author, sizeof(bookList[i].author), stdin);
            fflush(stdin);
            printf("Gia tien: ");
            scanf("%f", &bookList[i].price);
            getchar();
            printf("The loai: ");
            fgets(bookList[i].category, sizeof(bookList[i].category), stdin);
            fflush(stdin);
        }
    }
}

void sortBooksByPrice() {
    int choice;
    printf("Chon cach sap xep (1: Tang dan, 2: Giam dan): ");
    scanf("%d", &choice);
    getchar();
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if ((choice == 1 && bookList[i].price > bookList[j].price) || 
                (choice == 2 && bookList[i].price < bookList[j].price)) {
                Book temp = bookList[i];
                bookList[i] = bookList[j];
                bookList[j] = temp;
            }
        }
    }
}

void searchBookByTitle() {
    char bookTitleToSearch[50];
    printf("Nhap ten sach can tim: ");
    fgets(bookTitleToSearch, sizeof(bookTitleToSearch), stdin);
    fflush(stdin);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(bookList[i].bookTitle, bookTitleToSearch) != NULL) {
            printf("\nSach %d:\n", i + 1);
            printf("Ma sach: %s", bookList[i].bookID);
            printf("Ten sach: %s", bookList[i].bookTitle);
            printf("Tac gia: %s", bookList[i].author);
            printf("Gia tien: %.2f\n", bookList[i].price);
            printf("The loai: %s\n", bookList[i].category);
            found = 1;
        }
    }
    if (found==0) {
        printf("Khong tim thay sach\n");
    }
}
