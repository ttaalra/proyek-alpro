#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string username;
    string password;
    string role;

public:
    User() {
        username = "";
        password = "";
        role = "";
    }

    void inputUser() {
        cout << "\n========== INPUT USER ==========\n";

        cout << "Username : ";
        cin >> username;

        cout << "Password : ";
        cin >> password;

        cout << "Role (Admin/Kasir/Pelanggan) : ";
        cin >> role;

        cout << "\nData user berhasil ditambahkan.\n";
    }

    void tampilUser() {
        cout << "\n========== DATA USER ==========\n";
        cout << "Username : " << username << endl;
        cout << "Role     : " << role << endl;
    }

    bool login() {
        string userInput, passInput;

        cout << "\n========== LOGIN ==========\n";

        cout << "Username : ";
        cin >> userInput;

        cout << "Password : ";
        cin >> passInput;

        //username = "KharismaBahari"
        //Password = "admin123"

        if(userInput == "KharismaBahari" && passInput == "admin123") {
            username = "KharismaBahari";
            password = "admin123";
            role = "Admin";

            cout << "\nLogin berhasil sebagai Admin.\n";
            return true;
        }

        if(userInput == "kasir" && passInput == "kasir123") {
            username = "kasir";
            password = "kasir123";
            role = "Kasir";

            cout << "\nLogin berhasil sebagai Kasir.\n";
            return true;
        }

        cout << "\nUsername atau Password salah.\n";
        return false;
    }

    string getRole() {
        return role;
    }
};


class CabangWarteg {
private:
    int idCabang;
    string namaCabang;
    string alamatCabang;

public:
    CabangWarteg() {
        idCabang = 0;
        namaCabang = "";
        alamatCabang = "";
    }

    void inputCabang() {
        cout << "\n========== INPUT CABANG ==========\n";

        cout << "ID Cabang : ";
        cin >> idCabang;
        cin.ignore();

        cout << "Nama Cabang : ";
        getline(cin, namaCabang);

        cout << "Alamat Cabang : ";
        getline(cin, alamatCabang);

        cout << "\nData cabang berhasil ditambahkan.\n";
    }

    void tampilCabang() {
        cout << "\n========== DATA CABANG ==========\n";
        cout << "ID Cabang     : " << idCabang << endl;
        cout << "Nama Cabang   : " << namaCabang << endl;
        cout << "Alamat Cabang : " << alamatCabang << endl;
    }

    void editCabang() {
        cout << "\n========== EDIT CABANG ==========\n";
        cin.ignore();

        cout << "Nama Cabang Baru : ";
        getline(cin, namaCabang);

        cout << "Alamat Cabang Baru : ";
        getline(cin, alamatCabang);

        cout << "\nData cabang berhasil diubah.\n";
    }

    void hapusCabang() {
        idCabang = 0;
        namaCabang = "";
        alamatCabang = "";

        cout << "\nData cabang berhasil dihapus.\n";
    }

    void cariCabang() {
        string cari;

        cin.ignore();

        cout << "Masukkan nama cabang : ";
        getline(cin, cari);

        if(cari == namaCabang)
            tampilCabang();
        else
            cout << "Cabang tidak ditemukan.\n";
    }

    void menuCabang() {
        int pilih;

        do {
            cout << "\n========== MENU CABANG ==========\n";
            cout << "1. Input Cabang\n";
            cout << "2. Tampil Cabang\n";
            cout << "3. Edit Cabang\n";
            cout << "4. Hapus Cabang\n";
            cout << "5. Cari Cabang\n";
            cout << "0. Kembali\n";
            cout << "Pilihan : ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                    inputCabang();
                    break;
                case 2:
                    tampilCabang();
                    break;
                case 3:
                    editCabang();
                    break;
                case 4:
                    hapusCabang();
                    break;
                case 5:
                    cariCabang();
                    break;
                case 0:
                    cout << "\nKembali...\n";
                    break;
                default:
                    cout << "\nPilihan tidak tersedia!\n";
            }

        } while(pilih != 0);
    }
};

class Menu {
private:
    int idMenu;
    string namaMenu;
    string kategori;
    int harga;
    int stok;
    string statusKetersediaan;
    int idCabang;

public:
    Menu() {
        idMenu = 0;
        namaMenu = "";
        kategori = "";
        harga = 0;
        stok = 0;
        statusKetersediaan = "";
        idCabang = 0;
    }

