#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class NTexture
{
public:
    //Initializes variables
    NTexture(SDL_Renderer* renderer);

    //Deallocates memory
    ~NTexture();

    //Loads image at specified path
    bool loadFromFile(std::string path);

    //Deallocates texture
    void free();

    // set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    //Renders texture at given point
    void render(int x, int y, SDL_Rect* clip = nullptr);

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    // renderer
    SDL_Renderer* mRenderer;

    //Image dimensions
    int mWidth;
    int mHeight;
};