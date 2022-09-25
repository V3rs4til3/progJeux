/// @file Vecteur3d.hpp
/// @brief definition de la classe Vecteur3d
/// @author Jérémie Perreault

#include <cmath>

/// @brief Vecteur 3D
struct Vecteur3d{
    public :
        double x,y,z;

    /// @brief initialisation vecteur 3d
    /// @param posX position en x (defaut 0)
    /// @param posY position en y (defaut 0)
    /// @param posZ position en z (defaut 0)
    Vecteur3d(int posX = 0, int posY = 0, int posZ = 0){
        x = posX;
        y = posY;
        z = posZ;
    }

    /// @brief calcul de la norme du vecteur
    /// @return norme du vecteur
    double getNorm(){
        return sqrt(x*x + y*y + z*z);
    }

    /// @brief normalisation du vecteur
    void setNormalize(){
        double norm = getNorm();
        x /= norm;
        y /= norm;
        z /= norm;
    }

    /// @brief addition de 2 vecteurs
    /// @param v vecteur a ajouter
    /// @return resultat de l'addition (un 3e vecteur)
    Vecteur3d operator+(Vecteur3d v){
        Vecteur3d res;
        res.x = this->x + v.x;
        res.y = this->y + v.y;
        res.z = this->z + v.z;
        return res;
    }

    /// @brief soustraction de 2 vecteurs
    /// @param v vecteur a soustraire
    /// @return resultat de la soustraction (un 3e vecteur)
    Vecteur3d operator-(Vecteur3d v){
        Vecteur3d res;
        res.x = this->x - v.x;
        res.y = this->y - v.y;
        res.z = this->z - v.z;
        return res;
    }

    /// @brief produit vectoriel de 2 vecteurs
    /// @param v vecteur a multiplier
    /// @return resultat du produit vectoriel (un 3e vecteur)
    Vecteur3d operator*(Vecteur3d v){
        Vecteur3d res;
        res.x = v.y * this->z - v.z * this->y;
        res.y = v.z * this->x - v.x *this->z;
        res.z = v.x * this->y - v.y * this->x;
        return res;
    }

    /// @brief produit scalaire de 2 vecteurs
    /// @param v vecteur a multiplier
    /// @return resultat du produit scalaire
    double operator%(Vecteur3d v){
       return (this->x * v.x + this->y * v.y + this->z * v.z);
    }

    /// @brief produit scalaire d'un vecteur par un scalaire
    /// @param s scalaire a multiplier
    /// @return resultat du produit scalaire
    Vecteur3d operator*(double d){
        Vecteur3d res;
        res.x = this->x * d;
        res.y = this->y * d;
        res.z = this->z * d;
        return res;
    }

    /// @brief angle entre 2 vecteurs
    /// @param v 2e vecteur
    /// @return l'angle entre les 2 vecteurs
    double angleBtw2Vec(Vecteur3d v){
        return acos((*this%v)/(this->getNorm() * v.getNorm()));
    }
};