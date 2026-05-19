#pragma once
#include <vector>
#include "Kullanici.h"
#include "Kitap.h"

void kitapDosyayaKaydet(const std::vector<Kitap>& kitaplar);

void dosyadanOku(std::vector<Kullanici>& kullanicilar);
void kitapDosyadanOku(std::vector<Kitap>& kitaplar);

void kitapDosyayiYenidenYaz(const std::vector<Kitap>& kitaplar);
void dosyayiYenidenYaz(const std::vector<Kullanici>& kullanicilar);