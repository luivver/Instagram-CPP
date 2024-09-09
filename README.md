## Instagram-CPP
Instagram-CPP adalah proyek kelompok yang dibuat untuk memenuhi tugas akhir mata kuliah Struktur Data. 
Proyek ini ditulis dalam bahasa C++ dan mensimulasikan fungsi-fungsi dasar yang terdapat dalam aplikasi Instagram, seperti pengelolaan akun orang tua dan anak, serta interaksi di antara keduanya.
Anggota kelompok terdiri dari saya, Alphiaverta Kristiara, dan teman saya, Bintan Dinar Artamevia.

## Fitur
Proyek ini mencakup berbagai fungsi, antara lain:
- **Deklarasi List**:
  - void createListParent(listParent &LP); (Dinar)
  - void createListChild(listChild &LC); (Verta)
- **Pembuatan Akun**:
  - adrP newParent(string name, bool verified); (Dinar)
  - adrC newChild(string name, bool verified); (Verta)
- **Pengelolaan Akun**:
  - void insertParent(listParent &LP, adrP newP); (Dinar)
  - void insertChild(listChild &LC, adrC newC); (Verta)
  - void findParent(listParent LP, string name, adrP &foundP); (Dinar)
  - void findChild(listChild LC, string name, adrC &foundC); (Verta)
  - void deleteParent(listParent &LP, string name, adrP &deletedP); (Dinar)
  - void deleteChild(listChild &LC, string name, adrC &deletedC); (Verta)
- **Interaksi Akun**:
  - int sumFollowers(listParent LP, listChild LC, string name); (Dinar)
  - void showAccountAndFollowers(listParent LP, listChild LC); (Verta)
  - void showAllAccount(listParent LP); (Dinar)
  - void follow(listParent LP, listChild &LC, string acc); (Dinar)
  - void unfollow(listParent LP, listChild &LC, string accUnfollow, string accUser); (Dinar)
  - void deleteAccount(listParent &LP, adrP &deletedAccount, string acc); (Verta)
  - void showFollowing(listParent LP, string acc); (Verta)
  - int sumFollowing(listParent LP, string acc); (Dinar)
- **Menu dan Login**:
  - int menu(); (Dinar)
  - int menuLogin(string acc); (Verta)
  - int main(); (Dinar & Verta)
 
## Cara Menggunakan
1. Clone repository ini ke komputer Anda.
2. Buka proyek di IDE C++ favorit Anda.
3. Kompilasi dan jalankan program untuk mulai menggunakan fitur-fitur yang ada.
