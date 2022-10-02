#pragma once 

class TTFont{
    private:
        TTF_Font* font;
        SDL_Surface* surface;
    public:
        TTFont(const char* path, int size){
            font = TTF_OpenFont(path, size);
        }
        ~TTFont(){
            TTF_CloseFont(font);
        }
        void renderText(const char* text, SDL_Color color){
            surface = TTF_RenderText_Blended(font, text, color);
            unsigned int realPitch = surface->w * surface->format->BytesPerPixel;
            unsigned char* srcPointer = (unsigned char*)surface->pixels;
            unsigned char* dstPointer = srcPointer;
            for(size_t i = 0; i < surface->h; i++){
                memmove(dstPointer, srcPointer, realPitch);
                dstPointer += realPitch;
                srcPointer += surface->pitch;
            }
            surface->pitch = realPitch;
        }

        void imageTo2D(){
            #ifdef _APPLE_
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
                        0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
            #else
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
                        0, GL_BGRA /*GL_RGBA*/, GL_UNSIGNED_BYTE, surface->pixels);
            #endif
        }

        void freeSurface(){
            SDL_FreeSurface(surface);
        }
};