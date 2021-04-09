#include "Button.h"

Button::Button(char* _entityName, TextImage* _img, float _x, float _y) : RenderEntity::RenderEntity(_entityName, _img, _x, _y)
{

}

void Button::ButtonEvent(int x, int y)
{
	float w = entityImg->GetWidth();
	float h = entityImg->GetHeight();

	if (x > position->x && (position->x + w) > x && y > position->y && (position->y + h) > y) {
		OnClick();
	}
}

void Button::OnClick()
{
	//TextImage* t = (TextImage*)entityImg;
	
    std::cout << entityName << " was pressed" << std::endl;
}

void Button::Update()
{

}
