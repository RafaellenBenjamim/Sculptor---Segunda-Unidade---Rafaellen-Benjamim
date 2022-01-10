#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
  float r,g,b; // Cores
  float a; // Transparencia
  bool isOn; // Incluido ou nao
};

class Sculptor {

private:
  Voxel ***vox; // Matriz 3D, um asterisco para cada dimensão
  float lado;
  int nx,ny,nz; // Eixos - Dimensões
  float r,g,b,a; // Definir as cores e transparência

public:
  Sculptor(int _nx = 0, int _ny = 0, int _nz = 0); //Construtor da classe
  ~Sculptor(); // Destrutor da classe
  void setColor(float _r = 0, float _g = 0, float _b = 0, float alpha = 0); // Define a cor atual de desenho.
  void putVoxel(int x0 = 0, int y0 = 0, int z0 = 0); // Ativa o voxel na posição (x,y,z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho
  void cutVoxel(int x0 = 0, int y0 = 0, int z0 = 0); // Desativa o voxel na posição (x,y,z) (fazendo isOn = false)
  void putBox(int x0 = 0, int x1 = 0, int y0 = 0, int y1 = 0, int z0 = 0, int z1 = 0); // Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
  void cutBox(int x0 = 0, int x1 = 0, int y0 = 0, int y1 = 0, int z0 = 0, int z1 = 0); // Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
  void putSphere(int xc = 0, int yc = 0, int zc = 0, int raio = 0); // Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a)
  void cutSphere(int xc = 0, int yc = 0, int zc = 0, int raio = 0); // Desativa todos os voxels que satisfazem à equação da esfera
  void putEllipsoid(int xc = 0, int yc = 0, int zc = 0, int rx = 0, int ry = 0, int rz = 0); // Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho
  void cutEllipsoid(int xc = 0, int yc = 0, int zc = 0, int rx = 0, int ry = 0, int rz = 0); // Desativa todos os voxels que satisfazem à equação do elipsóide
  void writeOFF(char* filename); // grava a escultura no formato OFF no arquivo filename

};

#endif /* SCULPTOR_H */
