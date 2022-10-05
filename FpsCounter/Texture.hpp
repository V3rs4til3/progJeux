///@file Texture.hpp
///@brief Texture
///@author Jeremie Perreault 1751707@etu.cegep-lanaudiere.qc.ca
#pragma once
#include "TTFont.hpp"

/// @brief Classe permettant de gerer les textures
class Texture{
    private:
        SDL_Surface* surface;
        int width, height;
        unsigned int textureId;
    public:
        /// @brief constructeur d'une texture a partir d'une image
        /// @param path emplacement du fichier de texture
        Texture(const char* pathImage){
            surface = IMG_Load(pathImage);
            if(surface == NULL){
                exit(1);
            }
            height = surface->h;
            width = surface->w;
            glGenTextures(1, &textureId);
            glBindTexture(GL_TEXTURE_2D, textureId);

            #ifdef _APPLE_
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
                        0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
            #else
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
                                        0, GL_BGRA /*GL_RGBA*/, GL_UNSIGNED_BYTE, surface->pixels);
            #endif
            
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            SDL_FreeSurface(surface);
        
        }
        /// @brief constructeur d'une texture a partir d'une surface SDL
        /// @param surface 
        Texture(SDL_Surface* surface){
            glGenTextures(1, &textureId);
            glBindTexture(GL_TEXTURE_2D, textureId);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
                                        0, GL_BGRA /*GL_RGBA*/, GL_UNSIGNED_BYTE, surface->pixels);
            
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            SDL_FreeSurface(surface);
        }

        ~Texture(){
            glDeleteTextures(1, &textureId);
        }
        /// @brief fonction retournant l'id de la texture
        /// @return 
        unsigned int getTextureID(){
            return textureId;
        }    

        /// @brief fonction retournant la largeur de la texture
        /// @return la largeur de la texture
        int getHeigth(){
            return height;
        }

        /// @brief fonction retournant la hauteur de la texture
        /// @return la hauteur de la texture
        int getWitdh(){
            return width;
        }
};