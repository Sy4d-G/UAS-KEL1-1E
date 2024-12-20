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
        cout << "Total Harga: Rp " << total_harga << endl;
    } else if (pilihan_layanan == 2) {
        // Layanan Laundry Offline (Self-Service)
        string punya_koin;
        cout << "\nApakah Anda sudah punya koin untuk menjalankan mesin laundry? (y/n): ";
        cin >> punya_koin;

        if (punya_koin == "y" || punya_koin == "Y") {
            cout << "Untuk menggunakan mesin ini, silahkan scan QR code di mesin tersebut.\n";
            cout << "Nama: " << nama_pengguna << ", silahkan input koin ke dalam mesin cuci.\n";

            int jumlah_koin;
            cout << "Masukkan jumlah koin yang ingin digunakan: ";
            cin >> jumlah_koin;

            animasi_loading("Sedang menghitung koin");

            cout << "Penggunaan mesin cuci: " << jumlah_koin << " kali.\n";

            // Menambahkan fitur setrika + lipat
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
        } else if (punya_koin == "n" || punya_koin == "N") {
            int jumlah_uang, jumlah_koin, sisa_uang;

            // Input uang untuk membeli koin
            do {
                cout << "Masukkan jumlah uang Anda (minimal Rp 4000): ";
                cin >> jumlah_uang;

                if (jumlah_uang < harga_koin) {
                    cout << "Jumlah uang tidak cukup untuk membeli koin. Silakan masukkan minimal Rp 4000.\n";
                }
            } while (jumlah_uang < harga_koin);

            // Menghitung jumlah koin dan kembalian
            jumlah_koin = jumlah_uang / harga_koin;
            sisa_uang = jumlah_uang % harga_koin;

            cout << "Anda mendapatkan " << jumlah_koin << " koin.\n";
            if (sisa_uang > 0) {
                cout << "Uang kembalian Anda: Rp " << sisa_uang << ", silahkan diambil kembali.\n";
            }

            char konfirmasi_kembalian;
            do {
                cout << "Apakah uang kembalian telah diambil? (y/n): ";
                cin >> konfirmasi_kembalian;
                if (konfirmasi_kembalian == 'n' || konfirmasi_kembalian == 'N') {
                    cout << "Silakan ambil uang kembalian Anda terlebih dahulu.\n";
                }
            } while (konfirmasi_kembalian != 'y' && konfirmasi_kembalian != 'Y');

            cout << "Untuk menggunakan mesin ini, silahkan scan QR code di mesin tersebut.\n";
            cout << "Nama: " << nama_pengguna << ", silahkan input koin ke dalam mesin cuci.\n";

            int jumlah_koin_input;
            cout << "Masukkan jumlah koin yang ingin digunakan: ";
            cin >> jumlah_koin_input;

            animasi_loading("Sedang menghitung koin");

            cout << "Penggunaan mesin cuci: " << jumlah_koin_input << " kali.\n";

            // Menambahkan fitur setrika + lipat
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
        } else {
            cout << "Pilihan tidak valid. Harap masukkan 'y' untuk Ya atau 'n' untuk Tidak.\n";
        }
    } else {
        cout << "Pilihan tidak valid!\n";
    }

    return 0;
}
