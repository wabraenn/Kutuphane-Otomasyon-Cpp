#pragma once
#include <string>

unsigned long long adminKullaniciAdiAl();
std::string adminSifreAl();
int adminLogin();
bool adminGirisKontrol(const Admin& admin, unsigned long long kullaniciAdi, const string& sifre);
