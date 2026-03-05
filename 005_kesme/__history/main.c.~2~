#include <16f877.h> // Eksik olan kütüphane eklendi

// Denetleyici Konfigürasyonu
#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG
#use delay(clock=4M)
#use fast_io(b)

// --- DIÞ KESME FONKSÝYONU ---
#int_ext
void dis_kesme() 
{
    // Kesme tetiklendiðinde B portundaki tüm çýkýþlarý sýfýrla
    output_b(0x00); 
}

void main() 
{
    // Modülleri Devre Dýþý Býrakma (Güç tasarrufu ve stabilite için)
    setup_psp(PSP_DISABLED);
    setup_timer_1(T1_DISABLED);
    setup_timer_2(T2_DISABLED, 0, 1);
    setup_adc_ports(NO_ANALOGS);
    setup_adc(ADC_OFF);
    setup_ccp1(CCP_OFF);
    setup_ccp2(CCP_OFF);

    // Port Ayarlarý
    set_tris_b(0x01);   // RB0 giriþ (Kesme pini), diðerleri çýkýþ
    output_b(0x02);     // Baþlangýçta RB1 pinini lojik-1 yap

    // Kesme Konfigürasyonu
    ext_int_edge(H_TO_L);       // Düþen kenar tetiklemesi (Yüksekten Alçaða)
    enable_interrupts(INT_EXT); // Dýþ kesmeyi aktif et
    enable_interrupts(GLOBAL);  // Genel kesmeleri aktif et

    // Ana Döngü
    while(TRUE) 
    {
        // Ýþlemci burada bekler, kesme gelince dis_kesme fonksiyonuna atlar
    }
}
