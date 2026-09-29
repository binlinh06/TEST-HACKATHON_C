#include <stdio.h>

#define MAX_SIZE 50

int main(void) {
    int stock[MAX_SIZE] = {10, 25, 30, 15, 40};
    int n = 5;
    int choice;
    int value;
    int pos;

    do {
        printf("=====================================================\n");
        printf("        CHUONG TRINH QUAN LY TON KHO MINIMART\n");
        printf("=====================================================\n");
        printf("1. Them so luong ton kho\n");
        printf("2. Sua so luong ton kho\n");
        printf("3. Xoa so luong ton kho\n");
        printf("4. Tim kiem so luong ton kho\n");
        printf("0. Thoat chuong trinh\n");
        printf("=====================================================\n");
        printf("Vui long nhap lua chon cua ban (0 - 4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Kiem tra mang day truoc khi nhap du lieu
                if (n >= MAX_SIZE) {
                    printf("Mang da day, khong the them!\n");
                    break;
                }

                printf("Nhap gia tri can them: ");
                scanf("%d", &value);

                printf("Nhap vi tri can chen (1 - %d): ", n + 1);
                scanf("%d", &pos);

                // Vi tri chen hop le phai tu 1 den n + 1
                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le!\n");
                    break;
                }

                // Dich cac phan tu sang phai
                for (int i = n; i >= pos; i--) {
                    stock[i] = stock[i - 1];
                }
                stock[pos - 1] = value;
                n++;

                // Hien thi lai mang theo dinh dang [x, y, z]
                printf("Mang hien tai: [");
                for (int i = 0; i < n; i++) {
                    printf("%d", stock[i]);
                    if (i < n - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;

            case 2: {
                int newValue;
                printf("Nhap vi tri can sua (1 - %d): ", n);
                scanf("%d", &pos);

                // Kiem tra vi tri sua hop le (1 <= pos <= n)
                if (pos < 1 || pos > n) {
                    printf("Vi tri sua khong hop le!\n");
                    break;
                }

                printf("Nhap so luong ton kho moi: ");
                scanf("%d", &newValue);

                // Kiem tra ton kho khong duoc am
                if (newValue < 0) {
                    printf("So luong ton kho khong hop le!\n");
                    break;
                }

                stock[pos - 1] = newValue;

                // Hien thi lai mang
                printf("Mang hien tai: [");
                for (int i = 0; i < n; i++) {
                    printf("%d", stock[i]);
                    if (i < n - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;
            }

            case 3:
                // Kiem tra mang rong
                if (n == 0) {
                    printf("Mang rong, khong the xoa!\n");
                    break;
                }

                printf("Nhap vi tri can xoa (1 - %d): ", n);
                scanf("%d", &pos);

                // Kiem tra vi tri xoa hop le (1 <= pos <= n)
                if (pos < 1 || pos > n) {
                    printf("Vi tri xoa khong hop le!\n");
                    break;
                }

                // Dich cac phan tu phia sau sang trai
                for (int i = pos - 1; i < n - 1; i++) {
                    stock[i] = stock[i + 1];
                }
                n--;

                // Hien thi lai mang
                printf("Mang hien tai: [");
                for (int i = 0; i < n; i++) {
                    printf("%d", stock[i]);
                    if (i < n - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;

            case 4: {
                int target;
                int count = 0;
                int foundPositions[MAX_SIZE];

                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);

                // Thuat toan tim kiem tuyen tinh
                for (int i = 0; i < n; i++) {
                    if (stock[i] == target) {
                        foundPositions[count] = i + 1; // Luu vi tri bat dau tu 1
                        count++;
                    }
                }

                if (count == 0) {
                    printf("Khong tim thay gia tri trong mang!\n");
                } else {
                    printf("========================================\n");
                    printf("            KET QUA TIM KIEM            \n");
                    printf("========================================\n");
                    printf("Gia tri can tim : %d\n", target);
                    printf("Vi tri          : ");
                    for (int i = 0; i < count; i++) {
                        printf("%d", foundPositions[i]);
                        if (i < count - 1) {
                            printf(", ");
                        }
                    }
                    printf("\n");
                    printf("So lan xuat hien: %d\n", count);
                    printf("========================================\n");
                }
                break;
            }

            case 0:
                printf("Thoat chuong trinh thanh cong!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}