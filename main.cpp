#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono> // Library untuk mengukur waktu

using namespace std;

struct Buku {
    string id;
    string judul;
    string kategori;
    string penulis;
    string tahunTerbit;
};

// Fungsi untuk membaca file CSV
vector<Buku> bacaDataset(const string& namaFile) {
    vector<Buku> data;
    ifstream file(namaFile);
    string line;

    if (file.is_open()) {
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            Buku buku;
            getline(ss, buku.id, ',');
            getline(ss, buku.judul, ',');
            getline(ss, buku.kategori, ',');
            getline(ss, buku.penulis, ',');
            getline(ss, buku.tahunTerbit, ',');
            data.push_back(buku);
        }
        file.close();
    }
    return data;
}

// Fungsi Pencarian Iteratif
vector<Buku> cariIteratif(const vector<Buku>& data, const string& keyword, const string& kategori) {
    vector<Buku> hasil;
    for (const auto& buku : data) {
        string nilai;
        if (kategori == "Judul") nilai = buku.judul;
        else if (kategori == "Kategori") nilai = buku.kategori;
        else if (kategori == "Penulis") nilai = buku.penulis;
        else if (kategori == "Tahun Terbit") nilai = buku.tahunTerbit;

        if (nilai.find(keyword) != string::npos) {
            hasil.push_back(buku);
        }
    }
    return hasil;
}

// Fungsi Pencarian Rekursif
void cariRekursif(const vector<Buku>& data, const string& keyword, const string& kategori, size_t index, vector<Buku>& hasil) {
    if (index >= data.size()) return;

    string nilai;
    if (kategori == "Judul") nilai = data[index].judul;
    else if (kategori == "Kategori") nilai = data[index].kategori;
    else if (kategori == "Penulis") nilai = data[index].penulis;
    else if (kategori == "Tahun Terbit") nilai = data[index].tahunTerbit;

    if (nilai.find(keyword) != string::npos) {
        hasil.push_back(data[index]);
    }

    cariRekursif(data, keyword, kategori, index + 1, hasil);
}

// Fungsi Utama
int main() {
    string fileName = "buku.csv";
    vector<Buku> data = bacaDataset(fileName);

    string keyword, kategori, metode;
    cout << "Masukkan kata kunci: ";
    getline(cin, keyword);
    cout << "Masukkan kategori (Judul, Kategori, Penulis, Tahun Terbit): ";
    getline(cin, kategori);
    cout << "Masukkan metode (Iteratif/Rekursif): ";
    getline(cin, metode);

    vector<Buku> hasil;

    // Catat waktu mulai
    auto start_time = chrono::high_resolution_clock::now();

    if (metode == "Iteratif") {
        hasil = cariIteratif(data, keyword, kategori);
    } else if (metode == "Rekursif") {
        cariRekursif(data, keyword, kategori, 0, hasil);
    }

    // Catat waktu selesai
    auto end_time = chrono::high_resolution_clock::now();

    // Hitung durasi eksekusi
    chrono::duration<double> duration = end_time - start_time;
    cout << "Waktu eksekusi: " << duration.count() << " detik\n";

    cout << "Hasil Pencarian:\n";
    for (const auto& buku : hasil) {
        cout << "Judul: " << buku.judul << ", Kategori: " << buku.kategori
             << ", Penulis: " << buku.penulis << ", Tahun Terbit: " << buku.tahunTerbit << '\n';
    }

    return 0;
}
