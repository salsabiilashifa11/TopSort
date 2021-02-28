# TopSort
Program ini dibuat untuk memenuhi tugas ***IF2211 Strategi Algoritma***.

## Algoritma Decrease and Conquer
Tujuan dari program ini adalah untuk menyusun rencana pengambilan mata kuliah. Banyak mata kuliah yang memiliki prarsyarat sebelum dapat diambil. Hubungan keterkaitan prasyaray antar mata kuliah ini dapat direpresentasikan dalam bentuk Directed Acyclic Graph (DAG). Pada program sederhana ini, diberikan tambahan fitur yaitu untuk memperhitungkan juga SKS suatu mata kuliah dan dapat menerima masukan jumlah SKS maksimum yang bisa diambil oleh seorang mahasiswa. 

Untuk menyelesaikan permasalahan ini, digunakan pendekatan topological sort. Permasalahan dapat digambarkan dalam bentuk graf, dengan node merepresentasikan nama/kode mata kuliah yang harus diambil, dan directed edge merepresentasikan hubungan prerequisite dari satu mata kuliah ke mata kuliah yang lain. Suatu mata kuliah dikatakan bisa diambil pada satu semester (iterasi) tertentu, apabila derajat-masuknya sama dengan nol. Ketika suatu mata kuliah bisa diambil pada semester tertentu, maka mata kuliah tersebut akan dihapuskan dari graf dan derajat-masuk mata kuliah lain yang terhubung padanya akan dikurangi satu. 

Pada setiap iterasi, bisa saja terdapat lebih dari satu mata kuliah yang tidak memiliki prerequisite, sehingga bisa lebih dari satu mata kuliah yang dihapus. Dalam kondisi tersebut, maka penghapusan seluruh edge akan dilakukan secara bersamaan di akhir iterasi, untuk menghindari terjadinya pengurangan edge sebelum pengecekan pada semua node dalam satu iterasi berakhir.   

Penerapan algoritma topological sort pada penyelesaian masalah pengurutan mata kuliah ini merupakan implementasi algoritma decrease and conquer dengan varian decrease by a variable size. Ini berarti pada setiap iterasinya, upapersoalan direduksi dengan ukuran yang bisa bervariasi. Hal ini disebabkan oleh adanya ketentuan bahwa dalam satu semester (satu iterasi), jumlah mata kuliah yang diambil boleh lebih dari satu, asalkan mata kuliah yang bersangkutan tidak lagi memiliki prerequisite yang belum diambil. Dengan pengertian tersebut, jumlah mata kuliah yang dapat diambil pada setiap semesternya dapat bervariasi, yang artinya node dalam graf pada setiap iterasinya juga dapat berkurang dengan jumlah yang bervariasi.

## Requirements
- MinGW32 or g++ 12.0.0

## Eksekusi Program
### Menggunakan exe yang sudah tersedia
1. Naviagasi ke folder bin
2. Jalankan exe
3. Ikuti perintah yang ada pada program

### Kompilasi ulang
1. Dengan CLI, navigasi ke folder src
2. Masukkan command: `g++ -o main 13519106-main.cpp 13519106-graph.cpp 13519106-jadwal.cpp`
3. Jalankan hasil exe dengan: `./main`
4. Ikuti perintah yang ada pada program
> ***NOTE:***  Jika ingin menjalankan dengan perhitungan SKS, pastikan masukan SKS per semester maksimum tidak kurang dari SKS terbesar suatu mata pelajaran pada file teks terkait. 

## Author
Shifa Salsabiila (13519106)

