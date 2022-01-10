#include "Sculptor.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <math.h>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){ // Construtor

    nx = _nx;
    ny = _ny;
    nz = _nz;

    vox = new Voxel **[nx];

for (int i = 0; i < nx; i++){
    vox[i] = new Voxel*[ny];
    }
    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            vox[i][j] = new Voxel[nz];
        }
    }
    for(int i = 0; i < nx; i++){ // Atribuição dos valores iniciais das cores
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                vox[i][j][k].isOn = false;

                vox[i][j][k].r = 0;
                vox[i][j][k].g = 0;
                vox[i][j][k].b = 0;
                vox[i][j][k].a = 0;
            }
        }
    }
}

Sculptor::~Sculptor(){ // Destrutor - Liberação das memórias
        for(int i = 0; i < nx; i++){
           for (int j = 0; j < ny; j++){
                delete[] vox[i][j];
            }
        }
        for (int i = 0; i < nx; i++){
            delete[] vox[i];
        }
        delete[] vox;

        nx=ny=nz=0;

}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){

    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

void Sculptor::putVoxel(int x0, int y0, int z0){

    vox[x0][y0][z0].isOn = true;
    vox[x0][y0][z0].r = r;
    vox[x0][y0][z0].g = g;
    vox[x0][y0][z0].b = b;
    vox[x0][y0][z0].a = a;

}

void Sculptor::cutVoxel(int x0, int y0, int z0){

    vox[x0][y0][z0].isOn = false;

}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

for (int i = x0; i < x1; i++){
        for (int j = y0; j < y1; j++){
            for (int k = z0; k < z1; k++){

    vox[i][j][k].isOn = true;
    vox[i][j][k].r = r;
    vox[i][j][k].g = g;
    vox[i][j][k].b = b;
    vox[i][j][k].a = a;
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

for (int i = x0; i < x1; i++){
        for (int j = y0; j < y1; j++){
            for (int k = z0; k < z1; k++){

    vox[i][j][k].isOn = false;

            }
        }
    }
}

void Sculptor::putSphere(int xc, int yc, int zc, int raio){

double coordX, coordY, coordZ;
for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
            coordX = ((double)(i - xc)*(double)(i - xc));
            coordY = ((double)(j - yc)*(double)(j - yc));
            coordZ = ((double)(k - zc)*(double)(k - zc));

            if ((coordX + coordY + coordZ) < (raio*raio)){
            vox[i][j][k].isOn = true;
            vox[i][j][k].r = r;
            vox[i][j][k].g = g;
            vox[i][j][k].b = b;
            vox[i][j][k].a = a;
                }
            }
        }   
    }
}

void Sculptor::cutSphere(int xc, int yc, int zc, int raio){
double dx, dy, dz;
for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
            dx = ((double)(i - xc)*(double)(i - xc));
            dy = ((double)(j - yc)*(double)(j - yc));
            dz = ((double)(k - zc)*(double)(k - zc));

            if ((dx + dy + dz) < (raio*raio)){
            vox[i][j][k].isOn = false;
               }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){

double dx, dy, dz;

	for (int i = 0; i < nx; i++){
		for (int j = 0; j < ny; j++){
			for (int k = 0; k < nz; k++) {
				dx = ((double)(i - xc) * (double)(i - xc)) / (rx * rx);
				dy = ((double)(j - yc) * (double)(j - yc)) / (ry * ry);
				dz = ((double)(k - zc) * (double)(k - zc)) / (rz * rz);

				if ((dx + dy + dz) < 1){
				vox[i][j][k].isOn = true;
                vox[i][j][k].r = r;
                vox[i][j][k].g = g;
                vox[i][j][k].b = b;
                vox[i][j][k].a = a;
			          }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){

double dX, dY, dZ;

    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
            dX = ((double)(i - xc) * (double)(i - xc)) / (rx*rx);
            dY = ((double)(j - yc) * (double)(j - yc)) / (ry*ry);
            dZ = ((double)(k - zc) * (double)(k - zc)) / (rz*rz);

            if ((dX + dY + dZ) < 1){
                vox[i][j][k].isOn = false;

                }
            }
        }
    }
}

void Sculptor::writeOFF(char* filename){

ofstream outFile;
	outFile.open(filename);

	int Nvoxel = 0;

	for (int i = 0; i < nx; i++) { // Conta quantos voxels tem no desenho
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (vox[i][j][k].isOn) {
					Nvoxel++;
				}
			}
		}
	}

	outFile << "OFF" << endl << Nvoxel * 8 << " " << Nvoxel * 6 << " " << 0 << endl; // Calcula a quantidade de vertices e faces


	for (int i = 0; i < nx; i++) { // Declarando os pontos centrais de cada voxel
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (vox[i][j][k].isOn) {
					outFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
					outFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
				}
			}
		}
	}

	int vertice = 0;
	outFile << setiosflags(ios::fixed); // Fixa a saida das cores em decimal float <iomanip>

	for (int i = 0; i < nx; i++) { // Declarando as faces
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (vox[i][j][k].isOn) {
					outFile << 4 << " " << vertice + 0 << " " << vertice + 3 << " " << vertice + 2 << " " << vertice + 1 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 4 << " " << vertice + 5 << " " << vertice + 6 << " " << vertice + 7 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 0 << " " << vertice + 1 << " " << vertice + 5 << " " << vertice + 4 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 0 << " " << vertice + 4 << " " << vertice + 7 << " " << vertice + 3 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 3 << " " << vertice + 7 << " " << vertice + 6 << " " << vertice + 2 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 1 << " " << vertice + 2 << " " << vertice + 6 << " " << vertice + 5 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					vertice = vertice + 8;
				}
			}
		}
	}
	outFile.close();
}
