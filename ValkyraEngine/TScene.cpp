#include "TScene.h"


void TScene::Render()
{
	m_szClassName = "TScene";
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

const char * TScene::Serialize()
{
	return nullptr;
}
