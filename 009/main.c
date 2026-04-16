#include <16f877a.h>
#device ADC=10 // Daha hassas ölçüm için 10-bit (0-1023)
#use delay(clock=4M)

#define use_portb_lcd TRUE
#include <lcd.c>

unsigned long int deger; // 10-bit için long kullanmak daha güvenlidir
float voltaj;

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_CCP2(CCP_OFF);
   
   // PWM Frekansý ayarý (Yaklaþýk 1kHz)
   setup_timer_2(T2_DIV_BY_4, 249, 1); 
   setup_CCP1(CCP_PWM);
   
   setup_adc(adc_clock_div_32);
   setup_adc_ports(ALL_ANALOG);
   
   set_tris_a(0x20); // RA5 giriþ
   set_tris_c(0x00); // Port C çýkýþ (Motor ve PWM için)
   
   lcd_init();
   printf(lcd_putc,"\fDC Motor\nHiz Kontrolu");
   delay_ms(1000);
   
   set_pwm1_duty(0);
   set_adc_channel(4); // RA5/AN4 seçildi
   delay_us(20);

   while(TRUE)
   {
      deger = read_adc(); // 0-1023 arasý deðer okur
      
      // 10-bit ADC için voltaj hesabý: (deger * 5) / 1023
      voltaj = (float)deger * 0.0048828; 
      
      // Motor yön pinleri (L298/L293 baðlantýsýna göre)
      output_high(pin_c3);
      output_low(pin_c4);
      
      // PWM deðerini yaz (0-1023 arasý)
      set_pwm1_duty(deger);
      
      // Ekran Güncelleme
      printf(lcd_putc,"\fV=%1.2f V", voltaj);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"PWM Deger=%lu", deger);
      
      delay_ms(200); // 1000ms çok yavaþtýr, tepki süresi için düþürdüm
   }
}
