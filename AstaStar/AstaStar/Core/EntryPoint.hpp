#pragma once
#include "Logger.hpp"
#include "Application.hpp"

extern AstaStar::Application* AstaStar::createApplication();

int main(int argc, char** argv)
{
    AstaStar::Logger::init();
    AS_INFO("Initialized Logger!");

    AstaStar::Application* app = AstaStar::createApplication();

    app->run();

    delete app;

    AS_INFO("AstaStar exit.");
    return 0;
}

#define AS_APP(APP) AstaStar::Application* AstaStar::createApplication()   \
{                                                                           \
	return new APP();                                                       \
}