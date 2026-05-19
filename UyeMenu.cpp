#include "UyeMenu.h"

#include "KullaniciService.h"
#include "KitapService.h"
#include "Dosya.h"

#include <iostream>

using namespace std;

//----uye menusu fonksiyonu----//	
void uyeMenu(vector<Kullanici>& kullanicilar, vector<Kitap>& kitaplar, int index) {
	// üye menüsü kodlarý buraya gelecek
	int secim;
	cout << "\nÜye menüsüne hoþ geldiniz!\n";
	while (true) {
		cout << "\n1-Kitaplarý Görüntüle\n";
		cout << "2-Kitaplarým\n";
		cout << "3-Kitap Ödünç Al\n";
		cout << "4-Kitap Ýade Et\n";
		cout << "5-Hesabý Kapat\n";
		cout << "6-Çýkýþ\n";
		cout << "Seçiminiz: ";
		cin >> secim;
		cout << "\n";

		if (secim < 1 || secim > 6)
		{
			cout << "HATALI SEÇÝM YAPTINIZ. LÜTFEN TEKRAR DENEYÝN." << endl;
			continue; //hatalý seçim yapýldýðýnda döngünün baþýna dön
		}
		if (secim == 6) {
			cout << "ÇIKIÞ YAPILIYOR...\n" << endl;
			break;
		}
		switch (secim) {
		case 1:
			// Kitaplarý görüntüleme kodu
			kitapListele(kitaplar);
			break;
		case 2:
			// Kitaplarým kodu
			alinanKitaplariGoruntule(kullanicilar, kitaplar, index);
			break;
		case 3:
			// Kitap ödünç alma kodu
			kitapOdunc(kitaplar, kullanicilar, index);

			break;
		case 4:
			// Kitap iade etme kodu
			kitapIade(kitaplar, kullanicilar, index);
			break;
		case 5:
			// Hesap kapatma kodu
			// Kullanýcýyý silme iþlemi yapýlacak
			// kullaniciSil(kullanicilar); // bu fonksiyon admin menüsünde var, kullanýcý menüsünde de benzer bir fonksiyon yazýlabilir
			break;
		default:
			cout << "Hatalý seçim! Lütfen tekrar deneyin.\n";
			break;
		}
	}
}
