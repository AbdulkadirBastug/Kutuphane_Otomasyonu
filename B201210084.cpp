
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

void saatgoster()		//Sistemin o anki saatini yazd�r�yor
{
	string s;
	auto start = chrono::system_clock::now();
	auto baslangic = chrono::system_clock::to_time_t(start);
	char baslangicSaaat[35];

	ctime_s(baslangicSaaat, sizeof(baslangicSaaat), &baslangic);
	s = baslangicSaaat;
	cout << "Biti� saati:" << s.substr(11, 9) << "\n";

}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Turkish");
	string kullaniciadi;
	string sifre;
	string secim;
	//okuyucu bilgileri
	string TC_No;
	string Adi;
	string Soyadi;
	string uye_No;
	string Telefon;
	string Dogum_Tarihi;
	string Gorevi;
	string kitap_sayisi;
	//kitap bilgileri
	string ISBN;
	string Kitap_ismi;
	string Yazar_adi;
	string Yazar_soyadi;
	string Konu;
	string Tur;
	string Sayfa_sayisi;
	//�d�n� verilen dosya
	string Odunc_tarihi;
	string Donus_tarihi;
	string Tc;
	string isbn;
	string a;
	string b;
	string c;
	string d;
	string e;
	string f;
	string g;
	string h;
	string menu;
	int kayitsayisi = 0;
	bool kayitvarmi = false;
	string gecici_ISBN;
	bool okuyucu_kitap = false;
	bool okuyucuvarmi = false;
	bool kitapvarmi = false;
	bool oduncvarmi = false;
	int value;
	int kayitsayisi2 = 0;
	int kitapsayisi = 0;

	char cevap = 'e';

	cout << "kullan�c� ad�:";	cin >> kullaniciadi;
	cout << "�ifre:";			cin >> sifre;

	string Kullaniciadi;
	string Sifre;
	ifstream kullanicioku("kullan�c�lar.txt");
	do
	{
		kullanicioku >> Kullaniciadi >> Sifre;
	} while (kullaniciadi != Kullaniciadi);
	string s;
	auto start = chrono::system_clock::now();
	auto baslangic = chrono::system_clock::to_time_t(start);
	char baslangicSaaat[35];
	clock_t basla = clock(), bitis;

	ctime_s(baslangicSaaat, sizeof(baslangicSaaat), &baslangic);
	s = baslangicSaaat;
	if (kullaniciadi == Kullaniciadi)//kullanc� ad� �ifreyi do�rularsa giri� yap�yor ve men�y� g�steriyor
	{
		if (sifre == Sifre)
		{
			string s;
			auto start = chrono::system_clock::now();
			auto baslangic = chrono::system_clock::to_time_t(start);
			char baslangicSaaat[35];

			ctime_s(baslangicSaaat, sizeof(baslangicSaaat), &baslangic);
			s = baslangicSaaat;
			cout << "Ba�lang�� saati:" << s.substr(11, 9) << "\n" << "\n";

			do {
				cout << "1 - Okuyucu kayd�" << endl;
				cout << "2 - Okuyucu kayd� g�ncelleme" << endl;
				cout << "3 - Okuyucu silme" << endl;
				cout << "4 - Okuyucu �zerindeki kitaplar listesi" << endl;
				cout << "5 - Okuyucu kitap �d�n� alma" << endl;
				cout << "6 - Okuyucu kitap geri d�nd�rme" << endl;
				cout << "7 - Kitap ekleme" << endl;
				cout << "8 - Kitap silme" << endl;
				cout << "9 - Kitap d�zeltme" << endl;
				cin >> secim;
			} while (secim != "1" && secim != "2" && secim != "3" && secim != "4" && secim != "5" && secim != "6" && secim != "7" && secim != "8" && secim != "9");

		}
		else
		{
			exit(1);
		}


	}
	else
	{
		exit(1);

	}
	kullanicioku.close();




	if (secim == "1")
	{

		ofstream OkuyucuGir;
		OkuyucuGir.open("okuyucu.txt", ios::app);
		do {				//Sat�r sonuna kadar tc leri e�le�tiriyor bir e�le�me ��kmazsa hata veriyor

			cout << "Tc No:";						cin >> Tc;
			ifstream okuyucuoku("okuyucu.txt");


			while (!okuyucuoku.eof())
			{
				okuyucuoku >> TC_No >> Adi >> Soyadi >> uye_No >> Telefon >> Dogum_Tarihi >> Gorevi >> kitap_sayisi;

				if (Tc == TC_No)
				{
					cout << "Bu TC no'su zaten kay�tl�d�r\n" << endl;
					saatgoster();
					exit(1);
				}

			}
			okuyucuoku.close();
			cout << "Ad�:";							cin >> Adi;
			cout << "Soyad�:";						cin >> Soyadi;
			cout << "Uye No:";						cin >> uye_No;
			cout << "Telefon:";						cin >> Telefon;
			cout << "Do�um tarihi:";				cin >> Dogum_Tarihi;
			cout << "G�revi:";						cin >> Gorevi;
			cout << "Alabilece�i kitap say�s�:";	cin >> kitap_sayisi;

			OkuyucuGir << Tc << " " << Adi << " " << Soyadi << " " << uye_No << " " << Telefon << " " << Dogum_Tarihi << " " << Gorevi << " " << kitap_sayisi << "\n";
			cout << "okuyucu olu�turuldu\n" << endl;

			cout << "ba�ka kay�t yapacak m�s�n ?(e/h) ";  cin >> cevap;
		} while (cevap != 'h');		//h diyene kadar okuyucu kayd� yap�l�yor
		OkuyucuGir.close();
		saatgoster();

	}


	if (secim == "2")
	{
		string Tc2;
		cout << "G�ncellemek istedi�iniz ki�inin TC no'sunu giriniz:";	cin >> Tc;

		ifstream sayacoku("okuyucu.txt");

		while (!sayacoku.eof())			//Okuyucu say�s�n� bulan saya�
		{
			sayacoku >> a >> b >> c >> d >> e >> f >> g >> h;
			kayitsayisi++;
		}
		kayitsayisi -= 1;
		sayacoku.close();


		ifstream okuyucuoku("okuyucu.txt");

		for (int i = 0; i < kayitsayisi; i++)
		{

			okuyucuoku >> TC_No >> Adi >> Soyadi >> uye_No >> Telefon >> Dogum_Tarihi >> Gorevi >> kitap_sayisi;
			if (Tc == TC_No)		//Kay�t say�s� kadar d�nerek e�le�en tc var m� bak�yor(bulamazsa hata veriyor) ve e�le�me bulunca eski bilgileri getiriyor ve yenilerini istiyor
			{
				kayitvarmi = true;
				cout << "G�ncellemek istedi�iniz ki�inin bilgileri\n";
				cout << "Tc No:" << TC_No << endl;
				cout << "Ad�:" << Adi << endl;
				cout << "Soyad�:" << Soyadi << endl;
				cout << "Uye No:" << uye_No << endl;
				cout << "Telefon:" << Telefon << endl;
				cout << "Do�um tarihi:" << Dogum_Tarihi << endl;
				cout << "G�revi:" << Gorevi << endl;
				cout << "Alabilece�i kitap say�s�:" << kitap_sayisi << endl;

				cout << "G�ncellemek istedi�iniz ki�inin yeni bilgileri\n";
				cout << "Tc No:";					cin >> Tc2;

				ifstream Okuyucuoku;
				Okuyucuoku.open("okuyucu.txt");
				for (int i = 0; i < kayitsayisi; i++)
				{
					Okuyucuoku >> TC_No >> Adi >> Soyadi >> uye_No >> Telefon >> Dogum_Tarihi >> Gorevi >> kitap_sayisi;
					if (TC_No == Tc2)			// e�er ayn� tc den varsa  hata veriyor
					{
						cout << "Bu Tc no'lu okuyucu zaten bulunmaktad�r\n" << endl;
						saatgoster();
						exit(1);
					}
				}
				Okuyucuoku.close();

				cout << "Ad�:";						cin >> Adi;
				cout << "Soyad�:";					cin >> Soyadi;
				cout << "Uye No:";					cin >> uye_No;
				cout << "Telefon:";					cin >> Telefon;
				cout << "Do�um tarihi:";			cin >> Dogum_Tarihi;
				cout << "G�revi:";					cin >> Gorevi;
				cout << "Alabilece�i kitap say�s�:"; cin >> kitap_sayisi;


				ofstream okuyucugir;
				okuyucugir.open("gecici.txt", ios::app);

				okuyucugir << Tc2 << " " << Adi << " " << Soyadi << " " << uye_No << " " << Telefon << " " << Dogum_Tarihi << " " << Gorevi << " " << kitap_sayisi << "\n";
				okuyucugir.close();
			}
			else
			{

				ofstream okuyucugir;
				okuyucugir.open("gecici.txt", ios::app);
				okuyucugir << TC_No << " " << Adi << " " << Soyadi << " " << uye_No << " " << Telefon << " " << Dogum_Tarihi << " " << Gorevi << " " << kitap_sayisi << "\n";
				okuyucugir.close();
			}


		}
		if (kayitvarmi == false)			//B�yle bir TC nolu okuyucu yoksa hata veriyor
		{
			cout << "Kay�t bulunamad�!\n" << endl;
			saatgoster();
		}
		else
		{
			cout << "Kay�t g�ncellendi.\n" << endl;
			saatgoster();
		}

		okuyucuoku.close();
		remove("okuyucu.txt");						//Ana dosyay� kald�r�yor
		return rename("gecici.txt", "okuyucu.txt");// Ge�i�i dosyan�n ad�n� ana dosyayla de�i�tiriyor



	}
	if (secim == "3")
	{

		cout << "Silmek istedi�iniz ki�inin TC no'sunu giriniz:";	cin >> Tc;


		ifstream Sayacoku;
		Sayacoku.open("odunc.txt");

		while (!Sayacoku.eof())		//�d�n� verilen ki�i say�s�n� bulan saya�
		{
			Sayacoku >> a >> b >> c >> d;
			kayitsayisi2++;
		}
		kayitsayisi2 -= 1;
		Sayacoku.close();

		ifstream oduncoku;
		oduncoku.open("odunc.txt");

		for (int i = 0; i < kayitsayisi2; i++)		//Tc e�le�irse �d�n� ald�klar�n� yazd�rm�yor di�erlerini aynen ge�i�i dosyaya yazd�r�yor.
		{

			oduncoku >> ISBN >> TC_No >> Odunc_tarihi >> Donus_tarihi;
			if (TC_No == Tc && Donus_tarihi == "1")
			{

			}
			else
			{
				ofstream oduncgir;
				oduncgir.open("gecici.txt", ios::app);
				oduncgir << ISBN << " " << TC_No << " " << Odunc_tarihi << " " << Donus_tarihi << "\n";
				oduncgir.close();
			}

		}
		oduncoku.close();
		remove("odunc.txt");
		value = rename("gecici.txt", "odunc.txt");

		ifstream sayacoku("okuyucu.txt");

		while (!sayacoku.eof())			//Okuyucu say�s�n� bulan saya�
		{
			sayacoku >> a >> b >> c >> d >> e >> f >> g >> h;
			kayitsayisi++;
		}
		kayitsayisi -= 1;
		sayacoku.close();
		ifstream okuyucuoku("okuyucu.txt");

		for (int i = 0; i < kayitsayisi; i++)		//E�le�en TC no d���ndaki okuyucular� ge�i�i dosyaya yazd�r�yor
		{

			okuyucuoku >> TC_No >> Adi >> Soyadi >> uye_No >> Telefon >> Dogum_Tarihi >> Gorevi >> kitap_sayisi;
			if (Tc == TC_No)
			{
				kayitvarmi = true;
			}
			else
			{
				ofstream okuyucugir;
				okuyucugir.open("gecici.txt", ios::app);
				okuyucugir << TC_No << " " << Adi << " " << Soyadi << " " << uye_No << " " << Telefon << " " << Dogum_Tarihi << " " << Gorevi << " " << kitap_sayisi << "\n";
				okuyucugir.close();
			}


		}
		if (kayitvarmi == false)		//B�yle bir TC nolu okuyucu olup olmad�g�n� kontrol ediyor
		{
			cout << "Kay�t bulunamad�!\n" << endl;
			saatgoster();
		}
		else
		{
			cout << "Kay�t silindi.\n" << endl;
			saatgoster();
		}
		okuyucuoku.close();
		remove("okuyucu.txt");						//Ana dosyay� kald�r�yor
		return rename("gecici.txt", "okuyucu.txt");// Ge�i�i dosyan�n ad�n� ana dosyayla de�i�tiriyor


	}
	if (secim == "4")
	{

		ifstream sayacoku("odunc.txt");

		while (!sayacoku.eof())				// Ka� tane �d�n� verilen kitap oldu�unu bulan saya�
		{
			sayacoku >> a >> b >> c >> d;

			kayitsayisi++;
		}
		kayitsayisi -= 1;
		sayacoku.close();


		ifstream Sayacoku("kitaplar.txt");

		while (!Sayacoku.eof())			// ka� kitap oldu�unu bulan saya�
		{
			Sayacoku >> a >> b >> c >> d >> e >> f >> g;

			kitapsayisi++;
		}
		kitapsayisi -= 1;
		Sayacoku.close();


		cout << "Okuyucunun TC No'sunu giriniz:";	cin >> Tc;

		ifstream oduncoku;
		oduncoku.open("odunc.txt");
		for (int i = 0; i < kayitsayisi; i++)
		{

			oduncoku >> ISBN >> TC_No >> Odunc_tarihi >> Donus_tarihi;

			if (TC_No == Tc && Donus_tarihi == "1")		//Okyucu �zerinde kitap varsa kitaplar� yazd�r�yor
			{
				okuyucu_kitap = true;
				gecici_ISBN = ISBN;
				ifstream kitapoku;
				kitapoku.open("kitaplar.txt");
				for (int i = 0; i < kitapsayisi; i++)
				{

					kitapoku >> ISBN >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;

					if (gecici_ISBN == ISBN)
					{
						cout << ISBN << " " << Kitap_ismi << "\n";
					}

				}
				kitapoku.close();

			}



		}
		oduncoku.close();
		cout << endl;

		if (okuyucu_kitap == false)		//E�er Tc yanl��sa veya �zerinde kitap yoksa hata verdiriyor
		{
			cout << "Bu okuyucu �zerinde kitap yoktur veya yanl�� TC no girdiniz.\n" << endl;
		}
		else
		{
			cout << "^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^" << endl;
			cout << "Yukar�daki kitaplar " << Tc << " TC no'lu okuyucu �zerindeki kitaplard�r.\n";
		}


		saatgoster();

	}
	if (secim == "5")
	{
		string Donus_Tarihi = "1";
		ofstream oduncgir;
		oduncgir.open("odunc.txt", ios::app);
		do {

			cout << "ISBN:";						cin >> isbn;
			ifstream kitapoku("kitaplar.txt");
			while (!kitapoku.eof())					//Bu ISBN'yle kitap varm� kontrol ediyor ve yoksa hata veriyor
			{
				kitapoku >> ISBN >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;
				if (ISBN == isbn)
				{

					kitapvarmi = true;
				}

			}
			if (kitapvarmi == false)
			{
				cout << "Bu ISBN'li kitap bulunmamaktad�r\n" << endl;
				saatgoster();
				exit(1);
			}
			kitapoku.close();


			ifstream oduncoku("odunc.txt");

			while (!oduncoku.eof())
			{
				oduncoku >> ISBN >> TC_No >> Odunc_tarihi >> Donus_tarihi;

				if (ISBN == isbn && Donus_tarihi == "1")			//Ayn� kitap daha once �d�n� verildiyse hata veriyor
				{
					cout << "Bu kitap zaten �d�n� verildi\n" << endl;
					saatgoster();
					exit(1);
				}


			}
			oduncoku.close();

			cout << "TC No:";			cin >> Tc;

			ifstream okuyucuoku("okuyucu.txt");
			while (!okuyucuoku.eof())			//B�yle bir Tc nolu okuyucu var m� kontrol ediyor yoksa hata veriyor
			{
				okuyucuoku >> TC_No >> Adi >> Soyadi >> uye_No >> Telefon >> Dogum_Tarihi >> Gorevi >> kitap_sayisi;
				if (TC_No == Tc)
				{
					okuyucuvarmi = true;
				}

			}
			if (okuyucuvarmi == false)
			{
				cout << "Bu TC No'lu okuyucu bulunmamaktad�r\n" << endl;
				saatgoster();
				exit(1);
			}
			okuyucuoku.close();

			cout << "�d�n� Tarihi:";	cin >> Odunc_tarihi;


			oduncgir << isbn << " " << Tc << " " << Odunc_tarihi << " " << Donus_Tarihi << "\n";	//�d�n kayd� dosyaya yazd�r�l�yor

			cout << "�d�n� verildi" << endl;

			cout << "ba�ka �d�n� kitap verilecek mi ?(e/h) ";  cin >> cevap;
		} while (cevap != 'h');			//h yazana kadar dong�y� devam ettiriyor
		oduncgir.close();
		saatgoster();

	}
	if (secim == "6")
	{
		string Donus_Tarihi;

		ifstream sayacoku("odunc.txt");

		while (!sayacoku.eof())		//Ka� tane �d�n� verildi�ini bulmak i�in saya�
		{
			sayacoku >> a >> b >> c >> d;
			kayitsayisi++;
		}
		kayitsayisi -= 1;
		sayacoku.close();

		cout << "Geri vermek istedi�iniz kitab�n ISBN'sini giriniz:";	cin >> isbn;


		ifstream Oduncoku("odunc.txt");
		for (int i = 0; i < kayitsayisi; i++)
		{
			Oduncoku >> ISBN >> TC_No >> Odunc_tarihi >> Donus_tarihi;
			if (ISBN == isbn && Donus_tarihi == "1")		//Girilen ISBN'ye ait kitap �d�n� verilmi� mi kontrol ediyor
			{

				oduncvarmi = true;
			}

		}
		if (oduncvarmi == false)
		{
			cout << "Bu ISBN'li kitap �d�n� verilmemi�tir\n" << endl;
			saatgoster();
			exit(1);
		}
		Oduncoku.close();



		cout << "�ade tarihini giriniz:";  cin >> Donus_Tarihi;


		ifstream oduncoku("odunc.txt");

		for (int i = 0; i < kayitsayisi; i++)
		{

			oduncoku >> ISBN >> TC_No >> Odunc_tarihi >> Donus_tarihi;
			if (ISBN == isbn)		//E�le�en ISBN' yi ge�i�i dosyaya iade tarihi ile birlikte yazd�r�yor e�le�meyenleri aynen yazd�r�yor.
			{
				kayitvarmi = true;
				ofstream oduncgir;
				oduncgir.open("gecici.txt", ios::app);
				oduncgir << isbn << " " << TC_No << " " << Odunc_tarihi << " " << Donus_Tarihi << "\n";
				oduncgir.close();


			}
			else
			{

				ofstream oduncgir;
				oduncgir.open("gecici.txt", ios::app);
				oduncgir << ISBN << " " << TC_No << " " << Odunc_tarihi << " " << Donus_tarihi << "\n";
				oduncgir.close();

			}


		}
		if (kayitvarmi == false)		//�d�n� dosyas�nda bu ISBN var m� kontrol ediyor yoksa hata veriyor
		{
			cout << "Kay�t bulunamad�!\n" << endl;
			saatgoster();
		}
		else
		{
			cout << "�ade edildi\n" << endl;
			saatgoster();
		}

		oduncoku.close();
		remove("odunc.txt");					 //Ana dosyay� kald�r�yor
		return rename("gecici.txt", "odunc.txt");// Ge�i�i dosyan�n ad�n� ana dosyayla de�i�tiriyor

	}
	if (secim == "7")
	{
		ofstream kitapgir;
		kitapgir.open("kitaplar.txt", ios::app);
		do {

			cout << "ISBN:";						cin >> isbn;

			fstream kitapoku("kitaplar.txt");


			while (!kitapoku.eof())		//Girilen ISBN  daha �nce kaydedilmi� mi kontrol ediyor ve edilmi�se hata veriyor
			{
				kitapoku >> ISBN >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;

				if (ISBN == isbn)
				{
					cout << "Bu ISBN zaten kay�tl�d�r\n" << endl;
					saatgoster();
					exit(1);
				}

			}
			kitapoku.close();
			cout << "Kitap �smi:";			cin >> Kitap_ismi;
			cout << "Yazar Ad�:";			cin >> Yazar_adi;
			cout << "Yazar Soyad�:";		cin >> Yazar_soyadi;
			cout << "Konu:";				cin >> Konu;
			cout << "T�r:";					cin >> Tur;
			cout << "Sayfa Say�s�:";		cin >> Sayfa_sayisi;

			kitapgir << isbn << " " << Kitap_ismi << " " << Yazar_adi << " " << Yazar_soyadi << " " << Konu << " " << Tur << " " << Sayfa_sayisi << "\n";
			cout << "kitap kaydedildi" << endl;

			cout << "ba�ka kay�t yapacak m�s�n ?(e/h) ";  cin >> cevap;
		} while (cevap != 'h');	//h yazana kadar d�ng�y� devam ettiriyor
		kitapgir.close();
		saatgoster();

	}
	if (secim == "8")
	{

		cout << "Silmek istedi�iniz kitab�n ISBN'sini giriniz:";	cin >> isbn;

		ifstream Kitapoku("kitaplar.txt");

		while (!Kitapoku.eof())		//Ka� tane kitap oldu�unu bulan saya�
		{
			Kitapoku >> a >> b >> c >> d >> e >> f >> g;
			kayitsayisi++;
		}
		kayitsayisi -= 1;
		Kitapoku.close();


		ifstream kitapoku("kitaplar.txt");

		for (int i = 0; i < kayitsayisi; i++)	//ISBN e�le�en hari� di�erlerini ayn� �ekilde ge�i�i dosyaya yazd�r�yor
		{

			kitapoku >> ISBN >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;
			if (ISBN == isbn)
			{
				kayitvarmi = true;
			}
			else
			{
				ofstream kitapgir;
				kitapgir.open("gecici.txt", ios::app);
				kitapgir << ISBN << " " << Kitap_ismi << " " << Yazar_adi << " " << Yazar_soyadi << " " << Konu << " " << Tur << " " << Sayfa_sayisi << "\n";
				kitapgir.close();
			}


		}
		if (kayitvarmi == false)	//Kitap var m� kontrol ediyor
		{
			cout << "Kay�t bulunamad�!\n" << endl;
			saatgoster();
		}
		else
		{
			cout << "Kitap silindi.\n" << endl;
			saatgoster();
		}
		kitapoku.close();
		remove("kitaplar.txt");						//Ana dosyay� kald�r�yor
		return rename("gecici.txt", "kitaplar.txt");// Ge�i�i dosyan�n ad�n� ana dosyayla de�i�tiriyor


	}
	if (secim == "9")
	{

		cout << "D�zeltmek istedi�iniz kitab�n ISBN'sini giriniz:";	cin >> isbn;

		ifstream Kitapoku("kitaplar.txt");

		while (!Kitapoku.eof())		//Ka� tane kitap oldu�unu bulan saya�
		{
			Kitapoku >> a >> b >> c >> d >> e >> f >> g;
			kayitsayisi++;
		}
		kayitsayisi -= 1;
		Kitapoku.close();


		ifstream kitapoku("kitaplar.txt");

		for (int i = 0; i < kayitsayisi; i++)
		{

			kitapoku >> ISBN >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;
			if (ISBN == isbn)		//E�le�en ISBN'ye ait bilgileri ekrana yazd�ryor ve yeni bilgileri isteyip ge�i�i dosyaya yazd�r�yor
			{
				kayitvarmi = true;
				cout << "D�zeltmek istedi�iniz kitab�n bilgileri\n";
				cout << "ISBN:" << ISBN << endl;
				cout << "Kitap �smi:" << Kitap_ismi << endl;
				cout << "Yazar Ad�:" << Yazar_adi << endl;
				cout << "Yazar Soyad�:" << Yazar_soyadi << endl;
				cout << "Konu:" << Konu << endl;
				cout << "T�r:" << Tur << endl;
				cout << "Sayfa Say�s�:" << Sayfa_sayisi << endl;


				cout << "D�zeltmek istedi�iniz kitab�n yeni bilgileri\n";
				cout << "ISBN:";				cin >> ISBN;
				cout << "Kitap �smi:";			cin >> Kitap_ismi;
				cout << "Yazar Ad�:";			cin >> Yazar_adi;
				cout << "Yazar Soyad�:";		cin >> Yazar_soyadi;
				cout << "Konu:";				cin >> Konu;
				cout << "T�r:";					cin >> Tur;
				cout << "Sayfa Say�s�:";		cin >> Sayfa_sayisi;


				ofstream kitapgir;
				kitapgir.open("gecici.txt", ios::app);

				kitapgir << ISBN << " " << Kitap_ismi << " " << Yazar_adi << " " << Yazar_soyadi << " " << Konu << " " << Tur << " " << Sayfa_sayisi << "\n";
				kitapgir.close();
			}
			else		//E�le�meyen kitapla� ge�i�i dosyaya ayn� �ekilde yazd�r�yor
			{

				ofstream kitapgir;
				kitapgir.open("gecici.txt", ios::app);
				kitapgir << ISBN << " " << Kitap_ismi << " " << Yazar_adi << " " << Yazar_soyadi << " " << Konu << " " << Tur << " " << Sayfa_sayisi << "\n";
				kitapgir.close();
			}


		}
		if (kayitvarmi == false)	//Bu ISBN'ye ait kitap var m� kontrol ediyor ve varsa  hata veriyor
		{
			cout << "Kay�t bulunamad�!\n" << endl;
			saatgoster();
		}
		else
		{
			cout << "Kitap d�zeltildi.\n" << endl;
			saatgoster();
		}
		kitapoku.close();
		remove("kitaplar.txt");							//Ana dosyay� kald�r�yor
		return rename("gecici.txt", "kitaplar.txt");	// Ge�i�i dosyan�n ad�n� ana dosyayla de�i�tiriyor

	}







}

