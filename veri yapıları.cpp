#include <iostream>
#include <memory>
#include <vector>
#include <list>

using namespace std; // cin,cout giibi ogeleri saklayan kütüphane

// Bağlı liste için düğüm sınıfı
class Dugum {
public:
    int veri;
    Dugum* sonraki;

    Dugum(int veri) : veri(veri), sonraki(nullptr) {}
};

// Bağlı liste kullanarak yığın (stack) sınıfı
class Yigin {
private:
    Dugum* tepe;

public:
    Yigin() : tepe(nullptr) {}

    ~Yigin() {
        temizle();
    }

    bool bosMu() {
        return tepe == nullptr;
    }

    void koymak(int veri) {
        Dugum* yeniDugum = new Dugum(veri);
        yeniDugum->sonraki = tepe;
        tepe = yeniDugum;
    }

    int cikartmak() {
        if (bosMu()) {
            std::cout << "Yigin bos" << std::endl;
            return -1;
        }
        int cikanVeri = tepe->veri;
        Dugum* temp = tepe;
        tepe = tepe->sonraki;
        delete temp;
        return cikanVeri;
    }

    int ustVeri() {
        if (bosMu()) {
            std::cout << "Yığın boş" << std::endl;
            return -1;
        }
        return tepe->veri;
    }

    int elemanSayisi() {
        int sayac = 0;
        Dugum* gecici = tepe;
        while (gecici != nullptr) {
            sayac++;
            gecici = gecici->sonraki;
        }
        return sayac;
    }

    void temizle() {
        while (tepe != nullptr) {
            Dugum* temp = tepe;
            tepe = tepe->sonraki;
            delete temp;
        }
    }

    void goster() {
        Dugum* gecici = tepe;
        while (gecici != nullptr) {
            std::cout << gecici->veri << " ";
            gecici = gecici->sonraki;
        }
        std::cout << std::endl;
    }
};

// Bağlı liste kullanarak kuyruk (queue) sınıfı
class Kuyruk {
private:
    Dugum* on;
    Dugum* arka;

public:
    Kuyruk() : on(nullptr), arka(nullptr) {}

    ~Kuyruk() {
        temizle();
    }

    bool bosMu() {
        return on == nullptr;
    }

    void ekle(int veri) {
        Dugum* yeniDugum = new Dugum(veri);
        if (arka != nullptr) {
            arka->sonraki = yeniDugum;
        }
        arka = yeniDugum;
        if (on == nullptr) {
            on = yeniDugum;
        }
    }

    int cikart() {
        if (bosMu()) {
            std::cout << "Kuyruk boş" << std::endl;
            return -1;
        }
        int cikanVeri = on->veri;
        Dugum* temp = on;
        on = on->sonraki;
        if (on == nullptr) {
            arka = nullptr;
        }
        delete temp;
        return cikanVeri;
    }

    int elemanSayisi() {
        int sayac = 0;
        Dugum* gecici = on;
        while (gecici != nullptr) {
            sayac++;
            gecici = gecici->sonraki;
        }
        return sayac;
    }

    void temizle() {
        while (on != nullptr) {
            Dugum* temp = on;
            on = on->sonraki;
            delete temp;
        }
        arka = nullptr;
    }

    void goster() {
        Dugum* gecici = on;
        while (gecici != nullptr) {
            std::cout << gecici->veri << " ";
            gecici = gecici->sonraki;
        }
        std::cout << std::endl;
    }
};

// Tek yönlü bağlı liste sınıfı
class TekYonluBagliListe {
private:
    Dugum* bas;

public:
    TekYonluBagliListe() : bas(nullptr) {}

    ~TekYonluBagliListe() {
        temizle();
    }

    void basaEkle(int veri) {
        Dugum* yeniDugum = new Dugum(veri);
        yeniDugum->sonraki = bas;
        bas = yeniDugum;
    }