    void inputMenu() {
        cout << "\n========== INPUT MENU ==========\n";

        cout << "ID Menu : ";
        cin >> idMenu;
        cin.ignore();

        cout << "Nama Menu : ";
        getline(cin, namaMenu);

        cout << "Kategori (Lauk/Sayur/Gorengan/Sambal/Minuman/Tambahan) : ";
        getline(cin, kategori);

        cout << "Harga : ";
        cin >> harga;
        validasiHarga();

        cout << "Stok : ";
        cin >> stok;
        validasiStok();

        cout << "ID Cabang : ";
        cin >> idCabang;

        cekStatusMenu();

        cout << "\nData menu berhasil ditambahkan.\n";
    }

    void tampilMenu() {
        cout << "\n========== DATA MENU ==========\n";
        cout << "ID Menu : " << idMenu << endl;
        cout << "Nama Menu : " << namaMenu << endl;
        cout << "Kategori : " << kategori << endl;
        cout << "Harga : Rp" << harga << endl;
        cout << "Stok : " << stok << endl;
        cout << "Status : " << statusKetersediaan << endl;
        cout << "ID Cabang : " << idCabang << endl;
    }

    void tampilSingkat() {
        cout << idMenu << "\t"
             << namaMenu << "\t"
             << kategori << "\t"
             << harga << "\t"
             << stok << "\t"
             << statusKetersediaan << "\t"
             << idCabang << endl;
    }

    void editMenu() {
        cout << "\n========== EDIT MENU ==========\n";
        cin.ignore();

        cout << "Nama Menu Baru : ";
        getline(cin, namaMenu);

        cout << "Kategori Baru : ";
        getline(cin, kategori);

        cout << "Harga Baru : ";
        cin >> harga;
        validasiHarga();

        cout << "Stok Baru : ";
        cin >> stok;
        validasiStok();

        cout << "ID Cabang Baru : ";
        cin >> idCabang;

        cekStatusMenu();

        cout << "\nData menu berhasil diubah.\n";
    }

    void hapusMenu() {
        idMenu = 0;
        namaMenu = "";
        kategori = "";
        harga = 0;
        stok = 0;
        statusKetersediaan = "Habis";
        idCabang = 0;

        cout << "\nData menu berhasil dihapus.\n";
    }

    void cariMenu() {
        string cari;
        cin.ignore();

        cout << "Masukkan nama menu : ";
        getline(cin, cari);

        if(cari == namaMenu)
            tampilMenu();
        else
            cout << "Menu tidak ditemukan.\n";
    }

    void urutkanMenu() {
        cout << "\nFitur sorting akan dibuat setelah menggunakan array.\n";
    }

    void validasiHarga() {
        while(harga < 0) {
            cout << "Harga tidak boleh kurang dari 0 : ";
            cin >> harga;
        }
    }

    void validasiStok() {
        while(stok < 0) {
            cout << "Stok tidak boleh kurang dari 0 : ";
            cin >> stok;
        }
    }

    void cekStatusMenu() {
        if(stok > 0)
            statusKetersediaan = "Tersedia";
        else
            statusKetersediaan = "Habis";
    } 
    
        void tambahStok() {
        int tambah;

        cout << "\n========== TAMBAH STOK ==========\n";
        cout << "Menu : " << namaMenu << endl;
        cout << "Stok Saat Ini : " << stok << endl;

        cout << "Jumlah Stok Ditambah : ";
        cin >> tambah;

        if(tambah > 0) {
            stok += tambah;
            cekStatusMenu();
            cout << "\nStok berhasil ditambahkan.\n";
        }
        else {
            cout << "\nJumlah stok tidak valid.\n";
        }
    }

    void kurangiStok() {
        int kurang;

        cout << "\n========== KURANGI STOK ==========\n";
        cout << "Menu : " << namaMenu << endl;
        cout << "Stok Saat Ini : " << stok << endl;

        cout << "Jumlah Stok Dikurangi : ";
        cin >> kurang;

        if(kurang <= stok && kurang > 0) {
            stok -= kurang;
            cekStatusMenu();
            cout << "\nStok berhasil dikurangi.\n";
        }
        else {
            cout << "\nStok tidak mencukupi.\n";
        }
    }

