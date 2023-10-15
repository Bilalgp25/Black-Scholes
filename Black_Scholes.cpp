#include<iostream>
#include<cmath>

float cdf_loi_normale(float x){
  float res = 0.5*(1+erf(x/sqrt(2)));
  return res;}
  float d_image(float S,float E,float t,float r,float sigma) {
  float d = (log(S/E)+(r+((sigma*sigma)/2)))/(sigma*sqrt(t));
  return d;}

float call(float S,float E,float t,float r,float sigma){
 float d1 = d_image(S,E,t,r,sigma);
 float d2 = d1- (sigma * sqrt(t));
 float fimage_un = cdf_loi_normale(d1);
 float fimage_deux = cdf_loi_normale(d2);
 float res = S*fimage_un-E*exp(-r*t)*fimage_deux;
 return res;}

int main() {
    float S = 110.0; //prix de l'action
    float E = 120.0; //prix d'exercice
    float r = 0.1; //taux OAT
    float sigma = 0.5; //volatilite action
    float t = 1.0; // temps restant
    float resultat_black_scholes = call(S,E,t,r,sigma);
    std::cout<<" Le prix de l'option est "<<resultat_black_scholes;
    return 0;}

