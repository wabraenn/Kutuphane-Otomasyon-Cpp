
#include "AnaMenu.h"
#include "UyeMenu.h"
#include "AdminMenu.h"
#include "AdminInput.h"

#include "KullaniciService.h"
#include "KitapService.h"
#include "Dosya.h"

#include <iostream>

using namespace std;

//----Menu----//
void AnaMenu(vector<Kullanici>& kullanicilar, vector<Kitap>&
	kitaplar) {
	int secim;
	int index;
	cout << "Merhaba Kütüphanemize Hoþ Geldiniz\n\n";
	while (true) {
		cout << "1-Üye Giriþi\n";
		cout << "2-Üye Kaydý\n";
		cout << "3-Yönetici Giriþi\n";
		cout << "4-Çýkýþ\n";
		cout << "Seçiminiz:";
		cin >> secim;
		cout << "\n";

		if (secim < 1 || secim > 4)
		{
			cout << "HATALI SEÇÝM YAPTINIZ. LÜTFEN TEKRAR DENEYÝN." << endl;
			continue; //hatalý seçim yapýldýðýnda döngünün baþýna dön
		}
		if (secim == 4) {
			cout << "ÇIKIÞ YAPILIYOR..." << endl;
			break;
		}

		switch (secim)
		{
		case 1: {
			char devam;
			int index = login(kullanicilar);
			if (index == -1) {
				cout << "Giriþ baþarýsýz. Ana menüye dönülüyor...\n";
				continue;
			}
			else {
				uyeMenu(kullanicilar, kitaplar, index);
			}


			break;
		}
		case 2:
			uyeKaydi(kullanicilar);
			dosyayiYenidenYaz(kullanicilar);
			cout << "\n";
			break;

		case 3: {
			int adminGirisSonucu = adminLogin();
			if (adminGirisSonucu == 1) {
				adminMenu(kullanicilar, kitaplar);
			}
			else {
				cout << "Admin giriþi baþarýsýz. Ana menüye dönülüyor...\n";
			}

			break;
		}
		default:
			break;
		}
	}
}
