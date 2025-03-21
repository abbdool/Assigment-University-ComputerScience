Deskripsi Soal: BST untuk Manajemen Koleksi Game
Mr. X, seorang penggemar game, memiliki banyak koleksi game yang sulit untuk dilacak. Untuk memudahkan pencarian, ia memutuskan untuk menggunakan Binary Search Tree (BST) sebagai sistem penyimpanan. BST ini memiliki beberapa properti khusus:

Setiap node dalam BST menyimpan nama game dan rating game (1 – 10).

BST akan mengurutkan data berdasarkan nama game (string) secara alfabetis dalam urutan menurun (DESCENDING ORDER) dan tidak memperhatikan huruf besar/kecil (case insensitive).

Operasi yang dapat dilakukan pada BST ini adalah:

Insert:

Program akan meminta nama game dan rating game.

Jika nama game sudah ada dalam BST, rating game akan diperbarui.

Validasi: nama game harus memiliki panjang minimal 1 dan maksimal 100 karakter, serta rating game harus berada dalam rentang 1 hingga 10.

Delete:

Program akan meminta nama game yang akan dihapus.

Validasi: nama game harus memiliki panjang minimal 1 dan maksimal 100 karakter.

Jika nama game tidak ditemukan, program akan menampilkan pesan "Game name does not exist!".

Jika nama game ditemukan, node tersebut akan dihapus menggunakan metode penghapusan BST.
