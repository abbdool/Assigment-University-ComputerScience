TAP (Type and Play) - Film Playlist Management Terminal Application
TAP adalah aplikasi terminal sederhana untuk mengelola playlist film. Aplikasi ini memungkinkan pengguna untuk menyimpan film ke dalam dua playlist: Main Playlist dan Watch Later Playlist. Film dapat diputar dari Main Playlist, dan pengguna juga dapat menggabungkan kedua playlist dengan aturan prioritas tertentu.

Fitur Aplikasi
Insert Film ke Playlist:

insert_main: Menambahkan film ke Main Playlist.

insert_watch_later: Menambahkan film ke Watch Later Playlist.

Format input: movie_title movie_genre movie_duration.

Film diurutkan berdasarkan judul secara ascending (tidak case-sensitive).

Memutar Film:

play: Memutar film pertama dari Main Playlist dan menghapusnya dari playlist.

Output: WATCHED: movie_title movie_genre movie_duration.

Menggabungkan Playlist:

merge: Menggabungkan semua film dari Watch Later Playlist ke Main Playlist dengan urutan yang sesuai.

Jika Watch Later Playlist kosong, output: Watch later playlist is empty!.

Menampilkan Playlist:

display_main: Menampilkan semua film di Main Playlist.

display_watch_later: Menampilkan semua film di Watch Later Playlist.

Menghentikan Aplikasi:

stop: Menghentikan eksekusi aplikasi.

Struktur Data
Setiap film disimpan dalam struktur data dengan atribut:

title: Judul film.

genre: Genre film.

duration: Durasi film dalam menit.

Playlist diimplementasikan menggunakan Priority Queue dengan urutan berdasarkan judul film.
