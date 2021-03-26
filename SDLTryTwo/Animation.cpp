#include "Animation.h"

Animation::Animation(RenderEntity* _rEntity, Image* _animationSheet, int _frames, int xPlus)
{
    int xPos = 0;
    frames = _frames;
    animationSheet = _animationSheet;
    currentEnitity = _rEntity;

    for (int i = 0; i < _frames; i++)
    {
        SDL_Rect rect = { xPos, 0, xPlus, _animationSheet->GetHeight() };

        imagesTransform->push_back(rect);

        xPos += xPlus;
    }
}



Animation::~Animation()
{
    imagesTransform->clear();
    delete imagesTransform;
}

void Animation::Update()
{
    currectRect = imagesTransform->at(currectFrame / 4);
    UpdateFrame();
}

void Animation::UpdateFrame()
{
    ++currectFrame;

    //Cycle animation
    if (currectFrame / 4 >= frames)
    {
        currectFrame = 0;
    }
}
