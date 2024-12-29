import matplotlib.pyplot as plt

# Data yang diberikan
input_size = [10, 100, 1000, 10000]
iterative_time = [0.0000118, 0.0000190, 0.0001141, 0.0009043]
recursive_time = [0.0000116, 0.0000407, 0.0002466, 0.0021464]

# Membuat grafik
plt.figure(figsize=(10, 6))
plt.plot(input_size, iterative_time, marker='o', label='Iteratif', linewidth=2)
plt.plot(input_size, recursive_time, marker='o', label='Rekursif', linewidth=2)

# Menambahkan label dan judul
plt.title('Perbandingan Waktu Eksekusi Iteratif vs Rekursif', fontsize=14)
plt.xlabel('Ukuran Input', fontsize=12)
plt.ylabel('Waktu Eksekusi (detik)', fontsize=12)
plt.xscale('log')  # Menggunakan skala logaritmik pada sumbu X
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend(fontsize=12)
plt.tight_layout()

# Menampilkan grafik
plt.show()
