#pragma once
#include <vector>
#include "Kitap.h"
#include "Kullanici.h"

void kitapEkle(std::vector<Kitap>& kitaplar);
void kitapSil(std::vector<Kitap>& kitaplar);
void kitapListele(const std::vector<Kitap>& kitaplar);
void kitapOdunc(std::vector<Kitap>& kitaplar, std::vector<Kullanici>& kullanicilar, int index);
void kitapIade(std::vector<Kitap>& kitaplar, std::vector<Kullanici>& kullanicilar, int index);
void kitapStokGuncelle(std::vector<Kitap>& kitaplar);
void alinanKitaplariGoruntule(const vector<Kullanici>& kullanicilar, const vector<Kitap>& kitaplar, int index);