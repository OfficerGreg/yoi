#include <Yoi.h>

class Sandbox : public yoi::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};


yoi::Application* yoi::CreateApplication() {
	return new Sandbox();
}