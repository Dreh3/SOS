//Código desenvolvido por Andressa Sousa Fonseca
//O onjetivo do presente código é mostrar SOS em código morse a partir de sinalização luminosa

//Importante adicionar as bibliotecas necessárias ao código
#include <stdio.h>
#include "pico/stdlib.h"

//Definir a porta do LED
const uint led_pin_red = 13;
//Definindo valores importantes
#define GAP 125
#define tempoP 200 //tempo do led acesso para pontos
#define tempoT 800 //tempo do led acesso para traços
#define tempoI 250 //tempo de intervalo entre letras

//A primeira função será responsável por fazer o led piscar três vezes por 0,2 no intervalo GAP de 0,125 segundos
//representando assim pontos que simbolizam o S
void sinalPonto(){
    for(int i=0;i<3;i++){
        gpio_put(led_pin_red, true); //liga o led
        printf("."); //imprimir a letra correpondente
        sleep_ms(tempoP); //tempo que fica ligado
        gpio_put(led_pin_red,false);
        printf(" ");
        sleep_ms(GAP); //intervalo entre pontos
    }
}

//A primeira função será responsável por fazer o led piscar três vezes por 0,8 no intervalo GAP de 0,125 segundos
//representando assim traços que simbolizam o O
void sinalTraco(){
    for(int i =0; i<3;i++){
        gpio_put(led_pin_red,true);
        printf("-"); //imprime a letra correpondente
        sleep_ms(tempoT); //tempo que o led fica ligada para traços
        gpio_put(led_pin_red,false);
        printf(" ");
        sleep_ms(GAP); //intervalo entre traços
    }
}

int main()
{
    //Inicializar o pino 13
    gpio_init(led_pin_red);
    //Definir esse pino como uma porta de saída
    gpio_set_dir(led_pin_red, GPIO_OUT);

    //Detalhe extra para imprimir os sinais por monitor
    stdio_init_all();

    while (true) {
        sinalPonto(); //chama a função que fará o led piscar sinalizando S
        sleep_ms(tempoI); //tempo de intervalo entre as letras do SOS
        sinalTraco(); //chama a função que fará o led piscar sinalizando O
        sleep_ms(tempoI);
        sinalPonto();
        sleep_ms(3000); //intervalo para iniciar novo sinal
    }
}
