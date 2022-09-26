/// @file Matrix44d.hpp
/// @brief definition de la classe Matrix44d
/// @author Jérémie Perreault

#define e11 elements[0]
#define e12 elements[1]
#define e13 elements[2]
#define e14 elements[3]
#define e21 elements[4]
#define e22 elements[5]
#define e23 elements[6]
#define e24 elements[7]
#define e31 elements[8]
#define e32 elements[9]
#define e33 elements[10]
#define e34 elements[11]
#define e41 elements[12]
#define e42 elements[13]
#define e43 elements[14]
#define e44 elements[15]

/// @brief Matrix 4x4
class Matrix44d {
public:
    double elements[16];

    /// @brief 
    /// charge une matrice carré 4x4 dont tous les éléments de sa diagonale sont 1 et les autres 0 (matrice identité)
    void loadIdentity() {
        e11 = e22 = e33 = e44 = 1.0;
        e12 = e13 = e14 = e21 = e23 = e24 = e31 = e32 = e34 = e41 = e42 = e43 = 0.0;
    }

    /// @brief charge une matrice de mise a l'échelle
    /// @param x mise a l'échelle en x
    /// @param y mise a l'échelle en y
    /// @param z mise a l'échelle en z
    void loadEchelle(int x = 0, int y = 0, int z = 0){
        e11 = x;
        e22 = y;
        e33 = z;
        e12 = e13 = e14 = e21 = e23 = e24 = e31 = e32 = e34 = e41 = e42 = e43 = 0.0;
    }

    /// @brief 
    /// matrice de rotation sur l'axe x
    /// @param angleX angle de rotation en x
    void loadRotationX(double angleX){
        e11 = 1;
        e12 = e13 = e14 = e21 = e24 = e31 = e34 = e41 = e42 = e43 = e44 = 0.0;
        e22 = e33 = cos(angleX);
        e23 = -sin(angleX);
        e32 = sin(angleX);
    }

    /// @brief
    /// matrice de rotation sur l'axe y
    /// @param angleY angle de rotation en y
    void loadRotationY(double angleY){
        e22 = 1;
        e12 = e13 = e14 = e21 = e24 = e31 = e34 = e41 = e42 = e43 = e44 = 0.0;
        e11 = e33 = cos(angleY);
        e13 = sin(angleY);
        e31 = -sin(angleY);
    }

    /// @brief
    /// matrice de rotation sur l'axe z
    /// @param angleZ angle de rotation en z
    void loadRotationZ(double angleZ){
        e33 = 1;
        e12 = e13 = e14 = e21 = e24 = e31 = e34 = e41 = e42 = e43 = e44 = 0.0;
        e11 = e22 = cos(angleZ);
        e12 = -sin(angleZ);
        e21 = sin(angleZ);
    }

    /// @brief
    /// matrice de rotation arbitraire unitaire
    /// @param v vecteur unitaire de rotation
    /// @param angle angle de rotation
    void loadRotationOnNormalizeAxis(Vecteur3d axis, double angle){
        double c = cos(angle);
        double s = sin(angle);
        double t = 1 - c;
        double x = axis.x;
        double y = axis.y;
        double z = axis.z;

        e11 = t * x * x + c;
        e12 = t * x * y - s * z;
        e13 = t * x * z + s * y;

        e21 = t * x * y + s * z;
        e22 = t * y * y + c;
        e23 = t * y * z - s * x;

        e31 = t * x * z - s * y;
        e32 = t * y * z + s * x;
        e33 = t * z * z + c;

        e14 = e24 = e34 = e41 = e42 = e43 = 0.0;
        e44 = 1.0;
    }

    /// @brief
    /// matrice de rotation arbitraire
    /// @param v vecteur de rotation
    /// @param angle angle de rotation
    void loadRotationOnAxis(Vecteur3d* axis, double angle){
        if((axis->x * axis->x + axis->y * axis->y + axis->z * axis->z) != 1){
            axis->setNormalize();
        }
        loadRotationOnNormalizeAxis(*axis, angle);
    }

};