    void pilihCabangMenu() {
        int pilih;

        cout << "\n========== PILIH CABANG ==========\n";
        cout << "1. Cabang 1\n";
        cout << "2. Cabang 2\n";
        cout << "Pilihan : ";
        cin >> pilih;

        switch(pilih) {
            case 1:
                tampilMenuCabang1();
                break;
            case 2:
                tampilMenuCabang2();
                break;
            default:
                cout << "\nPilihan tidak tersedia.\n";
        }
    }
    
        // ==========================
    // MENU CABANG 1
    // ==========================

    void tampilMenuCabang1() {
        cout << "\n=========================================\n";
        cout << "         MENU WARTEG CABANG 1\n";
        cout << "=========================================\n";

        cout << "\n========== MAKANAN POKOK ==========\n";
        cout << "1. Nasi Putih\n";

        tampilLaukCabang1();
        tampilSayurCabang1();
        tampilGorenganCabang1();
        tampilSambalCabang1();
        tampilMinumanCabang1();
        tampilTambahanCabang1();
    }

    void tampilLaukCabang1() {
        cout << "\n========== LAUK ==========\n";
        cout << "1. Ayam Goreng\n";
        cout << "2. Telur Rebus Goreng Balado\n";
        cout << "3. Lele Goreng\n";
        cout << "4. Telur Mata Sapi Balado\n";
        cout << "5. Ikan Bandeng\n";
        cout << "6. Telur Asin\n";
        cout << "7. Tahu Kuah Kuning\n";
        cout << "8. Tahu Balado\n";
        cout << "9. Tempe Orak-Arik\n";
        cout << "10. Mie Goreng\n";
        cout << "11. Ayam Balado\n";
        cout << "12. Ayam Kuah Kuning\n";
        cout << "13. Ayam Kecap\n";
        cout << "14. Semur Daging\n";
        cout << "15. Ayam Suwir\n";
        cout << "16. Tongkol Balado\n";
        cout << "17. Ikan Teri Kacang\n";
    }

    void tampilSayurCabang1() {
        cout << "\n========== SAYUR ==========\n";
        cout << "1. Daun Singkong\n";
        cout << "2. Kangkung\n";
        cout << "3. Capcay\n";
        cout << "4. Sayur Toge\n";
        cout << "5. Sayur Sop\n";
        cout << "6. Terong Kecap\n";
        cout << "7. Sayur Lodeh\n";
        cout << "8. Tumis Kacang Panjang Tempe\n";
        cout << "9. Tumis Sawi Putih\n";
        cout << "10. Tumis Pare\n";
        cout << "11. Sayur Asem\n";
        cout << "12. Sayur Cabai Hijau\n";
    }

    void tampilGorenganCabang1() {
        cout << "\n========== GORENGAN ==========\n";
        cout << "1. Perkedel Kentang\n";
        cout << "2. Bakwan\n";
        cout << "3. Tempe Goreng\n";
    }

    void tampilSambalCabang1() {
        cout << "\n========== SAMBAL ==========\n";
        cout << "1. Sambal Tomat\n";
        cout << "2. Sambal Hijau\n";
        cout << "3. Sambal Terasi Goreng\n";
    }
    
        void tampilMinumanCabang1() {
        cout << "\n========== MINUMAN ==========\n";
        cout << "1. Es Teh Manis\n";
        cout << "2. Es Teh Tawar\n";
        cout << "3. Teh Hangat\n";
        cout << "4. Teh Tawar\n";
        cout << "5. Kopi\n";
        cout << "6. Es Jeruk\n";
        cout << "7. Es Lemon Tea\n";
        cout << "8. Es Nutrisari\n";
        cout << "9. Es Sirup\n";
        cout << "10. Es Kopi Susu\n";
        cout << "11. Es Milo\n";
        cout << "12. Es Kuku Bima\n";
        cout << "13. Es Extra Joss\n";
    }

    void tampilTambahanCabang1() {
        cout << "\n========== TAMBAHAN ==========\n";
        cout << "1. Kerupuk\n";
        cout << "2. Soto Ayam\n";
        cout << "3. Sop Iga\n";
        cout << "4. Air Mineral Botol\n";
    }

    // ==========================
    // MENU CABANG 2
    // ==========================

