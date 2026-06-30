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
        string user, pass;

        cout << "\n========== LOGIN ==========\n";

        cout << "Username : ";
        cin >> user;

        cout << "Password : ";
        cin >> pass;

        if(user == username && pass == password) {
            cout << "\nLogin berhasil.\n";
            return true;
        }

        cout << "\nUsername atau password salah.\n";
        return false;
    }

    void logout() {
        cout << "\nLogout berhasil.\n";
    }

    void hakAkses() {
        cout << "\n========== HAK AKSES ==========\n";

        if(role == "Admin")
            cout << "Hak akses : Admin\n";
        else if(role == "Kasir")
            cout << "Hak akses : Kasir\n";
        else if(role == "Pelanggan")
            cout << "Hak akses : Pelanggan\n";
        else
            cout << "Role tidak dikenali.\n";
    }

    void menuUser() {
        int pilih;

        do {
            cout << "\n========== MENU USER ==========\n";
            cout << "1. Input User\n";
            cout << "2. Tampil User\n";
            cout << "3. Login\n";
            cout << "4. Hak Akses\n";
            cout << "5. Logout\n";
            cout << "0. Kembali\n";
            cout << "Pilihan : ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                    inputUser();
                    break;
                case 2:
                    tampilUser();
                    break;
                case 3:
                    login();
                    break;
                case 4:
                    hakAkses();
                    break;
                case 5:
                    logout();
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


    Pesanan(){

        idPesanan = 0;
        nomorAntrian = 0;
        daftarMenu = "";
        jumlahPesanan = 0;
        totalHarga = 0;
        statusPesanan = "";
        waktuPesanan = "";

    }

    //=========================
    // BUAT PESANAN
    //=========================

    void buatPesanan(){

        cout<<"\n========== BUAT PESANAN ==========\n";


        cout<<"ID Pesanan : ";
        cin>>idPesanan;


        cout<<"Nomor Antrian : ";
        cin>>nomorAntrian;


        cin.ignore();


        cout<<"Daftar Menu : ";
        getline(cin, daftarMenu);



        cout<<"Jumlah Pesanan : ";
        cin>>jumlahPesanan;



        cout<<"Total Harga : ";
        cin>>totalHarga;



        cout<<"Waktu Pesanan : ";
        cin>>waktuPesanan;



        statusPesanan="Diproses";


        cout<<"\nPesanan berhasil dibuat.\n";

    }

    //=========================
    // TAMPIL PESANAN
    //=========================


    void tampilPesanan(){


        cout<<"\n========== DATA PESANAN ==========\n";


        cout<<"ID Pesanan     : "<<idPesanan<<endl;
        cout<<"Nomor Antrian  : "<<nomorAntrian<<endl;
        cout<<"Menu           : "<<daftarMenu<<endl;
        cout<<"Jumlah         : "<<jumlahPesanan<<endl;
        cout<<"Total Harga    : Rp"<<totalHarga<<endl;
        cout<<"Status         : "<<statusPesanan<<endl;
        cout<<"Waktu          : "<<waktuPesanan<<endl;


    }
    //=========================
    // EDIT PESANAN
    //=========================
    void editPesanan(){
        cout<<"\n========== EDIT PESANAN ==========\n";


        cin.ignore();

        cout<<"Menu Baru : ";
        getline(cin, daftarMenu);

        cout<<"Jumlah Baru : ";
        cin>>jumlahPesanan;



        cout<<"Total Harga Baru : ";
        cin>>totalHarga;


        cout<<"Status Baru : ";
        cin>>statusPesanan;

        cout<<"\nPesanan berhasil diubah.\n";


    }


    //=========================
    // HAPUS PESANAN
    //=========================

    void hapusPesanan(){


        idPesanan=0;
        nomorAntrian=0;
        daftarMenu="";
        jumlahPesanan=0;
        totalHarga=0;
        statusPesanan="Dihapus";
        waktuPesanan="";


        cout<<"\nPesanan berhasil dihapus.\n";


    }

    //=========================
    // CARI PESANAN
    //=========================


    void cariPesanan(){


        string cari;


        cin.ignore();


        cout<<"Masukkan menu yang dicari : ";
        getline(cin,cari);



        if(cari==daftarMenu){


            cout<<"\nPesanan ditemukan\n";

            tampilPesanan();


        }
        else{


            cout<<"\nPesanan tidak ditemukan.\n";


        }


    }

    //=========================
    // UBAH STATUS
    //=========================


    void ubahStatusPesanan(){


        cout<<"\nStatus sekarang : "<<statusPesanan<<endl;


        cout<<"Status baru : ";
        cin>>statusPesanan;



        cout<<"Status berhasil diubah.\n";


    }

};

/=====================================================
// CLASS TRANSAKSI
//=====================================================

class Transaksi {

private:

    int idTransaksi;
    string tanggalTransaksi;
    string metodePembayaran;
    string jenisPesanan;
    string statusPembayaran;
    int totalTransaksi;


public:

    //=========================
    // CONSTRUCTOR
    //=========================

    Transaksi(){

        idTransaksi = 0;
        tanggalTransaksi = "";
        metodePembayaran = "";
        jenisPesanan = "";
        statusPembayaran = "";
        totalTransaksi = 0;

    }

    //=========================
    // INPUT TRANSAKSI
    //=========================

    void inputTransaksi(){

        cout<<"\n========== INPUT TRANSAKSI ==========\n";

        cout<<"ID Transaksi : ";
        cin>>idTransaksi;

        cout<<"Tanggal Transaksi : ";
        cin>>tanggalTransaksi;

        cin.ignore();

        cout<<"Jenis Pesanan : ";
        getline(cin, jenisPesanan);

        cout<<"Total Transaksi : ";
        cin>>totalTransaksi;

        cout<<"Metode Pembayaran : ";
        cin>>metodePembayaran;

        statusPembayaran="Belum Lunas";

        cout<<"\nTransaksi berhasil dibuat.\n";


    }

    //=========================
    // TAMPIL TRANSAKSI
    //=========================

    void tampilTransaksi(){

        cout<<"\n========== DATA TRANSAKSI ==========\n";

        cout<<"ID Transaksi        : "<<idTransaksi<<endl;
        cout<<"Tanggal             : "<<tanggalTransaksi<<endl;
        cout<<"Jenis Pesanan       : "<<jenisPesanan<<endl;
        cout<<"Total               : Rp"<<totalTransaksi<<endl;
        cout<<"Metode Pembayaran   : "<<metodePembayaran<<endl;
        cout<<"Status Pembayaran   : "<<statusPembayaran<<endl;

    }
    
    //=========================
    // EDIT TRANSAKSI
    //=========================

    void editTransaksi(){


        cout<<"\n========== EDIT TRANSAKSI ==========\n";

        cin.ignore();

        cout<<"Jenis Pesanan Baru : ";
        getline(cin,jenisPesanan);

        cout<<"Total Baru : ";
        cin>>totalTransaksi;

        cout<<"Metode Pembayaran Baru : ";
        cin>>metodePembayaran;

        cout<<"Status Pembayaran Baru : ";
        cin>>statusPembayaran;

        cout<<"\nTransaksi berhasil diperbarui.\n";


    }
     //=========================
    // HAPUS TRANSAKSI
    //=========================

   void hapusTransaksi(){

        idTransaksi=0;
        tanggalTransaksi="";
        jenisPesanan="";
        totalTransaksi=0;
        metodePembayaran="";
        statusPembayaran="Dihapus";

        cout<<"\nData transaksi berhasil dihapus.\n";

    }
    //=========================
    // CARI TRANSAKSI
    //=========================

    void cariTransaksi(){

        int cari;

        cout<<"\nMasukkan ID Transaksi : ";
        cin>>cari;

        if(cari==idTransaksi){

            cout<<"\nTransaksi ditemukan.\n";

            tampilTransaksi();

        }

        else{

            cout<<"\nTransaksi tidak ditemukan.\n";

        }

    }
    //=========================
    // CETAK STRUK
    //=========================

    void cetakStruk(){

        cout<<"\n====================================\n";
        cout<<"          STRUK WARTEG DIGITAL\n";
        cout<<"====================================\n";

        cout<<"ID Transaksi : "<<idTransaksi<<endl;
        cout<<"Tanggal      : "<<tanggalTransaksi<<endl;
        cout<<"Pesanan      : "<<jenisPesanan<<endl;
        cout<<"Total        : Rp"<<totalTransaksi<<endl;
        cout<<"Pembayaran   : "<<metodePembayaran<<endl;
        cout<<"Status       : "<<statusPembayaran<<endl;


        cout<<"====================================\n";

    }
    //=========================
    // UBAH STATUS
    //=========================

    void ubahStatusPembayaran(){

        cout<<"\nStatus saat ini : "<<statusPembayaran<<endl;

        cout<<"Status baru : ";
        cin>>statusPembayaran;

        cout<<"Status berhasil diubah.\n";

    }

};

//=====================================================
// CLASS PEMBAYARAN
//=====================================================

class Pembayaran {

private:

    string metodePembayaran;
    int totalBayar;
    int uangMasuk;
    int kembalian;
    string statusPembayaran;

public:

    //=========================
    // CONSTRUCTOR
    //=========================

    Pembayaran(){

        metodePembayaran="";
        totalBayar=0;
        uangMasuk=0;
        kembalian=0;
        statusPembayaran="";

    }
    
    //=========================
    // INPUT PEMBAYARAN
    //=========================

    void inputPembayaran(){

        cout<<"\n========== INPUT PEMBAYARAN ==========\n";

        cout<<"Total Bayar : ";
        cin>>totalBayar;
        
        cout<<"Metode Pembayaran : ";
        cin>>metodePembayaran;


        if(metodePembayaran=="Cash" ||
           metodePembayaran=="cash"){

            bayarCash();

        }

        else if(metodePembayaran=="QRIS" ||
                metodePembayaran=="qris"){

            bayarQRIS();

        }

        else{

            statusPembayaran="Metode tidak tersedia";

        }

    }

    //=========================
    // BAYAR CASH
    //=========================

    void bayarCash(){

        cout<<"\n========== PEMBAYARAN CASH ==========\n";
        
        cout<<"Total : Rp"<<totalBayar<<endl;

        cout<<"Uang Masuk : ";
        cin>>uangMasuk;

        kembalian =
        uangMasuk - totalBayar;

        if(kembalian >= 0){

            statusPembayaran="Lunas";

            cout<<"Kembalian : Rp"
            <<kembalian<<endl;

        }
        else{

            statusPembayaran="Uang Kurang";

            cout<<"Uang kurang : Rp"
            <<-kembalian<<endl;

        }

    }

    //=========================
    // BAYAR QRIS
    //=========================

    void bayarQRIS(){

        cout<<"\n========== PEMBAYARAN QRIS ==========\n";

        metodePembayaran="QRIS";

        statusPembayaran="Lunas";

        kembalian=0;

        cout<<"Pembayaran QRIS berhasil.\n";

    }

    //=========================
    // TAMPIL PEMBAYARAN
    //=========================

    void tampilPembayaran(){

        cout<<"\n========== DATA PEMBAYARAN ==========\n";

        cout<<"Metode          : "
        <<metodePembayaran<<endl;

        cout<<"Total Bayar     : Rp"
        <<totalBayar<<endl;

        cout<<"Uang Masuk      : Rp"
        <<uangMasuk<<endl;

        cout<<"Kembalian       : Rp"
        <<kembalian<<endl;

        cout<<"Status          : "
        <<statusPembayaran<<endl;

    }

    //=========================
    // EDIT PEMBAYARAN
    //=========================

    void editPembayaran(){

        cout<<"\n========== EDIT PEMBAYARAN ==========\n";

        cout<<"Total Baru : ";
        cin>>totalBayar;

        cout<<"Metode Baru : ";
        cin>>metodePembayaran;

        cout<<"Status Baru : ";
        cin>>statusPembayaran;

        cout<<"\nData pembayaran berhasil diubah.\n";

    }

    //=========================
    // HAPUS PEMBAYARAN
    //=========================

    void hapusPembayaran(){

        metodePembayaran="";
        totalBayar=0;
        uangMasuk=0;
        kembalian=0;
        statusPembayaran="Dihapus";

        cout<<"\nData pembayaran berhasil dihapus.\n";

    }

    //=========================
    // CARI PEMBAYARAN
    //=========================

    void cariPembayaran(){

        string cari;

        cout<<"\nMasukkan metode pembayaran : ";
        cin>>cari;

        if(cari==metodePembayaran){

            cout<<"\nPembayaran ditemukan.\n";

            tampilPembayaran();

        }

        else{

            cout<<"\nData pembayaran tidak ditemukan.\n";

        }

    }

};

//=====================================================
// CLASS STOK BAHAN
//=====================================================

class StokBahan {

private:

    int idBahan;
    string namaBahan;
    int stok;
    string satuan;
    string statusStok;

public:

    //=========================
    // CONSTRUCTOR
    //=========================

    StokBahan(){

        idBahan=0;
        namaBahan="";
        stok=0;
        satuan="";
        statusStok="";

    }
    
    //=========================
    // INPUT BAHAN
    //=========================


    void inputBahan(){

        cout<<"\n========== INPUT BAHAN ==========\n";

        cout<<"ID Bahan : ";
        cin>>idBahan;

        cin.ignore();

        cout<<"Nama Bahan : ";
        getline(cin,namaBahan);


        cout<<"Jumlah Stok : ";
        cin>>stok;


        cout<<"Satuan : ";
        cin>>satuan;


        if(stok>0)

            statusStok="Tersedia";

        else

            statusStok="Habis";


        cout<<"\nData bahan berhasil ditambahkan.\n";

    }

    //=========================
    // TAMPIL BAHAN
    //=========================

    void tampilBahan(){

        cout<<"\n========== DATA STOK BAHAN ==========\n";

        cout<<"ID Bahan  : "
        <<idBahan<<endl;

        cout<<"Nama      : "
        <<namaBahan<<endl;

        cout<<"Stok      : "
        <<stok<<" "
        <<satuan<<endl;

        cout<<"Status    : "
        <<statusStok<<endl;

    }

    //=========================
    // EDIT BAHAN
    //=========================

    void editBahan(){

        cout<<"\n========== EDIT BAHAN ==========\n";

        cin.ignore();

        cout<<"Nama Bahan Baru : ";
        getline(cin,namaBahan);

        cout<<"Stok Baru : ";
        cin>>stok;

        cout<<"Satuan Baru : ";
        cin>>satuan;

        if(stok>0)

            statusStok="Tersedia";

        else

            statusStok="Habis";

        cout<<"\nData bahan berhasil diperbarui.\n";


    }

    //=========================
    // HAPUS BAHAN
    //=========================

    void hapusBahan(){

        idBahan=0;
        namaBahan="";
        stok=0;
        satuan="";
        statusStok="Dihapus";

        cout<<"\nData bahan berhasil dihapus.\n";

    }

    //=========================
    // CARI BAHAN
    //=========================

    void cariBahan(){

        string cari;

        cin.ignore();

        cout<<"Masukkan nama bahan : ";
        getline(cin,cari);


        if(cari==namaBahan){

            cout<<"\nBahan ditemukan.\n";

            tampilBahan();

        }

        else{

           cout<<"\nBahan tidak ditemukan.\n";

        }

    }
    //=========================
    // RESTOCK BAHAN
    //=========================

    void restockBahan(){
    	
        int tambah;

        cout<<"\n========== RESTOCK BAHAN ==========\n";

        cout<<"Nama Bahan : "
        <<namaBahan<<endl;

        cout<<"Tambah Stok : ";
        cin>>tambah;

        stok = stok + tambah;

        if(stok>0)

            statusStok="Tersedia";


        cout<<"\nRestock berhasil.\n";

        cout<<"Stok sekarang : "
        <<stok<<" "
        <<satuan<<endl;


    }

    //=========================
    // CEK STOK
    //=========================

    void cekStok(){

        cout<<"\n========== CEK STOK ==========\n";

        cout<<"Bahan : "
        <<namaBahan<<endl;

        cout<<"Jumlah : "
        <<stok<<" "
        <<satuan<<endl;

        if(stok<=5){

            cout<<"Peringatan : Stok hampir habis!\n";

        }

        else{

            cout<<"Stok aman.\n";

        }

    }

};


class Karyawan {
private:
    static const int MAX = 100;

    int idKaryawan[MAX];
    string nama[MAX];
    string alamat[MAX];
    string noHP[MAX];
    string jabatan[MAX];
    string shift[MAX];
    int gajiPokok[MAX];
    string jamMasuk[MAX];
    string jamPulang[MAX];
    string statusKerja[MAX];

    int jumlah;

public:

    Karyawan() {
        jumlah = 0;
    }

    void inputKaryawan() {

        if (jumlah >= MAX) {
            cout << "\nData karyawan penuh!\n";
            return;
        }

        cout << "\n====================================\n";
        cout << "\n========== INPUT KARYAWAN ==========\n";
        cout << "======================================\n";

        cout << "ID Karyawan : ";
        cin >> idKaryawan[jumlah];
        cin.ignore();

        cout << "Nama : ";
        getline(cin, nama[jumlah]);

        cout << "Alamat : ";
        getline(cin, alamat[jumlah]);

        cout << "No HP : ";
        getline(cin, noHP[jumlah]);

        cout << "Jabatan : ";
        getline(cin, jabatan[jumlah]);

        cout << "Shift : ";
        getline(cin, shift[jumlah]);

        cout << "Gaji Pokok : ";
        cin >> gajiPokok[jumlah];
        cin.ignore();

        jamMasuk[jumlah] = "-";
        jamPulang[jumlah] = "-";
        statusKerja[jumlah] = "Aktif";

        jumlah++;

        cout << "\nKaryawan berhasil ditambahkan.\n";
    }

    void tampilKaryawan() {

        cout << "\n===================================\n";
        cout << "\n========== DATA KARYAWAN ==========\n";
        cout << "=====================================\n";

        for (int i = 0; i < jumlah; i++) {
            cout << "\n--------------------------\n";
            cout << "ID        : " << idKaryawan[i] << endl;
            cout << "Nama      : " << nama[i] << endl;
            cout << "Alamat    : " << alamat[i] << endl;
            cout << "No HP     : " << noHP[i] << endl;
            cout << "Jabatan   : " << jabatan[i] << endl;
            cout << "Shift     : " << shift[i] << endl;
            cout << "Gaji      : " << gajiPokok[i] << endl;
            cout << "Status    : " << statusKerja[i] << endl;
        }
    }

    void cariKaryawan() {

        int id;
        cout << "\nMasukkan ID Karyawan: ";
        cin >> id;

        for (int i = 0; i < jumlah; i++) {
            if (idKaryawan[i] == id) {
                cout << "\n================================\n";
                cout << "\n=== KARYAWAN DITEMUKAN ===\n";
                cout << "Nama    : " << nama[i] << endl;
                cout << "Jabatan : " << jabatan[i] << endl;
                cout << "Shift   : " << shift[i] << endl;
                cout << "Gaji    : " << gajiPokok[i] << endl;
                cout << "================================\n";
                return;
            }
        }

        cout << "\nKaryawan tidak ditemukan.\n";
    }

    void editKaryawan() {
        int id;
        cout << "\nMasukkan ID Karyawan yang mau diedit: ";
        cin >> id;
        cin.ignore();

        for (int i = 0; i < jumlah; i++) {

            if (idKaryawan[i] == id) {

                cout << "\n=== EDIT DATA ===\n";

                cout << "Nama baru : ";
                getline(cin, nama[i]);

                cout << "Alamat baru : ";
                getline(cin, alamat[i]);

                cout << "No HP baru : ";
                getline(cin, noHP[i]);

                cout << "Jabatan baru : ";
                getline(cin, jabatan[i]);

                cout << "Shift baru : ";
                getline(cin, shift[i]);

                cout << "Gaji baru : ";
                cin >> gajiPokok[i];
                cin.ignore();

                cout << "\nData berhasil diupdate.\n";
                cout << "================================\n";
                return;
            }
        }

        cout << "\nKaryawan tidak ditemukan.\n";
    }

    void hapusKaryawan() {

        int id;
        cout << "\nMasukkan ID Karyawan yang mau dihapus: ";
        cin >> id;

        for (int i = 0; i < jumlah; i++) {

            if (idKaryawan[i] == id) {

                for (int j = i; j < jumlah - 1; j++) {

                    idKaryawan[j] = idKaryawan[j + 1];
                    nama[j] = nama[j + 1];
                    alamat[j] = alamat[j + 1];
                    noHP[j] = noHP[j + 1];
                    jabatan[j] = jabatan[j + 1];
                    shift[j] = shift[j + 1];
                    gajiPokok[j] = gajiPokok[j + 1];
                    jamMasuk[j] = jamMasuk[j + 1];
                    jamPulang[j] = jamPulang[j + 1];
                    statusKerja[j] = statusKerja[j + 1];
                }

                jumlah--;

                cout << "\nData karyawan berhasil dihapus.\n";
                return;
            }
        }

        cout << "\nKaryawan tidak ditemukan.\n";
    }

    void ubahShift() {

        int id;
        cout << "\nMasukkan ID Karyawan: ";
        cin >> id;
        cin.ignore();

        for (int i = 0; i < jumlah; i++) {

            if (idKaryawan[i] == id) {

                cout << "Shift baru (Pagi/Siang/Malam): ";
                getline(cin, shift[i]);

                cout << "\nShift berhasil diubah.\n";
                return;
            }
        }

        cout << "\nKaryawan tidak ditemukan.\n";
    }

    void rekapAbsensi() {
        cout << "\n===================================\n";
        cout << "\n========== REKAP ABSENSI ==========\n";
        cout << "=====================================\n";

        for (int i = 0; i < jumlah; i++) {

            cout << "\n-------------------\n";
            cout << "Nama   : " << nama[i] << endl;
            cout << "Shift  : " << shift[i] << endl;
            cout << "Masuk  : " << jamMasuk[i] << endl;
            cout << "Pulang : " << jamPulang[i] << endl;
            cout << "Status : " << statusKerja[i] << endl;
        }
    }
};

class Membership {
private:
    static const int MAX = 100;

    int idMember[MAX];
    string namaMember[MAX];
    string noHP[MAX];
    int poin[MAX];

    int jumlah;

public:

    Membership() {
        jumlah = 0;
    }

    void daftarMember() {

        if (jumlah >= MAX) {
            cout << "\nData member penuh!\n";
            return;
        }

        cout << "\n==========================================\n";
        cout << "\n========== DAFTAR MEMBER WARTEG ==========\n";
        cout << "============================================\n";

        cout << "ID Member : ";
        cin >> idMember[jumlah];
        cin.ignore();

        cout << "Nama      : ";
        getline(cin, namaMember[jumlah]);

        cout << "No HP     : ";
        getline(cin, noHP[jumlah]);

        poin[jumlah] = 0; // awal pendaftaran poin = 0

        jumlah++;

        cout << "\nMember berhasil didaftarkan!\n";
    }

    void tambahPoin() {

        int id, tambahan;

        cout << "\nMasukkan ID Member: ";
        cin >> id;

        for (int i = 0; i < jumlah; i++) {

            if (idMember[i] == id) {

                cout << "Jumlah poin belanja: ";
                cin >> tambahan;

                poin[i] += tambahan;

                cout << "\nPoin berhasil ditambahkan!\n";
                cout << "Total poin sekarang: " << poin[i] << endl;

                return;
            }
        }

        cout << "\nMember tidak ditemukan.\n";
    }

    void tampilMember() {

        cout << "\n========================================\n";
        cout << "\n========== DATA MEMBER WARTEG ==========\n";
        cout << "==========================================\n";

        for (int i = 0; i < jumlah; i++) {

            cout << "\n--------------------------\n";
            cout << "ID Member : " << idMember[i] << endl;
            cout << "Nama      : " << namaMember[i] << endl;
            cout << "No HP     : " << noHP[i] << endl;
            cout << "Poin      : " << poin[i] << endl;
            cout << "----------------------------\n";

            if (poin[i] >= 100) {
                cout << "*****************************************\n";
                cout << "* Status    : Member VIP (Diskon aktif) *\n";
                cout << "*****************************************\n";
            } else {
                cout << "-----------------------------------------\n";
                cout << "|       Status    : Member Reguler      |\n";
                cout << "-----------------------------------------\n";
            }
        }
    }
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

int main() {
    
    return 0;
}