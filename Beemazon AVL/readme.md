Beemazon — AVL Tree Console App
Beemazon adalah prototipe aplikasi e-commerce berbasis struktur data AVL Tree yang ditulis dalam bahasa C. Proyek ini berjalan sepenuhnya di console dan tidak memiliki antarmuka grafis.

🔧 Fitur Utama
Menyimpan data produk dalam AVL Tree (balanced binary search tree).

Menggunakan harga sebagai key unik dan nama produk sebagai value.

Mendukung 4 jenis perintah:

Insert — Menambahkan produk baru.

Delete — Menghapus produk berdasarkan harga.

Find Similar — Menemukan produk dengan harga terdekat.

Show Data — Menampilkan daftar produk dalam rentang peringkat tertentu.

📥 Format Perintah
1. Insert
Format: 1 <harga> <nama_produk>
Contoh: 1 3500 noodle
Menambahkan produk ke AVL Tree. Tidak menghasilkan output.

2. Delete
Format: 2 <harga>
Contoh: 2 150350
Menghapus produk dengan harga tersebut jika ada. Tidak menghasilkan output.

3. Find Similar
Format: 3 <harga>
Contoh: 3 12000
Menampilkan produk dengan harga terdekat.

4. Show Data
Format: 4 <rank_awal> <rank_akhir>
Contoh: 4 1 10
Menampilkan daftar produk dari urutan ke-1 sampai ke-10 (berdasarkan in-order traversal AVL Tree