    void tampilMenuCabang2() {
        cout << "\n=========================================\n";
        cout << "         MENU WARTEG CABANG 2\n";
        cout << "=========================================\n";

        cout << "\n========== MAKANAN POKOK ==========\n";
        cout << "1. Nasi Putih\n";

        tampilLaukCabang2();
        tampilSayurCabang2();
        tampilGorenganCabang2();
        tampilMinumanCabang2();
        tampilTambahanCabang2();
    }

    void tampilLaukCabang2() {
        cout << "\n========== LAUK ==========\n";
        cout << "1. Ayam Goreng\n";
        cout << "2. Ikan Goreng\n";
        cout << "3. Tahu Kuah Kuning\n";
        cout << "4. Telur Balado\n";
        cout << "5. Telur Puyuh\n";
        cout << "6. Telur Asin\n";
        cout << "7. Ayam Kecap\n";
        cout << "8. Ikan Tepung\n";
        cout << "9. Ikan Bandeng\n";
        cout << "10. Tempe Orek\n";
    }

    void tampilSayurCabang2() {
        cout << "\n========== SAYUR ==========\n";
        cout << "1. Kangkung\n";
        cout << "2. Capcay\n";
        cout << "3. Sayur Toge\n";
        cout << "4. Sayur Sop\n";
        cout << "5. Terong Kecap\n";
        cout << "6. Tumis Kacang Panjang Tempe\n";
        cout << "7. Tumis Sawi Putih\n";
        cout << "8. Tumis Pare\n";
        cout << "9. Sayur Asem\n";
        cout << "10. Sayur Lodeh\n";
        cout << "11. Sayur Cabai Hijau\n";
    }

    void tampilGorenganCabang2() {
        cout << "\n========== GORENGAN ==========\n";
        cout << "1. Tahu Goreng\n";
        cout << "2. Tempe Goreng\n";
        cout << "3. Bakwan Jagung\n";
    }
    
        void tampilMinumanCabang2() {
        cout << "\n========== MINUMAN ==========\n";
        cout << "1. Teh Panas\n";
        cout << "2. Es Teh Manis\n";
        cout << "3. Es Teh Tawar\n";
        cout << "4. Teh Tawar\n";
        cout << "5. Kopi Hitam\n";
        cout << "6. Es Kopi Susu\n";
        cout << "7. Es Milo\n";
        cout << "8. Es Nutrisari Jeruk Peras\n";
        cout << "9. Es Nutrisari Jeruk Nipis\n";
        cout << "10. Es Kuku Bima\n";
        cout << "11. Es Extra Joss\n";
        cout << "12. Es Lemon Tea\n";
    }

    void tampilTambahanCabang2() {
        cout << "\n========== TAMBAHAN ==========\n";
        cout << "1. Kerupuk\n";
        cout << "2. Soto Ayam\n";
        cout << "3. Sop Iga\n";
        cout << "4. Air Mineral Botol\n";
    }

    void menuMenu() {
        int pilih;

        do {
            cout << "\n========== MENU MENU ==========\n";
            cout << "1. Input Menu\n";
            cout << "2. Tampil Menu\n";
            cout << "3. Edit Menu\n";
            cout << "4. Hapus Menu\n";
            cout << "5. Cari Menu\n";
            cout << "6. Tambah Stok\n";
            cout << "7. Kurangi Stok\n";
            cout << "8. Lihat Menu Cabang\n";
            cout << "0. Kembali\n";
            cout << "Pilihan : ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                    inputMenu();
                    break;
                case 2:
                    tampilMenu();
                    break;
                case 3:
                    editMenu();
                    break;
                case 4:
                    hapusMenu();
                    break;
                case 5:
                    cariMenu();
                    break;
                case 6:
                    tambahStok();
                    break;
                case 7:
                    kurangiStok();
                    break;
                case 8:
                    pilihCabangMenu();
                    break;
                case 0:
                    cout << "\nKembali...\n";
                    break;
                default:
                    cout << "\nPilihan tidak tersedia!\n";
            }

        } while(pilih != 0);
    }
};
    

class Pesanan {
private:
    int idPesanan;
    int nomorAntrian;
    string daftarMenu;
    int jumlahPesanan;
    int totalHarga;
    string statusPesanan;
    string waktuPesanan;

public:
    void buatPesanan();
    void tampilPesanan();
    void ubahStatusPesanan();
};

