
#include "stdafx.h"
#include "Window.h"
#include "Execute.h"


int APIENTRY WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE prevInstance,
	_In_ LPSTR lpszCmdParam,
	_In_ int nCmdShow) {
	Window::Create(hInstance, 500, 500);
	Window::Show();

	Settings::Get().SetWindowHandle(Window::global_handle);
	Settings::Get().SetWidth(static_cast<float>(Window::GetWidth()));
	Settings::Get().SetHeight(static_cast<float>(Window::GetHeight()));

	Execute* execute = new Execute();

	while (Window::Update()) {
		execute->Update();
		execute->Render();
	}

	SAFE_DELETE(execute);
	Window::Destroy();

	return 0;
}