    void sonaEkle(int veri) {
        Dugum* yeniDugum = new Dugum(veri);
        if (bas == nullptr) {
            bas = yeniDugum;
            return;
        }
        Dugum* son = bas;
        while (son->sonraki != nullptr) {
            son = son->sonraki;
        }
        son->sonraki = yeniDugum;
    }

    
    void arayaEkle(int veri, int konum) {
        if (konum < 0) {
            std::cout << "Gecersiz konum" << std::endl;
            return;
        }


        Dugum* yeniDugum = new Dugum(veri);
        if (konum == 0) {
            yeniDugum->sonraki = bas;
            bas = yeniDugum;
            return;
        }

        Dugum* gecici = bas;
        for (int i = 0; gecici != nullptr && i < konum - 1; i++) {
            gecici = gecici->sonraki;
        }
       
        if (gecici == nullptr) {
            std::cout << "Gecersiz konum" << std::endl;
            delete yeniDugum;
            return;
        }

        yeniDugum->sonraki = gecici->sonraki;
        gecici->sonraki = yeniDugum;
    }


    void dugumSil(int anahtar) {
        Dugum* temp = bas;
        Dugum* onceki = nullptr;

        if (temp != nullptr && temp->veri == anahtar) {
            bas = temp->sonraki;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->veri != anahtar) {
            onceki = temp;
            temp = temp->sonraki;
        }

        if (temp == nullptr) return;

        onceki->sonraki = temp->sonraki;
        delete temp;
    }

    int elemanSayisi() {
        int sayac = 0;
        Dugum* gecici = bas;
        while (gecici != nullptr) {
            sayac++;
            gecici = gecici->sonraki;
        }
        return sayac;
    }

    void temizle() {
        while (bas != nullptr) {
            Dugum* temp = bas;
            bas = bas->sonraki;
            delete temp;
        }
    }

    void goster() {
        Dugum* gecici = bas;
        while (gecici != nullptr) {
            std::cout << gecici->veri << " ";
            gecici = gecici->sonraki;
        }
        std::cout << std::endl;
    }
};

// İkili ağaç sınıfı
class AgacDugumu {
public:
    int veri;
    AgacDugumu* sol;
    AgacDugumu* sag;

    AgacDugumu(int anahtar) : veri(anahtar), sol(nullptr), sag(nullptr) {}

    ~AgacDugumu() {
        delete sol;
        delete sag;
    }

    void ekle(int anahtar) {
        if (anahtar < veri) {
            if (sol == nullptr) {
                sol = new AgacDugumu(anahtar);
            }
            else {
                sol->ekle(anahtar);
            }
        }
        else if (anahtar > veri) {
            if (sag == nullptr) {
                sag = new AgacDugumu(anahtar);
            }
            else {
                sag->ekle(anahtar);
            }
        }
    }

    void inorderDolas(std::vector<int>& sonuc) {
        if (sol != nullptr) {
            sol->inorderDolas(sonuc);
        }
        sonuc.push_back(veri);
        if (sag != nullptr) {
            sag->inorderDolas(sonuc);
        }
    }
};

// Zincirleme kullanarak hash tablosu sınıfı
class HashTablosu {
private:
    std::vector<std::list<std::pair<int, std::string>>> tablo;

    int hashFonksiyonu(int anahtar) {
        return anahtar % tablo.size();
    }

public:
    HashTablosu() : tablo(10) {}

    void ekle(int anahtar, const std::string& deger) {
        int hashAnahtari = hashFonksiyonu(anahtar);
        auto& hucre = tablo[hashAnahtari];
        auto it = hucre.begin();
        for (; it != hucre.end(); it++) {
            if (it->first == anahtar) {
                it->second = deger;
                return;
            }
        }
        hucre.emplace_back(anahtar, deger);
    }

    std::string al(int anahtar) {
        int hashAnahtari = hashFonksiyonu(anahtar);
        auto& hucre = tablo[hashAnahtari];
        for (auto& kv : hucre) {
            if (kv.first == anahtar) {
                return kv.second;
            }
        }
        return "Bulunamadı";
    }

    void sil(int anahtar) {
        int hashAnahtari = hashFonksiyonu(anahtar);
        auto& hucre = tablo[hashAnahtari];
        hucre.remove_if([anahtar](const std::pair<int, std::string>& kv) {
            return kv.first == anahtar;
            });
    }

    int elemanSayisi() {
        int sayac = 0;
        for (const auto& hucre : tablo) {
            sayac += hucre.size();
        }
        return sayac;
    }
};

