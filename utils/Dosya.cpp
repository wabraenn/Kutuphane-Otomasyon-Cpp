#include "Dosya.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

//----Kitapları dosyaya kaydetme işlemi----//
void kitapDosyayaKaydet(const vector<Kitap>& kitaplar) {
	ofstream dosya("kitaplar.txt", ios::app); // ekleme modu

	if (!dosya.is_open()) {
		cout << "Dosya acilamadi!\n";
		return;
	}

	for (const Kitap& k : kitaplar) {
		dosya << k.kitapAdi << "|"
			<< k.yazarAdi << "|"
			<< k.stokAdedi << "\n";
	}

	dosya.close();
}

//----Dosya okuma islemi----//
void dosyadanOku(vector<Kullanici>& kullanicilar) {
	ifstream dosya("kullanicilar.txt");

	if (!dosya.is_open()) {
		// Dosya yoksa bu bir hata değildir
		return;
	}

	string satir;

	while (getline(dosya, satir)) {
		stringstream ss(satir);
		string tcStr, adSoyad, sifre, oduncAlinanKitaplarStr, kitapAlinmaTarihleriStr;

		getline(ss, tcStr, '|');
		getline(ss, adSoyad, '|');
		getline(ss, sifre, '|');
		getline(ss, oduncAlinanKitaplarStr, '|');
		getline(ss, kitapAlinmaTarihleriStr, '|');
		Kullanici k;
		k.tcKimlik = stoull(tcStr);
		k.adSoyad = adSoyad;
		k.sifre = sifre;


		// kitapları ayır
		stringstream kitapSS(oduncAlinanKitaplarStr);
		string kitap;
		while (getline(kitapSS, kitap, ',')) {
			if (!kitap.empty()) {
				k.oduncAlinanKitaplar.push_back(kitap);
			}
		}

		// tarihleri ayır
		stringstream tarihSS(kitapAlinmaTarihleriStr);
		string tarihStr;
		while (getline(tarihSS, tarihStr, ',')) {
			if (!tarihStr.empty()) {
				k.kitapAlinmaTarihleri.push_back(stoull(tarihStr));
			}
		}

		// kontrol
		if (k.oduncAlinanKitaplar.size() != k.kitapAlinmaTarihleri.size()) {
			cout << "Veri uyumsuz!\n";
		}

		kullanicilar.push_back(k);
	}

	dosya.close();
}

//----Kitapları dosyadan okuma işlemi----//
void kitapDosyadanOku(vector<Kitap>& kitaplar) {
	ifstream dosya("kitaplar.txt");

	if (!dosya.is_open()) {
		// Dosya yoksa bu bir hata değildir
		return;
	}

	string satir;

	while (getline(dosya, satir)) {
		stringstream ss(satir);
		string kitapAdi, yazarAdi, stokStr;

		getline(ss, kitapAdi, '|');
		getline(ss, yazarAdi, '|');
		getline(ss, stokStr, '|');
		Kitap k;
		k.kitapAdi = kitapAdi;
		k.yazarAdi = yazarAdi;
		k.stokAdedi = stoi(stokStr);
		kitaplar.push_back(k);
	}

	dosya.close();
}

//----Kitap dosyasını güncelleme fonksiyonu----//
void kitapDosyayiYenidenYaz(const vector<Kitap>& kitaplar) {
	ofstream dosya("kitaplar.txt", ios::trunc); // 🔴 ESKİ DOSYA SİLİNİR

	if (!dosya.is_open()) {
		cout << "Dosya acilamadi!\n";
		return;
	}

	for (const auto& k : kitaplar) {
		dosya << k.kitapAdi << "|"
			<< k.yazarAdi << "|"
			<< k.stokAdedi << "\n";
	}

	dosya.close();
}


//----Dosya güncelleme islemi----//
void dosyayiYenidenYaz(const vector<Kullanici>& kullanicilar) {
	ofstream dosya("kullanicilar.txt", ios::trunc); // 🔴 ESKİ DOSYA SİLİNİR

	if (!dosya.is_open()) {
		cout << "Dosya acilamadi!\n";
		return;
	}

	for (const auto& k : kullanicilar) {
		dosya << k.tcKimlik << "|"
			<< k.adSoyad << "|"
			<< k.sifre << "|";
		for (size_t i = 0; i < k.oduncAlinanKitaplar.size(); i++) {
			dosya << k.oduncAlinanKitaplar[i];
			if (i + 1 < k.oduncAlinanKitaplar.size())
				dosya << ",";
		}
		for (size_t i = 0; i < k.kitapAlinmaTarihleri.size(); i++) {
			dosya << k.kitapAlinmaTarihleri[i];
		}
		dosya << "\n";
	}

	dosya.close();
}
