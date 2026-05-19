#include "UyeMenu.h"

#include "KullaniciService.h"
#include "KitapService.h"
#include "Dosya.h"

#include <iostream>

using namespace std;

//----uye menusu fonksiyonu----//	
void uyeMenu(vector<Kullanici>& kullanicilar, vector<Kitap>& kitaplar, int index) {
	// üye menüsü kodları buraya gelecek
	int secim;
	cout << "\nÜye menüsüne hoş geldiniz!\n";
	while (true) {
		cout << "\n1-Kitapları Görüntüle\n";
		cout << "2-Kitaplarım\n";
		cout << "3-Kitap Ödünç Al\n";
		cout << "4-Kitap İade Et\n";
		cout << "5-Hesabı Kapat\n";
		cout << "6-Çıkış\n";
		cout << "Seçiminiz: ";
		cin >> secim;
		cout << "\n";

		if (secim < 1 || secim > 6)
		{
			cout << "HATALI SEÇİM YAPTINIZ. LÜTFEN TEKRAR DENEYİN." << endl;
			continue; //hatalı seçim yapıldığında döngünün başına dön
		}
		if (secim == 6) {
			cout << "ÇIKIŞ YAPILIYOR...\n" << endl;
			break;
		}
		switch (secim) {
		case 1:
			// Kitapları görüntüleme kodu
			kitapListele(kitaplar);
			break;
		case 2:
			// Kitaplarım kodu
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
			// Kullanıcıyı silme işlemi yapılacak
			// kullaniciSil(kullanicilar); // bu fonksiyon admin menüsünde var, kullanıcı menüsünde de benzer bir fonksiyon yazılabilir
			break;
		default:
			cout << "Hatalı seçim! Lütfen tekrar deneyin.\n";
			break;
		}
	}
}