// Menü Fonksiyonları
void yiginMenu() {
    Yigin yigin;
    while (true) {
        std::cout << "\nYigin icin islem seciniz: " << std::endl;
        std::cout << "1-Yigina eleman ekle" << std::endl;
        std::cout << "2-Yigindan eleman cikar" << std::endl;
        std::cout << "3-Ust Veriyi Gor" << std::endl;
        std::cout << "6-Yigindaki eleman sayisini goster" << std::endl;
        std::cout << "5-Yigini temizle" << std::endl;
        std::cout << "6-Yigindaki elemanlari goster" << std::endl;
        std::cout << "7-Ana Menuye Don" << std::endl;
        int secim;
        std::cin >> secim;
        if (secim == 1) {
            int veri;
            std::cout << "Veriyi girin: ";
            std::cin >> veri;
            yigin.koymak(veri);
        }
        else if (secim == 2) {
            std::cout << "Cikartilan veri: " << yigin.cikartmak() << std::endl;
        }
        else if (secim == 3) {
            std::cout << "Ust veri: " << yigin.ustVeri() << std::endl;
        }
        else if (secim == 4) {
            std::cout << "Eleman sayisi: " << yigin.elemanSayisi() << std::endl;
        }
        else if (secim == 5) {
            yigin.temizle();
            std::cout << "Yigin temizlendi" << std::endl;
        }
        else if (secim == 6) {
            std::cout << "Yigindaki elemanlar: ";
            yigin.goster();
        }
        else if (secim == 7) {
            break;
        }
    }
}

void kuyrukMenu() {
    Kuyruk kuyruk;
    while (true) {
        std::cout << "\nKuyruk icin islem seciniz: " << std::endl;
        std::cout << "1-Kuyruga eleman ekle" << std::endl;
        std::cout << "2-Kuyruga eleman cikar" << std::endl;
        std::cout << "3-Kuyruktaki eleman sayisini Gor" << std::endl;
        std::cout << "4-Kuyrugu temizle" << std::endl;
        std::cout << "5-Kuyruktaki elemanlari goster" << std::endl;
        std::cout << "6-Ana Menuye Don" << std::endl;
        int secim;
        std::cin >> secim;
        if (secim == 1) {
            int veri;
            std::cout << "Veriyi girin: ";
            std::cin >> veri;
            kuyruk.ekle(veri);
        }
        else if (secim == 2) {
            std::cout << "Cikartilan veri: " << kuyruk.cikart() << std::endl;
        }
        else if (secim == 3) {
            std::cout << "Eleman sayisi: " << kuyruk.elemanSayisi() << std::endl;
        }
        else if (secim == 4) {
            kuyruk.temizle();
            std::cout << "Kuyruk temizlendi" << std::endl;
        }
        else if (secim == 5) {
            std::cout << "Kuyruktaki elemanlar: ";
            kuyruk.goster();
        }
        else if (secim == 6) {
            break;
        }
    }
}

void tekYonluBagliListeMenu() {
    TekYonluBagliListe liste;
    while (true) {
        std::cout << "\nTek Yonlu Bagli Liste Menusu:" << std::endl;
        std::cout << "1. Basa Ekle" << std::endl;
        std::cout << "2. Sona Ekle" << std::endl;
        std::cout << "3. Araya Ekle" << std::endl;
        std::cout << "4. Dugum Sil" << std::endl;
        std::cout << "5. Eleman Sayisini Gor" << std::endl;
        std::cout << "6. Bagli Listeyi Temizle" << std::endl;
        std::cout << "7. Bagli Listedeki Elemanlari Goster" << std::endl;
        std::cout << "8. Ana Menuye Don" << std::endl;
        int secim;
        std::cin >> secim;
        if (secim == 1) {
            int veri;
            std::cout << "Veriyi girin: ";
            std::cin >> veri;
            liste.basaEkle(veri);
        }
        else if (secim == 2) {
            int veri;
            std::cout << "Veriyi girin: ";
            std::cin >> veri;
            liste.sonaEkle(veri);
        }
        else if (secim == 3) {
            int veri, konum;
            std::cout << "Veriyi girin: ";
            std::cin >> veri;
            std::cout << "Konumu girin: ";
            std::cin >> konum;
            liste.arayaEkle(veri, konum);
        }
        else if (secim == 4) {
            int anahtar;
            std::cout << "Silinecek anahtari girin: ";
            std::cin >> anahtar;
            liste.dugumSil(anahtar);
        }
        else if (secim == 5) {
            std::cout << "Eleman sayisi: " << liste.elemanSayisi() << std::endl;
        }
        else if (secim == 6) {
            liste.temizle();
            std::cout << "Bagli liste temizlendi" << std::endl;
        }
        else if (secim == 7) {
            std::cout << "Bagli listedeki elemanlar: ";
            liste.goster();
        }
        else if (secim == 8) {
            break;
        }
    }
}


