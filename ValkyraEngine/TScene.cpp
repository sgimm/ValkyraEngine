#include "TScene.h"


void TScene::Render()
{
}

void TScene::OnMessage(TMessage* message)
{
	TComponent::OnMessage(message);
}

TScene::TScene(TComponent * owner, void * parent, TMiracle* mirc):TComponent(owner, parent, mirc)
{
}


TScene::~TScene()
{
}
