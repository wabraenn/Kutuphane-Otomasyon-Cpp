#define _CRT_SECURE_NO_WARNINGS

#include "KitapService.h"
#include "Kitap.h"
#include "Kullanici.h"
#include "Helper.h"
#include "Dosya.h"
#include "KitapKontrol.h"

#include <iostream>


using namespace std;


//----kitap ekleme fonksiyonu----//
void kitapEkle(vector<Kitap>& kitaplar) {
	char devam;

	do {
		Kitap yeniKitap;

		yeniKitap.kitapAdi = kitapAdiAl();
		yeniKitap.yazarAdi = yazarAdiAl();
		yeniKitap.stokAdedi = stokAdediAl();

		if (kitapVarMi(kitaplar, yeniKitap.kitapAdi)) {
			cout << "Bu kitap zaten mevcut!\n";
		}
		else {
			cout << "Kitap başarıyla eklendi!\n\n";
			kitaplar.push_back(yeniKitap);
		}

		cout << "Devam etmek istiyor musunuz? (E/H): ";
		cin >> devam;
		devam = toupper(devam);
	} while (devam == 'E');
}

//----kitap silme fonksiyonu----//
void kitapSil(vector<Kitap>& kitaplar) {
	string kitapSilAd;
	char silmeKontrol;
	char devam;
	bool kitapBulundu = false;
	do {
		cout << "Silmek istediğiniz kitabın adını girmeniz gerekmektedir.\n";
		kitapSilAd = kitapAdiAl();

		for (size_t i = 0; i < kitaplar.size(); i++) {
			if (kucukHarfeCevir(kitaplar[i].kitapAdi) == kucukHarfeCevir(kitapSilAd)) {
				kitapBulundu = true;
				cout << kitaplar[i].kitapAdi << " isimli kitabı silmek isteiğinize emin misiniz? (E/H):";
				cin >> silmeKontrol;
				if (silmeKontrol == 'E' || silmeKontrol == 'e') {
					kitaplar.erase(kitaplar.begin() + i);
					kitapDosyayiYenidenYaz(kitaplar);
					cout << "Kitap başarıyla silindi.\n";
					cout << "Başka kitap silmek istiyor musunuz? (E/H): ";
					cin >> devam;
					devam = toupper(devam);
				}
				else {
					cout << "Kitap silme işlemi iptal edildi.\n";
				}
				break;
			}
		}if (!kitapBulundu) {
			cout << "Bu ada sahip kitap bulunamadı.\n";
		}

	} while (devam == 'E');


}

//----Kitap ödünç alma fonksiyonu----//
void kitapOdunc(vector<Kitap>& kitaplar, vector<Kullanici>& kullanicilar, int index)
{
	char devam;
	kitapListele(kitaplar);
	do {
		bool basariliMi = false;

		string kitapOdunc_ad = kitapAdiAl();

		int islem = kitapBulunduMu(kitaplar, kitapOdunc_ad);

		if (islem != -1) {

			if (kitapStokKontrol(kitaplar, kitapOdunc_ad)) {

				if (!kullaniciAyniKitabiAlmisMi(kullanicilar, kitapOdunc_ad, index)) {

					if (alinanKitapSayisiKontrol(kullanicilar, index)) {

						kitaplar[islem].stokAdedi--;

						kullanicilar[index].oduncAlinanKitaplar.push_back(kitapOdunc_ad);

						kullanicilar[index].kitapAlinmaTarihleri.push_back(kitapAlinmaTarihiEkle());

						kitapDosyayiYenidenYaz(kitaplar);
						dosyayiYenidenYaz(kullanicilar);

						cout << "Kitap başarıyla ödünç alındı.\n";
						basariliMi = true;

					}
					else {
						cout << "3 ten fazla kitap ödünç alamazsınız! ";

					}
				}
				else {
					cout << "Bu kitaba sahipsiniz! ";

				}
			}
			else {
				cout << "Stok kalmadı! ";

			}
		}
		else {
			cout << "Kitap bulunamadı!  ";

		}

		if (basariliMi)
			cout << "Başka kitap ödünç almak istiyor musunuz? (E/H): ";
		else
			cout << "Tekrar denemek ister misiniz? (E/H): ";

		cin >> devam;
		devam = toupper(devam);


	} while (devam == 'E');
}

