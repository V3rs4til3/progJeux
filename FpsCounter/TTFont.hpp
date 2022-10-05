///@file TTFont.hpp
///@brief TTFont
///@author Jeremie Perreault 1751707@etu.cegep-lanaudiere.qc.ca
#pragma once 

/// @brief Classe permettant de gerer les fonts
class TTFont{
    private:
        TTF_Font* font;
        SDL_Surface* surface;
        int size;
        const char* text;
        const char* fontPath;
        SDL_Color color;

        /// @brief fonction permettant de corriger le bug de font de SDL
        void fixText(){
            unsigned int textureId = surface->w;
            unsigned int realPitch = this->surface->w * this->surface->format->BytesPerPixel;
            unsigned char* srcPointer = (unsigned char*)surface->pixels;
            unsigned char* dstPointer = srcPointer;
            for(size_t i = 0; i < surface->h; i++){
                memmove(dstPointer, srcPointer, realPitch);
                dstPointer += realPitch;
                srcPointer += surface->pitch;
            }
            surface->pitch = realPitch;
        }
    public:
        /// @brief constructeur de la classe TTFont
        /// @param path emplacement du fichier de font
        /// @param size grosseur de la font
        TTFont(const char* path, int size){
            TTF_Init();
            font = TTF_OpenFont(path, size);
        }
        ~TTFont(){
            TTF_CloseFont(font);
        }

        /// @brief fonction permettant de charger la font dans une surface SDL
        /// @param text texte a afficher
        /// @param color couleur du texte
        /// @return la surface contenant la font
        SDL_Surface* renderText(const char* text, SDL_Color color){
            this->text = text;
            this->color = color;
            surface = TTF_RenderText_Blended(font, text, color);
            if(surface == NULL){
                exit(1);
            }
            fixText();
            return surface;
        }
};