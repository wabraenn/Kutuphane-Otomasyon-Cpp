#pragma once
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct Kullanici
{
    vector<string> oduncAlinanKitaplar;
    vector<time_t> kitapAlinmaTarihleri;
    unsigned long long tcKimlik;
    string sifre;
    string adSoyad;
};
