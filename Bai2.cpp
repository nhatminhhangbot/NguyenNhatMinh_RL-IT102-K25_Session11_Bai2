#include <stdio.h>

typedef struct {
    char ma_kien_hang[20];
    float trong_luong;
    float nhiet_do_yeu_cau;
} PalletItem;

typedef struct {
    char ma_ke[20];
    float trong_luong_hien_tai;
    float tai_trong_toi_da;
    int la_kho_lanh;
} WarehouseShelf;

int kiem_tra_nhap_kho(WarehouseShelf ke, PalletItem kien) {
    if (ke.trong_luong_hien_tai + kien.trong_luong > ke.tai_trong_toi_da) {
        return 0;
    }

    if (ke.la_kho_lanh == 1) {
        if (kien.nhiet_do_yeu_cau >= -18.0 && kien.nhiet_do_yeu_cau <= 5.0) {
            return 1;
        } else {
            return 0;
        }
    }

    return 1;
}

int main() {
    WarehouseShelf ke_lanh_A1 = {"KE-COLD-01", 350.0, 500.0, 1};

    PalletItem kien_hop_le = {"PL-COLD-01", 100.0, -10.0};
    PalletItem kien_sai_nhiet_do = {"PL-DRY-88", 80.0, 25.0};
    PalletItem kien_vuot_tai_trong = {"PL-HEAVY-01", 200.0, -2.0};

    printf("--- TEST CASE 1: KIEN HANG HOP LE VAO KHO LANH ---\n");
    if (kiem_tra_nhap_kho(ke_lanh_A1, kien_hop_le) == 1) {
        printf("KET QUA: CHO PHEP NHAP KHO\n");
    } else {
        printf("KET QUA: TU CHOI NHAP KHO\n");
    }

    printf("\n--- TEST CASE 2: KIEN HANG SAI NHIET DO KHO LANH ---\n");
    if (kiem_tra_nhap_kho(ke_lanh_A1, kien_sai_nhiet_do) == 1) {
        printf("KET QUA: CHO PHEP NHAP KHO\n");
    } else {
        printf("KET QUA: TU CHOI NHAP KHO\n");
    }

    printf("\n--- TEST CASE 3: KIEN HANG VUOT TAI TRONG TOI DA ---\n");
    if (kiem_tra_nhap_kho(ke_lanh_A1, kien_vuot_tai_trong) == 1) {
        printf("KET QUA: CHO PHEP NHAP KHO\n");
    } else {
        printf("KET QUA: TU CHOI NHAP KHO\n");
    }

    return 0;
}
