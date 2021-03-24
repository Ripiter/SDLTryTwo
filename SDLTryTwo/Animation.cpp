#include "Animation.h"

Animation::Animation(Image* _imgTexture, int _frames, int xPlus)
{
    int xPos = 0;
    frames = _frames;

    for (int i = 0; i < _frames; i++)
    {
        SDL_Rect rect = { xPos, 0, xPlus, _imgTexture->GetHeight() };

        imagesTransform->push_back(rect);

        xPos += xPlus;
    }
}

Animation::~Animation()
{
    imagesTransform->clear();
    delete imagesTransform;
}