void agacMenu() {
    AgacDugumu* kok = nullptr;
    while (true) {
        std::cout << "\nAgac Menusu:" << std::endl;
        std::cout << "1. Ekle" << std::endl;
        std::cout << "2. Inorder Dolas" << std::endl;
        std::cout << "3. Ana Menuye Don" << std::endl;
        int secim;
        std::cin >> secim;
        if (secim == 1) {
            int veri;
            std::cout << "Veriyi girin: ";
            std::cin >> veri;
            if (kok == nullptr) {
                kok = new AgacDugumu(veri);
            }
            else {
                kok->ekle(veri);
            }
        }
        else if (secim == 2) {
            if (kok == nullptr) {
                std::cout << "Agac bos" << std::endl;
            }
            else {
                std::vector<int> sonuc;
                kok->inorderDolas(sonuc);
                std::cout << "Inorder Dolasim: ";
                for (int v : sonuc) {
                    std::cout << v << " ";
                }
                std::cout << std::endl;
            }
        }
        else if (secim == 3) {
            break;
        }
    }
}

void hashTablosuMenu() {
    HashTablosu hashTablosu;
    while (true) {
        std::cout << "\nHash Tablosu icin islem seciniz:" << std::endl;
        std::cout << "1-Tabloya Eleman Ekle" << std::endl;
        std::cout << "2. Al" << std::endl;
        std::cout << "3-Tabloya Eleman Sil" << std::endl;
        std::cout << "4-Tablodaki Eleman Sayisini Gor" << std::endl;
        std::cout << "5. Ana Menuye Don" << std::endl;
        int secim;
        std::cin >> secim;
        if (secim == 1) {
            int anahtar;
            std::string deger;
            std::cout << "Anahtari girin: ";
            std::cin >> anahtar;
            std::cout << "Degeri girin: ";
            std::cin >> deger;
            hashTablosu.ekle(anahtar, deger);
        }
        else if (secim == 2) {
            int anahtar;
            std::cout << "Anahtari girin: ";
            std::cin >> anahtar;
            std::cout << "Deger: " << hashTablosu.al(anahtar) << std::endl;
        }
        else if (secim == 3) {
            int anahtar;
            std::cout << "Silinecek anahtari girin: ";
            std::cin >> anahtar;
            hashTablosu.sil(anahtar);
        }
        else if (secim == 4) {
            std::cout << "Eleman sayisi: " << hashTablosu.elemanSayisi() << std::endl;
        }
        else if (secim == 5) {
            break;
        }
    }
}

int main() {
    while (true) {
        cout << "\nYapmak istediginiz uygulamayi seciniz: " << endl;
        cout << "1- Yigin Uygulamasi" << endl;
        cout << "2- Kuyruk Uygulamasi" << endl;
        cout << "3- Tek Yonlu Bagli Liste Uygulamasi" << endl;
        cout << "4- Ikili Agac Uygulamasi" << endl;
        cout << "5- Hash Tablo Uygulamasi" << endl;
        cout << "6- Programdan Cikis" << endl;
        int secim;
        std::cin >> secim;
        if (secim == 1) {
            yiginMenu();
        }
        else if (secim == 2) {
            kuyrukMenu();
        }
        else if (secim == 3) {
            tekYonluBagliListeMenu();
        }
        else if (secim == 4) {
            agacMenu();
        }
        else if (secim == 5) {
            hashTablosuMenu();
        }
        else if (secim == 6) {
            break;
        }
    }
    return 0;
}
