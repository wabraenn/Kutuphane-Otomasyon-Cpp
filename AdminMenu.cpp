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
		cout << "\n\n===Admin Menüsüne Hoþ Geldiniz===\n\n";
		cout << "1-Kullanýcýlarý Görüntüle\n";
		cout << "2-Kullanýcý Sil\n";
		cout << "3-Kitaplarý Görüntüle\n";
		cout << "4-Kitap Ekle\n";
		cout << "5-Kitap Sil\n";
		cout << "6-Kitap Stok Güncelle\n";
		cout << "7-Çýkýþ\n";
		cout << "Seçiminiz: ";
		cin >> secim;
		cout << "\n";

		if (secim < 1 || secim > 7)
		{
			cout << "HATALI SEÇÝM YAPTINIZ. LÜTFEN TEKRAR DENEYÝN." << endl;
			continue; //hatalý seçim yapýldýðýnda döngünün baþýna dön
		}
		if (secim == 7) {
			cout << "ÇIKIÞ YAPILIYOR...\n" << endl;
			break;
		}

		switch (secim) {
		case 1:
			// Kullanýcýlarý görüntüleme kodu
			kullaniciListele(kullanicilar);
			break;
		case 2:
		{
			// Kullanýcý silme kodu
			kullaniciSil(kullanicilar, kitaplar);
			break;
		}
		case 3:
			// Kitaplarý görüntüleme kodu
			kitapListele(kitaplar);
			break;
		case 4:
			// Kitap ekleme kodu
			kitapEkle(kitaplar);
			kitapDosyayiYenidenYaz(kitaplar); // eklenen kitabýn dosyaya kaydedilmesi
			break;
		case 5:
			// Kitap silme kodu
			kitapListele(kitaplar);
			kitapSil(kitaplar);
			kitapDosyayiYenidenYaz(kitaplar); // silinen kitabýn dosyaya kaydedilmesi
			break;
		case 6:
			// Kitap stok güncelleme kodu
			kitapListele(kitaplar);
			kitapStokGuncelle(kitaplar);
			break;
		default:
			cout << "Hatalý seçim! Lütfen tekrar deneyin.\n";
			break;
		}

	}
}
