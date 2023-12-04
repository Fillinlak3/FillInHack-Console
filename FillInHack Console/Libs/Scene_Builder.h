#pragma once
#include <iostream>

class Scene {
public:
	enum class Scene_Selector {
		Login,
		Register,
		ChangeUsername,
		ChangePassword,
		CommandLine,
		BatchMode
	};

public:
	Scene();
	Scene(Scene_Selector scene_selection);
	~Scene();

public:
	void LoginPage();
	void RegisterPage();
	void ChangeUsernamePage();
	void ChangePasswordPage();
	void TerminalPage();
	void BatchMode();

private:
	std::string __getPassword(std::string prompt);
	bool __capture_CTRL_Events(bool __activate_handler);
};