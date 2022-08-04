#pragma once

#include "Core.h"

namespace yoi {

	class YOI_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//to be defined in client
	Application* CreateApplication();
}
