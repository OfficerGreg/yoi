#pragma once

#ifdef YOI_PLATFORM_WIN

extern yoi::Application* yoi::CreateApplication();

int main(int argc, char** argv) {

	auto app = yoi::CreateApplication();
	app->Run();
	delete app;

}

#endif
