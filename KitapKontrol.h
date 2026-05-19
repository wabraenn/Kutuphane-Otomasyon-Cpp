#pragma once
#include <string>
#include <vector>
#include <ctime>
#include "Kitap.h"
#include "Kullanici.h"

// Giriþ / veri alma
std::string kitapAdiAl();
std::string yazarAdiAl();
int stokAdediAl();

// Kitap kontrolleri
bool kitapBul(const std::vector<Kitap>& kitaplar, const std::string& kitapAdi);
int kitapBulunduMu(const std::vector<Kitap>& kitaplar, const std::string& kitapAdi);
bool kitapStokKontrol(const std::vector<Kitap>& kitaplar, const std::string& kitapAdi);

// Kullanýcý kontrolleri
bool kullaniciAyniKitabiAlmisMi(const std::vector<Kullanici>& kullanicilar, const std::string& kitapAdi, int index);
bool alinanKitapSayisiKontrol(const std::vector<Kullanici>& kullanicilar, int index);

// Zaman iþlemi
time_t kitapAlinmaTarihiEkle();

//----Ayný kitap var mi kontrol fonksiyonu----//
bool kitapVarMi(const vector<Kitap>& kitaplar, const string& kitapAdi);