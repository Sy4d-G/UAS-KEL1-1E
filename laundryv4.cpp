#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Fungsi untuk membuat ID Membership secara acak
string buat_id_membership() {
    string id = "ID-";
    for (int i = 0; i < 6; i++) {
        id += to_string(rand() % 10); // Menambahkan angka acak
    }
    return id;
}

// Fungsi untuk menampilkan animasi loading
void animasi_loading(const string &pesan) {
    cout << pesan;
    for (int i = 0; i < 5; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(500)); // Delay 500ms
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Inisialisasi random seed

    string nama_pengguna, kata_sandi, id_membership;
    string masukan_nama, masukan_sandi;
    int pilihan_layanan, pilihan_lokasi, mode_layanan, berat, biaya_per_kg = 0, biaya_tambahan = 0;
    const int harga_koin = 4000; // Harga per koin
    const int biaya_setrika_lipat_per_kg = 4500; // Biaya setrika + lipat offline per kg

    cout << "=== Selamat Datang di Laundry Karawang Sejahtera ===" << endl;

    // Registrasi
    cout << "\nPendaftaran Akun\n";
    cout << "Masukkan nama pengguna: ";
    cin >> nama_pengguna;
    cout << "Masukkan kata sandi: ";
    cin >> kata_sandi;
    id_membership = buat_id_membership();
    cout << "Pendaftaran berhasil! ID Membership Anda: " << id_membership << endl;

    // Login
    cout << "\nSilakan Login\n";
    while (true) {
        cout << "Nama Pengguna: ";
        cin >> masukan_nama;
        cout << "Kata Sandi: ";
        cin >> masukan_sandi;

        if (masukan_nama == nama_pengguna && masukan_sandi == kata_sandi) {
            cout << "Login berhasil! Selamat datang, " << nama_pengguna << ".\n";
            break;
        } else {
            cout << "Nama pengguna atau kata sandi salah. Silakan coba lagi.\n";
        }
    }

    // Pilihan layanan
    cout << "\nPilih layanan laundry:\n"
         << "1. Layanan Laundry Online\n"
         << "2. Layanan Laundry Offline (Self-Service)\n"
         << "Pilihan Anda (1-2): ";
    cin >> pilihan_layanan;

    if (pilihan_layanan == 1) {
        // Layanan Laundry Online
        cout << "\nPilih jenis layanan laundry online:\n"
             << "1. Cuci Saja (Rp 5.000/Kg)\n"
             << "2. Cuci + Setrika (Rp 10.000/Kg)\n"
             << "3. Setrika + Lipat (Rp 6.000/Kg)\n"
             << "Pilihan Anda (1-3): ";
        cin >> pilihan_layanan;

        switch (pilihan_layanan) {
            case 1: biaya_per_kg = 5000; break;
            case 2: biaya_per_kg = 10000; break;
            case 3: biaya_per_kg = 6000; break;
            default:
                cout << "Pilihan tidak valid!\n";
                return 1;
        }

        cout << "\nPilih lokasi Anda:\n";
        cout << "1. Karawang Barat\n"
             << "2. Karawang Timur\n"
             << "3. Cikampek\n"
             << "4. Telukjambe\n"
             << "5. Cilamaya Kulon\n"
             << "6. Cilamaya Wetan\n"
             << "7. Klari\n"
             << "8. Batujaya\n"
             << "9. Tempuran\n"
             << "10. Rengasdengklok\n"
             << "11. Tirtajaya\n"
             << "12. Jatisari\n"
             << "13. Pakisjaya\n"
             << "14. Banyusari\n"
             << "15. Purwasari\n"
             << "16. Pedes\n"
             << "17. Rawamerta\n"
             << "18. Jayakerta\n"
             << "19. Kutawaluya\n"
             << "20. Lemahabang\n"
             << "21. Cibuaya\n"
             << "22. Pangkalan\n"
             << "23. Tegalwaru\n"
             << "24. Majalaya\n";
        cout << "Pilihan Anda (1-24): ";
        cin >> pilihan_lokasi;

        if (pilihan_lokasi < 1 || pilihan_lokasi > 24) {
            cout << "Pilihan tidak valid!\n";
            return 1;
        }

        animasi_loading("\nDriver sedang menuju tempat Anda");

        cout << "\nDriver telah tiba! Masukkan berat laundry Anda (kg): ";
        cin >> berat;

        cout << "\nPilih mode layanan:\n"
             << "1. Kilat (6 jam, Tambahan Rp 10.000)\n"
             << "2. Express (1 hari, Tambahan Rp 6.000)\n"
             << "3. Reguler (2,5 hari, Tanpa tambahan biaya)\n"
             << "Pilihan Anda (1-3): ";
        cin >> mode_layanan;

        switch (mode_layanan) {
            case 1: biaya_tambahan = 10000; break;
            case 2: biaya_tambahan = 6000; break;
            case 3: biaya_tambahan = 0; break;
            default:
                cout << "Pilihan tidak valid!\n";
                return 1;
        }

        int total_harga = (biaya_per_kg * berat) + biaya_tambahan;
        string estimasi_waktu = (mode_layanan == 1) ? "6 jam" :
                                (mode_layanan == 2) ? "1 hari" : "2,5 hari";

        cout << "\n=== Ringkasan Pesanan ===\n";
        cout << "ID Membership: " << id_membership << endl;
        cout << "Berat Laundry: " << berat << " kg\n";
        cout << "Jenis Layanan: "
             << ((pilihan_layanan == 1) ? "Cuci Saja" :
                 (pilihan_layanan == 2) ? "Cuci + Setrika" : "Setrika + Lipat") << endl;
        cout << "Mode Layanan: "
             << ((mode_layanan == 1) ? "Kilat" :
                 (mode_layanan == 2) ? "Express" : "Reguler") << endl;
        cout << "Estimasi Waktu Selesai: " << estimasi_waktu << endl;
        cout << "Total Harga: Rp " << total_harga << endl;

        cout << "\nTerima kasih telah menggunakan layanan kami!\n";

    } else if (pilihan_layanan == 2) {
        // Layanan Laundry Offline (Self-Service)
        int jumlah_uang, jumlah_koin, sisa_uang;
        cout << "\n=== Layanan Laundry Offline (Self-Service) ===\n";
        cout << "Masukkan jumlah uang Anda (dalam Rupiah): ";
        cin >> jumlah_uang;

        jumlah_koin = jumlah_uang / harga_koin;
        sisa_uang = jumlah_uang % harga_koin;

        cout << "Anda mendapatkan " << jumlah_koin << " koin.\n";
        cout << "Uang kembalian Anda: Rp " << sisa_uang << ", silahkan diambil kembali.\n";

        // Konfirmasi pengambilan uang kembalian
        char konfirmasi_kembalian;
        do {
            cout << "Apakah uang kembalian telah diambil? (y/n): ";
            cin >> konfirmasi_kembalian;
            if (konfirmasi_kembalian == 'n' || konfirmasi_kembalian == 'N') {
                cout << "Silakan ambil uang kembalian Anda terlebih dahulu.\n";
            }
        } while (konfirmasi_kembalian != 'y' && konfirmasi_kembalian != 'Y');

        // Opsi setrika + lipat
        char setrika_pilihan;
        cout << "Apakah Anda ingin pakaian Anda disetrika + dilipat? (y/n): ";
        cin >> setrika_pilihan;

        if (setrika_pilihan == 'y' || setrika_pilihan == 'Y') {
            int berat_setrika;
            cout << "Masukkan berat pakaian untuk disetrika + dilipat (kg): ";
            cin >> berat_setrika;

            int total_biaya_setrika = berat_setrika * biaya_setrika_lipat_per_kg;
            cout << "Biaya tambahan untuk setrika + lipat: Rp " << total_biaya_setrika << endl;
        }

        cout << "Terima kasih telah menggunakan layanan kami!\n";
    } else {
        cout << "Pilihan tidak valid!\n";
    }

    return 0;
}
