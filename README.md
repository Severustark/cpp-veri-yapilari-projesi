# Veri Yapıları Uygulama Projesi

Bu proje, **Veri Yapıları** dersi kapsamında hazırlanmıştır ve temel veri yapılarının nesne yönelimli programlama (OOP) ilkeleriyle nasıl uygulanabileceğini göstermektedir. Projede **Yığın**, **Kuyruk**, **Tek Yönlü Bağlı Liste**, **İkili Ağaç** ve **Çırpılama (Hash Tablosu)** veri yapıları, kullanıcı etkileşimli bir menü sistemiyle birlikte sunulmuştur.📄 [Proje PDF Dokümanı](./veri-yapilari.pdf) bu linkten ayrıntılara ulaşabilirsiniz.


## 📌 Proje Özellikleri

- Tüm veri yapıları **C++ sınıfları (class)** kullanılarak yazılmıştır.
- **Struct** yapısı yerine tamamen **class** yapısı tercih edilmiştir.
- **Yığın** ve **Kuyruk** işlemleri, dinamik yapıdaki **bağlı liste** ile gerçekleştirilmiştir; bu nedenle eleman sayısında sınır yoktur.
- Kullanıcı dostu ve çok seviyeli bir **konsol menü arayüzü** ile veri yapıları arasında geçiş yapılabilir.
- Her satır, uygun şekilde **yorum satırları** ile açıklanmıştır.

## 🔧 Kullanılan Veri Yapıları

1. **Yığın (Stack)**
   - Bağlı liste ile implementasyon
   - Eleman ekleme (push), çıkarma (pop) ve görüntüleme (display)

2. **Kuyruk (Queue)**
   - Bağlı liste ile implementasyon
   - Eleman ekleme (enqueue), çıkarma (dequeue) ve görüntüleme

3. **Tek Yönlü Bağlı Liste (Singly Linked List)**
   - Baştan ve sondan ekleme/silme
   - Araya eleman ekleme/silme
   - Arama ve listeleme işlemleri

4. **İkili Ağaç (Binary Tree)**
   - Düğüm ekleme
   - Önce (preorder), ortada (inorder), sonra (postorder) dolaşım (traversal)
   - Eleman arama işlemleri

5. **Çırpılama (Hash Tablosu)**
   - Basit hash fonksiyonu
   - Çakışma çözümü (örneğin lineer probing veya chaining)
   - Ekleme, silme ve arama işlemleri

📦 Proje Dosya Yapısı
cpp-veri-yapilari-projesi/
├── README.md
├── main.cpp
├── Stack.hpp
├── Queue.hpp
├── LinkedList.hpp
├── BinaryTree.hpp
├── HashTable.hpp
└── ...

## 🚀 Nasıl Kullanılır?

1. C++ yüklü bir geliştirme ortamında (örneğin Visual Studio, Code::Blocks veya g++) projeyi derleyin.
2. Program çalıştırıldığında sizi aşağıdaki gibi bir **ana menü** karşılayacaktır:
3. Her alt menüde ilgili veri yapısına ait işlemler listelenir.
4. Menüden çıkmak için `6` tuşuna basmanız yeterlidir.


### 👤 Geliştirici

"DAMLA ARPA"
Bilgisayar Mühendisliği  Öğrencisi
Dumlupınar Üniversitesi 

---