class Transaksi {
private:
    int idTransaksi;
    string tanggalTransaksi;
    string metodePembayaran;
    string jenisPesanan;
    string statusPembayaran;

public:
    void prosesTransaksi();
    void tampilTransaksi();
    void cetakStruk();
};

class Pembayaran {
private:
    string metodePembayaran;
    int totalBayar;
    int uangMasuk;
    int kembalian;
    string statusPembayaran;

public:
    void bayarCash();
    void bayarQRIS();
    void tampilPembayaran();
};

class StokBahan {
private:
    int idBahan;
    string namaBahan;
    int stok;
    string satuan;
    string statusStok;

public:
    void inputBahan();
    void restockBahan();
    void tampilBahan();
};

class Karyawan {
private:
    int idKaryawan;
    string nama;
    string alamat;
    string noHP;
    string jabatan;
    string shift;
    int gajiPokok;
    string jamMasuk;
    string jamPulang;
    string statusKerja;

public:
    void inputKaryawan();
    void tampilKaryawan();
    void absensi();
    void hitungGaji();
};

class Membership {
private:
    int idMember;
    string namaMember;
    string noHP;
    int poin;

public:
    void daftarMember();
    void tambahPoin();
    void tampilMember();
};

class Voucher {
private:
    string kodeVoucher;
    string jenisVoucher;
    int diskon;
    bool statusVoucher;

public:
    void buatVoucher();
    void gunakanVoucher();
    void tampilVoucher();
};

class Laporan {
private:
    int totalPendapatan;
    int totalPengeluaran;
    int budgetHarian;
    string periodeLaporan;

public:
    void laporanHarian();
    void laporanMingguan();
    void laporanBulanan();
    void statistikPenjualan();
};

class Sistem {
private:
    User user;
    CabangWarteg cabang;
    Menu menu;

public:
    void menuUtama() {
        int pilih;

        do {
            cout << "\n=====================================\n";
            cout << "        WARTEG DIGITAL\n";
            cout << "=====================================\n";
            cout << "1. Penjual\n";
            cout << "2. Pembeli\n";
            cout << "0. Keluar\n";
            cout << "Pilihan : ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                    menuPenjual();
                    break;
                case 2:
                    menuPembeli();
                    break;
                case 0:
                    cout << "\nTerima kasih.\n";
                    break;
                default:
                    cout << "\nPilihan tidak tersedia!\n";
            }

        } while(pilih != 0);
    }

    void menuPenjual() {
        int pilih;

        do {
            cout << "\n========== MENU PENJUAL ==========\n";
            cout << "1. Daftar User\n";
            cout << "2. Login\n";
            cout << "0. Kembali\n";
            cout << "Pilihan : ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                    user.inputUser();
                    break;

                case 2:
                    if(user.login()) {
                        user.hakAkses();

                        int menuAdmin;

                        do {
                            cout << "\n========== MENU ADMIN ==========\n";
                            cout << "1. Cabang Warteg\n";
                            cout << "2. Menu\n";
                            cout << "0. Logout\n";
                            cout << "Pilihan : ";
                            cin >> menuAdmin;

                            switch(menuAdmin) {
                                case 1:
                                    cabang.menuCabang();
                                    break;

                                case 2:
                                    menu.menuMenu();
                                    break;

                                case 0:
                                    user.logout();
                                    break;

                                default:
                                    cout << "\nPilihan tidak tersedia!\n";
                            }

                        } while(menuAdmin != 0);
                    }
                    break;

                case 0:
                    break;

                default:
                    cout << "\nPilihan tidak tersedia!\n";
            }

        } while(pilih != 0);
    }

    void menuPembeli() {
        int pilih;

        do {
            cout << "\n========== MENU PEMBELI ==========\n";
            cout << "1. Lihat Menu Cabang 1\n";
            cout << "2. Lihat Menu Cabang 2\n";
            cout << "3. Pesan Makanan\n";
            cout << "0. Kembali\n";
            cout << "Pilihan : ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                    menu.tampilMenuCabang1();
                    break;

                case 2:
                    menu.tampilMenuCabang2();
                    break;

                case 3:
                    cout << "\nFitur pemesanan akan dibuat pada Class Pesanan.\n";
                    break;

                case 0:
                    break;

                default:
                    cout << "\nPilihan tidak tersedia!\n";
            }

        } while(pilih != 0);
    }
};

int main() {
    Sistem warteg;
    warteg.menuUtama();

    return 0;
}