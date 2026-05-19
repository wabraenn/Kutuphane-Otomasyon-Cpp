#include <string>
#include <cctype>

using namespace std;

string kucukHarfeCevir(string s) {
    for (char& c : s) {
        c = tolower((unsigned char)c);
    }
    return s;
}

bool sadeceRakamMi(const string& s) {
    if (s.empty()) return false;

    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

//----Ad Soyad kontrol fonksiyonu----//
bool gecerliAdSoyad(const string& ad) {
	for (unsigned char c : ad) {

		// boþluk serbest
		if (c == ' ')
			continue;

		// Ýngilizce harfler
		if (c >= 'A' && c <= 'Z')
			continue;

		if (c >= 'a' && c <= 'z')
			continue;

		// ASCII dýþý karakterler (Türkçe harfler burada)
		if (c >= 128)
			continue;

		// geri kalan HER ÞEY yasak
		return false;
	}
	return true;
}

//----Kitap adý kontrol----//
bool gecerliKitapAdi(const string& ad) {
	for (unsigned char c : ad) {

		// boþluk serbest
		if (c == ' ')
			continue;

		// Ýngilizce harfler
		if (c >= 'A' && c <= 'Z')
			continue;

		if (c >= 'a' && c <= 'z')
			continue;

		// ASCII dýþý karakterler (Türkçe harfler burada)
		if (c >= 128)
			continue;

		if (c >= '0' && c <= '9')
			continue;
		// geri kalan HER ÞEY yasak
		return false;
	}
	return true;
}
