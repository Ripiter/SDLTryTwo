#include "Animation.h"

/// <param name="_rEntity">Entity that the animation is for</param>
/// <param name="_animationSheet">The big image that is going to get cut</param>
/// <param name="_frames">Amount of frames in the animation spread sheet</param>
/// <param name="x">Cut animation sheet every x amount</param>
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