//----Kitap iade fonksiyonu----//
void kitapIade(vector<Kitap>& kitaplar, vector<Kullanici>& kullanicilar, int index) {

	string kitapIade_ad = kitapAdiAl();
	bool kitapBulundu = false;
	bool kullaniciKitabiBulundu = false;

	for (size_t i = 0; i < kitaplar.size(); i++) {

		if (kucukHarfeCevir(kitaplar[i].kitapAdi) == kucukHarfeCevir(kitapIade_ad))
		{
			kitapBulundu = true;

			// Kullanıcı bu kitabı gerçekten almış mı?
			for (size_t j = 0; j < kullanicilar[index].oduncAlinanKitaplar.size(); j++) {
				if (kucukHarfeCevir(kullanicilar[index].oduncAlinanKitaplar[j]) == kucukHarfeCevir(kitapIade_ad)) {
					kullaniciKitabiBulundu = true;

					// İade işlemi
					kitaplar[i].stokAdedi++;
					kullanicilar[index].oduncAlinanKitaplar.erase(
						kullanicilar[index].oduncAlinanKitaplar.begin() + j);
					kullanicilar[index].kitapAlinmaTarihleri.erase(
						kullanicilar[index].kitapAlinmaTarihleri.begin() + j);

					kitapDosyayiYenidenYaz(kitaplar);
					dosyayiYenidenYaz(kullanicilar);

					cout << "Kitap başarıyla iade edildi.\n";
					return;
				}
			}

			// Kitap var ama kullanıcı almamış
			cout << "Hata! Bu kitap sizde değil.\n";
			return;
		}
	}

	if (!kitapBulundu) {
		cout << "Kitap bulunamadı!\n";
	}
}

//----kitap stok güncelleme fonksiyonu----//
void kitapStokGuncelle(vector<Kitap>& kitaplar) {
	string kitapAdi;
	int secim;
	int miktar;
	char devam;
	while (true) {


		cout << "\nİşlem seçiniz:\n\n1-Stok Ekle\n2-Stok Azalt\n3-Çıkış\nSeçiminiz: ";
		cin >> secim;

		if (secim < 1 || secim > 3) {
			cout << "Hatalı seçim!\n";
			continue;
		}

		if (secim == 3) {
			cout << "ÇIKIŞ YAPILIYOR...\n";
			break;
		}

		// 🔹 ORTAK INPUT
		kitapAdi = kitapAdiAl();
		miktar = stokAdediAl();
		int index = kitapBulunduMu(kitaplar, kitapAdi);

		// ❌ KİTAP YOK
		if (index == -1) {
			cout << "Bu ada sahip kitap bulunamadı.\n";
			cout << "Tekrar denemek ister misiniz? (e/h): ";
			cin >> devam;

			if (devam != 'e' && devam != 'E')
				break;
			else
				continue;
		}

		// ✅ STOK EKLE
		if (secim == 1) {
			kitaplar[index].stokAdedi += miktar;
			kitapDosyayiYenidenYaz(kitaplar);

			cout << "Stok başarıyla artırıldı.\n";
		}

		// ✅ STOK AZALT
		else if (secim == 2) {
			if (kitaplar[index].stokAdedi < miktar) {
				cout << "Miktar stoktan fazla olamaz.\n";

				cout << "Tekrar denemek ister misiniz? (e/h): ";
				cin >> devam;

				if (devam != 'e' && devam != 'E')
					break;
				else
					continue;
			}

			kitaplar[index].stokAdedi -= miktar;
			kitapDosyayiYenidenYaz(kitaplar);

			cout << "Stok başarıyla azaltıldı.\n";
		}

		// 🔁 İŞLEM SONRASI
		cout << "Başka bir işlem yapmak ister misiniz? (e/h): ";
		cin >> devam;

		if (devam != 'e' && devam != 'E')
			break;
	}
}

//----kitap listeleme fonksiyonu----//
void kitapListele(const vector<Kitap>& kitaplar) {
	for (size_t i = 0; i < kitaplar.size(); i++) {
		cout << i + 1 << ".Kitap:\n";
		cout << "Kitap Adı: " << kitaplar[i].kitapAdi << "\n";
		cout << "Yazar Adı: " << kitaplar[i].yazarAdi << "\n";
		if (kitaplar[i].stokAdedi == 0) {
			cout << "Stokta bulunamadı!\n";
		}
		else {
			cout << "Stok Adedi: " << kitaplar[i].stokAdedi << "\n";
			cout << "\n";
		}
	}
}

//----Alınan kitapları görüntüleme fonksiyonu----//
void alinanKitaplariGoruntule(const vector<Kullanici>& kullanicilar, const vector<Kitap>& kitaplar, int index) {

	if (kullanicilar[index].oduncAlinanKitaplar.empty()) {
		cout << "Hiç kitap ödünç alınmamış.\n";
		return;
	}
	for (size_t i = 0; i < kullanicilar[index].oduncAlinanKitaplar.size(); i++) {

		string kitapAdi = kullanicilar[index].oduncAlinanKitaplar[i];
		time_t alinanTarih = kullanicilar[index].kitapAlinmaTarihleri[i];

		cout << "Kitap: " << kitapAdi << endl;
		cout << "Tarih: " << ctime(&alinanTarih);


	}
}
