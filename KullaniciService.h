#pragma once
#include <vector>
#include "Kullanici.h"
#include "Kitap.h"

void uyeKaydi(std::vector<Kullanici>& kullanicilar);
int login(const std::vector<Kullanici>& kullanicilar);

void kullaniciSil(std::vector<Kullanici>& kullanicilar, std::vector<Kitap>& kitaplar);
void kullaniciListele(const std::vector<Kullanici>& kullanicilar);