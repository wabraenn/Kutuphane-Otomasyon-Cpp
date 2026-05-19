#include "AnaMenu.h"
#include "UyeMenu.h"

#include "KullaniciService.h"
#include "KitapService.h"
#include "Dosya.h"

#include <iostream>

using namespace std;

//----admin menusu fonksiyonu----//
void adminMenu(vector<Kullanici>& kullanicilar, vector<Kitap>& kitaplar) {
	int secim;
	while (true) {
		cout << "\n\n===Admin Menüsüne Hoş Geldiniz===\n\n";
		cout << "1-Kullanıcıları Görüntüle\n";
		cout << "2-Kullanıcı Sil\n";
		cout << "3-Kitapları Görüntüle\n";
		cout << "4-Kitap Ekle\n";
		cout << "5-Kitap Sil\n";
		cout << "6-Kitap Stok Güncelle\n";
		cout << "7-Çıkış\n";
		cout << "Seçiminiz: ";
		cin >> secim;
		cout << "\n";

		if (secim < 1 || secim > 7)
		{
			cout << "HATALI SEÇİM YAPTINIZ. LÜTFEN TEKRAR DENEYİN." << endl;
			continue; //hatalı seçim yapıldığında döngünün başına dön
		}
		if (secim == 7) {
			cout << "ÇIKIŞ YAPILIYOR...\n" << endl;
			break;
		}

		switch (secim) {
		case 1:
			// Kullanıcıları görüntüleme kodu
			kullaniciListele(kullanicilar);
			break;
		case 2:
		{
			// Kullanıcı silme kodu
			kullaniciSil(kullanicilar, kitaplar);
			break;
		}
		case 3:
			// Kitapları görüntüleme kodu
			kitapListele(kitaplar);
			break;
		case 4:
			// Kitap ekleme kodu
			kitapEkle(kitaplar);
			kitapDosyayiYenidenYaz(kitaplar); // eklenen kitabın dosyaya kaydedilmesi
			break;
		case 5:
			// Kitap silme kodu
			kitapListele(kitaplar);
			kitapSil(kitaplar);
			kitapDosyayiYenidenYaz(kitaplar); // silinen kitabın dosyaya kaydedilmesi
			break;
		case 6:
			// Kitap stok güncelleme kodu
			kitapListele(kitaplar);
			kitapStokGuncelle(kitaplar);
			break;
		default:
			cout << "Hatalı seçim! Lütfen tekrar deneyin.\n";
			break;
		}

	}
}
