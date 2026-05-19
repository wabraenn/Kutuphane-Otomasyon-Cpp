#include "KitapService.h"
#include "Kitap.h"
#include "Kullanici.h"
#include "Helper.h"
#include "Dosya.h"

#include <iostream>

using namespace std;


//----kitap bulma fonksiyonu----//
bool kitapBul(const vector<Kitap>& kitaplar, const string& kitapAdi) {
	for (const auto& kitap : kitaplar) {
		if (kucukHarfeCevir(kitap.kitapAdi) == kucukHarfeCevir(kitapAdi)) {

			return true;
		}
	}
	return false;
}

//----kitap alınma tarihi ekleme fonksiyonu----//
time_t kitapAlinmaTarihiEkle() {
	return time(nullptr); // geçerli zamanı döndürür
}

//----kitap var mi kontrol fonksiyonu----//
int kitapBulunduMu(const vector<Kitap>& kitaplar, const string& kitapAdi) {

	for (size_t i = 0; i < kitaplar.size(); i++) {
		if (kucukHarfeCevir(kitaplar[i].kitapAdi) == kucukHarfeCevir(kitapAdi)) {
			return i;
		}
	}
	return -1;

}

//----kitap stok kontrol fonksiyonu----//
bool kitapStokKontrol(const vector<Kitap>& kitaplar, const string& kitapAdi) {
	for (const auto& kitap : kitaplar) {
		if (kucukHarfeCevir(kitap.kitapAdi) == kucukHarfeCevir(kitapAdi)) {
			return kitap.stokAdedi > 0; // stok varsa true döndür
		}
	}
	return false; // kitap bulunamazsa false döndür
}

//----kullanıcı aynı kitabı almış mı kontrol fonksiyonu----//
bool kullaniciAyniKitabiAlmisMi(const vector<Kullanici>& kullanicilar, const string& kitapAdi, int index) {
	for (const string& kitap : kullanicilar[index].oduncAlinanKitaplar) {
		if (kucukHarfeCevir(kitap) == kucukHarfeCevir(kitapAdi)) {
			return true; // kullanıcı aynı kitabı almış
		}
	}
	return false; // kullanıcı aynı kitabı almamış
}

//----kullanıcının sahip olduğu kitap sayısı----//
bool alinanKitapSayisiKontrol(const vector<Kullanici>& kullanicilar, int index) {
	if (kullanicilar[index].oduncAlinanKitaplar.size() < 4) {
		return true;
	}
	return false;
}

//----Aynı kitap var mi kontrol fonksiyonu----//
bool kitapVarMi(const vector<Kitap>& kitaplar, const string& kitapAdi) {
	for (const auto& kitap : kitaplar) {
		if (kucukHarfeCevir(kitap.kitapAdi) == kucukHarfeCevir(kitapAdi)) {
			return true;
		}
	}
	return false;
}
