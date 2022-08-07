#pragma once

#ifdef YOI_PLATFORM_WIN

extern yoi::Application* yoi::CreateApplication();

int main(int argc, char** argv) {

	yoi::Log::Init();
	YOI_CORE_ERROR("Initialized Log");
	YOI_CORE_WARN("Initialized Log");
	YOI_CORE_INFO("Initialized Log");


	auto app = yoi::CreateApplication();
	app->Run();
	delete app;

}

#endif
