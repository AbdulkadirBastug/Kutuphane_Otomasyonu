İf bloğuyla kullanıcı adı şifre kontrollerini yaptım.do while ile menüyü ekrana yazdırıp seçenekler dışında seçildiğinde tekrar ekrana çıkarttırdım. Seçimleri de iflerle yaptım ve ekrana saat yazdıran void fonksiyonu yazdım.
Seçim 1 de son satıra kadar her satırı okutup aynı T.C. den okuyucu var mı kontrol ettirdim yoksa dosyaya yeni okuyucu yazdırdım.
Seçim 2 de güncellenecek T.C. numarasını alıp bu T.C. den okuyucu var mı diye okutturdum ifstreamle ve bulunduğunda bilgilerini ekrana yazdırdım ve yeni bilgileri isteyip ofstreamle geçici bir dosyaya yazdırdım diğer okuyucuları da aynı bilgilerle geçici dosyaya yazdırdım sonra da okuyucu dosyasını kaldırıp geçici dosyasının adını okuyucu dosyasıyla değiştirdim.
Seçim 3 de silinecek T.C. numarasını arattırdım var mı yok diye aynı şekilde eşleşmeyenleri geçici dosyaya yazdırdım eşleşen T.C. numaralı okuyucuyu ise hiç yazdırmadım.
Seçim 4 de T.C. No girdirip ödünç dosyasında eşleşen kitapları yazdırdım.
Seçim 5 de ISBN ve T.C. No istedim böylece kitap ve okuyucu var mı kontrol ettim sonra da ödünç dosyasına yazdırdım 
Seçim 6 de kitap iadesi için T.C. isteyip kontrollerini yaptım ve her şey doğruysa iade tarihini isteyip geçici dosyaya yazdırdım eşleşmeyenleri ise aynı bilgileriyle yazdırdım sonra da ödünç dosyasını kaldırıp geçici dosyasının adını ödünç dosyasıyla değiştirdim.
Seçim 7 de ISBN kontrolüyle aynı kitaptan var mı kontrol ettirdim yoksa kitaplar dosyasında yazdırdım.
Seçim 8 de silinecek ISBN kontrolünü yapıp eşleşeni geçici dosyaya yazdırmadım diğerlerini yazdırdım ve kitaplar dosyasını kaldırıp geçici dosyasının adını kitaplar dosyasıyla değiştirdim.
Seçim 9 da düzenlenecek olan ISBN’li kitabın olup olmadığını kontrol edip eski bilgilerini ekrana yazdırdım ve yeni bilgilerini isteyip geçici dosyaya yazdırdım. Eşleşmeyen ISBN’li kitapları da aynen yazdırdım ve kitaplar dosyasını kaldırıp geçici dosyasının adını kitaplar dosyasıyla değiştirdim.
