#include "Sculptor.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int main(void){

    Sculptor alien(200, 200, 200);
    // x largura, y altura, z profundidade
    //Pes
    alien.setColor(0.168, 0.233, 0.184, 1);
    alien.putBox(5, 18, 0, 1, 0, 10);

    alien.setColor(0, 0.100, 0.400, 1); //Azul Escuro
    alien.putBox(7, 16, 1, 3, 4, 6);
    alien.cutBox(11, 12, 1, 3, 4, 6); // Separando os pés
    alien.putBox(6, 7, 1, 2, 4, 6);
    alien.putBox(16, 17, 1, 2, 4, 6);   
    
    //Pernas
    alien.setColor(0, 0.180, 1, 1); //Azul Claro
    alien.putBox(7, 16, 3, 8, 4, 6);
    alien.cutBox(11, 12, 3, 8, 4, 6); // Separando os pés
    alien.cutBox(10, 13, 7, 8, 5, 6);

    //Corpo
    alien.setColor(0, 0.180, 1, 1);
    alien.putBox(7, 16, 9, 14, 4, 6);
    alien.cutBox(10, 13, 9, 10, 5, 6);
    
    //Cinto
    alien.setColor(0, 0.100, 0.400, 1);
    alien.putBox(7, 16, 8, 9, 4, 6);
    alien.cutBox(10, 13, 8, 9, 5, 6);
    alien.putEllipsoid(11.5, 8.5, 5, 2, 2, 2);
    alien.cutEllipsoid(11.5, 8.5, 6, 2, 2, 1);
    alien.setColor(0, 0.180, 1, 1);
    alien.putBox(10, 13, 9, 10, 4, 5);
    alien.putBox(10, 13, 7, 8, 4, 5);

    //Cabeca
    alien.setColor(0.180, 1, 0, 1); // Verde Limao
    alien.putEllipsoid(11.5, 18.5, 5, 8, 5, 3);
    alien.cutBox(6, 17, 14, 15, 4, 7);
    
    //Colar
    alien.setColor(0.180, 0, 0.128, 1); // Roxo
    alien.putBox(6, 17, 14, 15, 4, 6);

    //Bracos
    alien.setColor(0, 0.180, 1, 1);
    alien.putBox(3, 7, 10, 13, 4, 6);
    alien.putBox(16, 18, 10, 13, 4, 6);

    //Maos
    alien.setColor(0.180, 1, 0, 1);
    alien.putEllipsoid(2, 11, 5, 2, 2, 2);
    alien.cutEllipsoid(2, 11, 6, 2, 2, 1);
    alien.putEllipsoid(19, 11, 5, 2, 2, 2);
    alien.cutEllipsoid(19, 11, 6, 2, 2, 1);
    alien.putBox(0, 1, 10, 11, 4, 6);
    alien.putBox(0, 1, 12, 13, 4, 6);
    alien.putBox(2, 3, 13, 14, 4, 6);
    alien.putBox(21, 22, 10, 11, 4, 6);
    alien.putBox(21, 22, 12, 13, 4, 6);
    alien.putBox(19, 20, 13, 14, 4, 6);

    //Antena
    alien.setColor(0.180, 1, 0, 1);
    alien.putBox(10, 13, 23, 24, 4, 6);
    alien.putBox(11, 12, 24, 25, 4, 6);
    alien.putSphere(11, 26, 4, 2);
    alien.cutBox(10, 13, 25, 28, 3, 4);
    
    //Orelhas
    alien.setColor(0.180, 1, 0, 1); 
    alien.putBox(2, 4, 17, 20, 4, 6);
    alien.putBox(19, 21, 17, 20, 4, 6);
    alien.putVoxel(2, 20, 4);
    alien.putVoxel(2, 20, 5);
    alien.putVoxel(20, 20, 4);
    alien.putVoxel(20, 20, 5);
    
    //Detalhes do Rosto
    alien.setColor(1, 1, 1, 1);
    alien.putBox(6, 9, 18, 21, 7, 8);
    alien.putBox(10, 13, 19, 22, 7, 8);
    alien.putBox(14, 17, 18, 21, 7, 8);
    alien.setColor(0, 0, 0, 1);
    alien.putVoxel(7, 19, 7);
    alien.putVoxel(11, 20, 7);
    alien.putVoxel(15, 19, 7);
    alien.putBox(10, 13, 16, 17, 7, 8);
    alien.putBox(9, 14, 17, 18, 7, 8);
    
    //Planetinha
    alien.setColor(1, 0.270, 0, 1);
    alien.putBox(13, 15, 11, 13, 5, 6);

    //WriteOff
    alien.writeOFF((char*)"Alien.off");

    Sculptor elipsoide (200, 200, 200);
    elipsoide.setColor(0.185, 0, 0, 1); //Vinho
    elipsoide.putEllipsoid(20, 20, 20, 15, 10, 7);
    elipsoide.writeOFF((char*)"Elipsoide.off");
 
    Sculptor esfera(200, 200, 200);
    esfera.setColor(0, 1, 1, 1); // Azul Clarissimo
    esfera.putSphere(20, 20, 20, 10);
    esfera.writeOFF((char*)"Esfera.off");

    return 0;
}
