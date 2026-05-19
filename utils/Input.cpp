#include "Input.h"
#include "Helper.h"

#include <iostream>

using namespace std;


//----Tc alma fonksiyonu----//
unsigned long long tcKimlikAl() {
	string tcStr;

	do {
		cout << "TC KİMLİK NO: ";
		cin >> tcStr;

		if (tcStr.length() != 11 || !sadeceRakamMi(tcStr)) {
			cout << "HATALI TC! Sadece 11 haneli rakam giriniz.\n";
		}


	} while (tcStr.length() != 11 || !sadeceRakamMi(tcStr));

	// string → unsigned long long
	return stoull(tcStr);
}

//----Ad Soyad alma fonksiyonu----//
string adSoyadAl() {
	string adSoyad;
	cin.ignore();
	do {
		cout << "AD VE SOYAD: ";

		getline(cin, adSoyad);

		if (!gecerliAdSoyad(adSoyad)) {
			cout << "HATALI GİRİŞ! Sadece harf ve boşluk kullanınız.\n";
		}

	} while (!gecerliAdSoyad(adSoyad));
	return adSoyad;
}

//----Kitap adı alma fonksiyonu----//
string kitapAdiAl() {
	string kitapAdi;

	do {
		cout << "KITAP ADI: ";
		getline(cin >> ws, kitapAdi);

		if (!gecerliKitapAdi(kitapAdi)) {
			cout << "HATALI GİRİŞ! Sadece harf ve boşluk kullanınız.\n";
		}

	} while (!gecerliKitapAdi(kitapAdi));

	return kitapAdi;
}

//----Yazar adı alma fonksiyonu----//
string yazarAdiAl() {
	string yazarAdi;

	do {
		cout << "YAZAR ADI: ";
		getline(cin >> ws, yazarAdi);

		if (!gecerliAdSoyad(yazarAdi)) {
			cout << "HATALI GİRİŞ! Sadece harf ve boşluk kullanınız.\n";
		}

	} while (!gecerliAdSoyad(yazarAdi));

	return yazarAdi;
}

//----Stok adedi alma fonksiyonu----//
int stokAdediAl() {
	string stokStr;

	do {
		cout << "STOK ADEDİ: ";
		cin >> stokStr;
		if (!sadeceRakamMi(stokStr)) {
			cout << "HATALI GİRİŞ! Sadece rakam giriniz.\n";
		}


	} while (!sadeceRakamMi(stokStr));
	// string → unsigned long long
	return stoull(stokStr);
}

//----Sifre kayıt etme fonksiyonu----//
string sifreGiris() {
	string sifre;
	string sifreTekrar;
	cout << "ŞİFRENİZİ GİRİNİZ: ";
	do {
		cin >> sifre;
		if (sifre.length() != 6) {
			cout << "HATALI ŞİFRE! Şifreniz en az 6 karakter olmalıdır.\nLÜTFEN TEKRAR GİRİNİZ: ";
		}
		else if (!sadeceRakamMi(sifre)) {
			cout << "HATALI ŞİFRE! Şifre sadece rakamlardan oluşmalıdır.\nLÜTFEN TEKRAR GİRİNİZ: ";
		}
	} while (sifre.length() != 6 || !sadeceRakamMi(sifre));
	cout << "TEKRAR ŞİFRENİZİ GİRİNİZ: ";

	do {
		cin >> sifreTekrar;
		if (sifreTekrar != sifre) {
			cout << "Şifreler uyuşmuyor. Lütfen tekrar deneyin:\n ";
		}

		else if (!sadeceRakamMi(sifreTekrar)) {
			cout << "Şifre sadece rakamlardan oluşmalıdır!\n";
		}

	} while (sifreTekrar != sifre || !sadeceRakamMi(sifreTekrar));

	return sifreTekrar;
}

//----Sifre alma fonksiyonu----//
string sifreAl() {
	string sifre;
	cout << "Sifre giriniz: ";
	cin >> sifre;
	return sifre;
}
