#include "KullaniciService.h"
#include "KullaniciKontrol.h"
#include "Kullanici.h"
#include "Kitap.h"
#include "KitapKontrol.h"
#include "Helper.h"
#include "Dosya.h"
#include "Input.h"

#include <iostream>

using namespace std;

//----Uye kaydi fonksiyonu----//
void uyeKaydi(vector<Kullanici>& kullanicilar) {

	Kullanici yeniKayit;
	do {
		yeniKayit.tcKimlik = tcKimlikAl();
		if (tcVarMi(kullanicilar, yeniKayit.tcKimlik)) {
			cout << "Bu TC zaten kayitli!\n";
		}
	} while (tcVarMi(kullanicilar, yeniKayit.tcKimlik));
	yeniKayit.adSoyad = adSoyadAl();
	yeniKayit.sifre = sifreGiris();

	kullanicilar.push_back(yeniKayit);

}

//----Giriş işlemleri fonksiyonu----//
int login(const vector<Kullanici>& kullanicilar) {
	Kullanici girisKontrol;
	int index = -1;
	char devam;

	do {
		girisKontrol.tcKimlik = tcKimlikAl();
		index = -1;

		// 🔹 TC ARAMA
		for (int i = 0; i < kullanicilar.size(); i++) {
			if (girisKontrol.tcKimlik == kullanicilar[i].tcKimlik) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			// 🔹 ŞİFRE KONTROL
			do {
				girisKontrol.sifre = sifreAl();

				if (girisKontrol.sifre == kullanicilar[index].sifre) {
					return index;
				}
				else {
					cout << "Hatalı şifre! Tekrar denemek ister misiniz? (e/h): ";
					cin >> devam;
				}
			} while (devam == 'e' || devam == 'E');
		}
		else {
			cout << "Bu TC'ye sahip kullanıcı bulunamadı! Tekrar denemek ister misiniz? (e/h): ";
			cin >> devam;
		}

	} while (devam == 'e' || devam == 'E');

	return -1;
}

//----kullanıcı silme fonksiyonu----//
void kullaniciSil(vector<Kullanici>& kullanicilar, vector<Kitap>& kitaplar) {

	unsigned long long tcSil;
	char silmeKontrol;
	bool kullaniciBulundu = false;

	cout << "Kullanıcı silmek için Tc kimlik numarası giriniz:\n";
	tcSil = tcKimlikAl();

	for (size_t i = 0; i < kullanicilar.size(); i++) {
		if (kullanicilar[i].tcKimlik == tcSil) {

			kullaniciBulundu = true;

			cout << "Kullanıcıyı silmek istediğinize emin misiniz? (E/H): ";
			cin >> silmeKontrol;

			if (silmeKontrol == 'E' || silmeKontrol == 'e') {

				// 🔥 TÜM KİTAPLARI GERİ VER
				for (size_t j = 0; j < kullanicilar[i].oduncAlinanKitaplar.size(); j++) {

					string kitapAdi = kullanicilar[i].oduncAlinanKitaplar[j];

					int kitapIndex = kitapBulunduMu(kitaplar, kitapAdi);

					if (kitapIndex != -1) {
						kitaplar[kitapIndex].stokAdedi++;
					}
				}

				// 🔥 kullanıcıyı sil
				kullanicilar.erase(kullanicilar.begin() + i);

				kitapDosyayiYenidenYaz(kitaplar);
				dosyayiYenidenYaz(kullanicilar);

				cout << "Kullanıcı başarıyla silindi.\n";
			}
			else {
				cout << "İşlem iptal edildi.\n";
			}

			break;
		}
	}

	if (!kullaniciBulundu) {
		cout << "Bu TC'ye sahip kullanıcı bulunamadı.\n";
	}

}

//----kullanıcı listeleme fonksiyonu----//
void kullaniciListele(const vector<Kullanici>& kullanicilar) {
	for (size_t i = 0; i < kullanicilar.size(); i++) {
		cout << i + 1 << ".Kullanıcı:\n";
		cout << "TC: " << kullanicilar[i].tcKimlik << "\n";
		cout << "Ad Soyad: " << kullanicilar[i].adSoyad << "\n";
		cout << "Ödünç Alınan Kitaplar: ";
		for (const auto& kitap : kullanicilar[i].oduncAlinanKitaplar) {
			cout << kitap << ", ";
		}
		cout << "\n";
	}
}
