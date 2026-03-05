 #include <main.h>
 #fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG
 #use delay(clock=4M)
 #use fast_io(b)
 #int_ext
 void dis_kesme(){
 output_b(0x00);
 }
 void main()
 {
 setup_psp(PSP_DISABLED);
 setup_timer_1(T1_DISABLED);
 setup_timer_2(T2_DISABLED,0,1);
 setup_adc_ports(NO_ANALOGS);
 setup_adc(ADC_OFF);
 setup_CCP1(CCP_OFF);
 setup_CCP2(CCP_OFF);


 set_tris_b(0x01);
 output_b(0x02);

 ext_int_edge(H_TO_L);

 enable_interrupts(INT_EXT);
 enable_interrupts(GLOBAL);

 while(true);
 }
