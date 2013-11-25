#include "Input.h"

Input::Input(void)
{
}

Input::~Input(void)
{
}

void Input::handleInput(sf::RenderWindow& mainWindow, DataStore& data)
{
	sf::Event input;
    while (mainWindow.GetEvent(input))
    {
        if (input.Type == sf::Event::Closed) //window closed
            mainWindow.Close();
		else if (input.Type == sf::Event::KeyPressed) //key pressed
			keyPress(input, mainWindow, data);
		else if (input.Type == sf::Event::KeyReleased) //key released
			keyRelease(input, mainWindow, data);
		else if (input.Type == sf::Event::MouseButtonPressed) //mouse button pressed
			mousePress(input, mainWindow, data);
		else if (input.Type == sf::Event::MouseButtonReleased) //mouse button released
			mouseRelease(input, mainWindow, data);
		else if (input.Type == sf::Event::MouseMoved) //mouse moved
		{
			data.mousePos[0] = input.MouseMove.X;
			data.mousePos[1] = input.MouseMove.Y;
			data.updateCursor();
		}
    }
}

void Input::keyPress(sf::Event& input, sf::RenderWindow& mainWindow, DataStore& data)
{
	switch (input.Key.Code)
	{
		case sf::Key::A:
			data.Key.A = true;
			break;
		case sf::Key::B:
			data.Key.B = true;
			break;
		case sf::Key::C:
			data.Key.C = true;
			break;
		case sf::Key::D:
			data.Key.D = true;
			break;
		case sf::Key::E:
			data.Key.E = true;
			break;
		case sf::Key::F:
			data.Key.F = true;
			break;
		case sf::Key::G:
			data.Key.G = true;
			break;
		case sf::Key::H:
			data.Key.H = true;
			break;
		case sf::Key::I:
			data.Key.I = true;
			break;
		case sf::Key::J:
			data.Key.J = true;
			break;
		case sf::Key::K:
			data.Key.K = true;
			break;
		case sf::Key::L:
			data.Key.L = true;
			break;
		case sf::Key::M:
			data.Key.M = true;
			break;
		case sf::Key::N:
			data.Key.N = true;
			break;
		case sf::Key::O:
			data.Key.O = true;
			break;
		case sf::Key::P:
			data.Key.P = true;
			break;
		case sf::Key::Q:
			data.Key.Q = true;
			break;
		case sf::Key::R:
			data.Key.R = true;
			break;
		case sf::Key::S:
			data.Key.S = true;
			break;
		case sf::Key::T:
			data.Key.T = true;
			break;
		case sf::Key::U:
			data.Key.U = true;
			break;
		case sf::Key::V:
			data.Key.V = true;
			break;
		case sf::Key::W:
			data.Key.W = true;
			break;
		case sf::Key::X:
			data.Key.X = true;
			break;
		case sf::Key::Y:
			data.Key.Y = true;
			break;
		case sf::Key::Z:
			data.Key.Z = true;
			break;
		case sf::Key::Num0:
			data.Key.Num0 = true;
			break;
		case sf::Key::Num1:
			data.Key.Num1 = true;
			break;
		case sf::Key::Num2:
			data.Key.Num2 = true;
			break;
		case sf::Key::Num3:
			data.Key.Num3 = true;
			break;
		case sf::Key::Num4:
			data.Key.Num4 = true;
			break;
		case sf::Key::Num5:
			data.Key.Num5 = true;
			break;
		case sf::Key::Num6:
			data.Key.Num6 = true;
			break;
		case sf::Key::Num7:
			data.Key.Num7 = true;
			break;
		case sf::Key::Num8:
			data.Key.Num8 = true;
			break;
		case sf::Key::Num9:
			data.Key.Num9 = true;
			break;
		case sf::Key::Escape:
			data.Key.Escape = true;

			mainWindow.Close();

			break;
		case sf::Key::LControl:
			data.Key.LControl = true;
			break;
		case sf::Key::LShift:
			data.Key.LShift = true;
			break;
		case sf::Key::LAlt:
			data.Key.LAlt = true;
			break;
		case sf::Key::LSystem:
			data.Key.LSystem = true;
			break;
		case sf::Key::RControl:
			data.Key.RControl = true;
			break;
		case sf::Key::RShift:
			data.Key.RShift = true;
			break;
		case sf::Key::RAlt:
			data.Key.RAlt = true;
			break;
		case sf::Key::RSystem:
			data.Key.RSystem = true;
			break;
		case sf::Key::Menu:
			data.Key.Menu = true;
			break;
		case sf::Key::LBracket:
			data.Key.LBracket = true;
			break;
		case sf::Key::RBracket:
			data.Key.RBracket = true;
			break;
		case sf::Key::SemiColon:
			data.Key.SemiColon = true;
			break;
		case sf::Key::Comma:
			data.Key.Comma = true;
			break;
		case sf::Key::Period:
			data.Key.Period = true;
			break;
		case sf::Key::Quote:
			data.Key.Quote = true;
			break;
		case sf::Key::Slash:
			data.Key.Slash = true;
			break;
		case sf::Key::BackSlash:
			data.Key.BackSlash = true;
			break;
		case sf::Key::Tilde:
			data.Key.Tilde = true;

			if (data.settings.debugOn)
				data.settings.debugOn = false;
			else
				data.settings.debugOn = true;

			break;
		case sf::Key::Equal:
			data.Key.Equal = true;
			break;
		case sf::Key::Dash:
			data.Key.Dash = true;
			break;
		case sf::Key::Space:
			data.Key.Space = true;
			break;
		case sf::Key::Return:
			data.Key.Return = true;
			break;
		case sf::Key::Back:
			data.Key.Back = true;
			break;
		case sf::Key::Tab:
			data.Key.Tab = true;
			break;
		case sf::Key::PageUp:
			data.Key.PageUp = true;
			break;
		case sf::Key::PageDown:
			data.Key.PageDown = true;
			break;
		case sf::Key::End:
			data.Key.End = true;
			break;
		case sf::Key::Home:
			data.Key.Home = true;
			break;
		case sf::Key::Insert:
			data.Key.Insert = true;
			break;
		case sf::Key::Delete:
			data.Key.Delete = true;
			break;
		case sf::Key::Add:
			data.Key.Add = true;
			break;
		case sf::Key::Subtract:
			data.Key.Subtract = true;
			break;
		case sf::Key::Multiply:
			data.Key.Multiply = true;
			break;
		case sf::Key::Divide:
			data.Key.Divide = true;
			break;
		case sf::Key::Left:
			data.Key.Left = true;
			break;
		case sf::Key::Right:
			data.Key.Right = true;
			break;
		case sf::Key::Up:
			data.Key.Up = true;
			break;
		case sf::Key::Down:
			data.Key.Down = true;
			break;
		case sf::Key::Numpad0:
			data.Key.Numpad0 = true;
			break;
		case sf::Key::Numpad1:
			data.Key.Numpad1 = true;
			break;
		case sf::Key::Numpad2:
			data.Key.Numpad2 = true;
			break;
		case sf::Key::Numpad3:
			data.Key.Numpad3 = true;
			break;
		case sf::Key::Numpad4:
			data.Key.Numpad4 = true;
			break;
		case sf::Key::Numpad5:
			data.Key.Numpad5 = true;
			break;
		case sf::Key::Numpad6:
			data.Key.Numpad6 = true;
			break;
		case sf::Key::Numpad7:
			data.Key.Numpad7 = true;
			break;
		case sf::Key::Numpad8:
			data.Key.Numpad8 = true;
			break;
		case sf::Key::Numpad9:
			data.Key.Numpad9 = true;

			if (data.settings.vsyncOn)
			{
				data.settings.vsyncOn = false;
				mainWindow.UseVerticalSync(data.settings.vsyncOn);
			}
			else
			{
				data.settings.vsyncOn = true;
				mainWindow.UseVerticalSync(data.settings.vsyncOn);
			}

			break;
		case sf::Key::F1:
			data.Key.F1 = true;
			break;
		case sf::Key::F2:
			data.Key.F2 = true;
			break;
		case sf::Key::F3:
			data.Key.F3 = true;
			break;
		case sf::Key::F4:
			data.Key.F4 = true;
			break;
		case sf::Key::F5:
			data.Key.F5 = true;
			break;
		case sf::Key::F6:
			data.Key.F6 = true;
			break;
		case sf::Key::F7:
			data.Key.F7 = true;
			break;
		case sf::Key::F8:
			data.Key.F8 = true;
			break;
		case sf::Key::F9:
			data.Key.F9 = true;
			break;
		case sf::Key::F10:
			data.Key.F10 = true;
			break;
		case sf::Key::F11:
			data.Key.F11 = true;

			if (data.settings.fullscreenOn)
			{
				data.settings.fullscreenOn = false;
				mainWindow.Create(sf::VideoMode(data.settings.WIN_WIDTH, data.settings.WIN_HEIGHT, 32), "Athena", sf::Style::Close);
			}
			else
			{
				data.settings.fullscreenOn = true;
				mainWindow.Create(sf::VideoMode(data.settings.WIN_WIDTH, data.settings.WIN_HEIGHT, 32), "Athena", sf::Style::Fullscreen);
			}

			break;
		case sf::Key::F12:
			data.Key.F12 = true;
			break;
		case sf::Key::F13:
			data.Key.F13 = true;
			break;
		case sf::Key::F14:
			data.Key.F14 = true;
			break;
		case sf::Key::F15:
			data.Key.F15 = true;
			break;
		case sf::Key::Pause:
			data.Key.Pause = true;
			break;
	}
}

void Input::keyRelease(sf::Event& input, sf::RenderWindow& mainWindow, DataStore& data)
{
	switch (input.Key.Code)
	{
		case sf::Key::A:
			data.Key.A = false;
			break;
		case sf::Key::B:
			data.Key.B = false;
			break;
		case sf::Key::C:
			data.Key.C = false;
			break;
		case sf::Key::D:
			data.Key.D = false;
			break;
		case sf::Key::E:
			data.Key.E = false;
			break;
		case sf::Key::F:
			data.Key.F = false;
			break;
		case sf::Key::G:
			data.Key.G = false;
			break;
		case sf::Key::H:
			data.Key.H = false;
			break;
		case sf::Key::I:
			data.Key.I = false;
			break;
		case sf::Key::J:
			data.Key.J = false;
			break;
		case sf::Key::K:
			data.Key.K = false;
			break;
		case sf::Key::L:
			data.Key.L = false;
			break;
		case sf::Key::M:
			data.Key.M = false;
			break;
		case sf::Key::N:
			data.Key.N = false;
			break;
		case sf::Key::O:
			data.Key.O = false;
			break;
		case sf::Key::P:
			data.Key.P = false;
			break;
		case sf::Key::Q:
			data.Key.Q = false;
			break;
		case sf::Key::R:
			data.Key.R = false;
			break;
		case sf::Key::S:
			data.Key.S = false;
			break;
		case sf::Key::T:
			data.Key.T = false;
			break;
		case sf::Key::U:
			data.Key.U = false;
			break;
		case sf::Key::V:
			data.Key.V = false;
			break;
		case sf::Key::W:
			data.Key.W = false;
			break;
		case sf::Key::X:
			data.Key.X = false;
			break;
		case sf::Key::Y:
			data.Key.Y = false;
			break;
		case sf::Key::Z:
			data.Key.Z = false;
			break;
		case sf::Key::Num0:
			data.Key.Num0 = false;
			break;
		case sf::Key::Num1:
			data.Key.Num1 = false;
			break;
		case sf::Key::Num2:
			data.Key.Num2 = false;
			break;
		case sf::Key::Num3:
			data.Key.Num3 = false;
			break;
		case sf::Key::Num4:
			data.Key.Num4 = false;
			break;
		case sf::Key::Num5:
			data.Key.Num5 = false;
			break;
		case sf::Key::Num6:
			data.Key.Num6 = false;
			break;
		case sf::Key::Num7:
			data.Key.Num7 = false;
			break;
		case sf::Key::Num8:
			data.Key.Num8 = false;
			break;
		case sf::Key::Num9:
			data.Key.Num9 = false;
			break;
		case sf::Key::Escape:
			data.Key.Escape = false;
			break;
		case sf::Key::LControl:
			data.Key.LControl = false;
			break;
		case sf::Key::LShift:
			data.Key.LShift = false;
			break;
		case sf::Key::LAlt:
			data.Key.LAlt = false;
			break;
		case sf::Key::LSystem:
			data.Key.LSystem = false;
			break;
		case sf::Key::RControl:
			data.Key.RControl = false;
			break;
		case sf::Key::RShift:
			data.Key.RShift = false;
			break;
		case sf::Key::RAlt:
			data.Key.RAlt = false;
			break;
		case sf::Key::RSystem:
			data.Key.RSystem = false;
			break;
		case sf::Key::Menu:
			data.Key.Menu = false;
			break;
		case sf::Key::LBracket:
			data.Key.LBracket = false;
			break;
		case sf::Key::RBracket:
			data.Key.RBracket = false;
			break;
		case sf::Key::SemiColon:
			data.Key.SemiColon = false;
			break;
		case sf::Key::Comma:
			data.Key.Comma = false;
			break;
		case sf::Key::Period:
			data.Key.Period = false;
			break;
		case sf::Key::Quote:
			data.Key.Quote = false;
			break;
		case sf::Key::Slash:
			data.Key.Slash = false;
			break;
		case sf::Key::BackSlash:
			data.Key.BackSlash = false;
			break;
		case sf::Key::Tilde:
			data.Key.Tilde = false;
			break;
		case sf::Key::Equal:
			data.Key.Equal = false;
			break;
		case sf::Key::Dash:
			data.Key.Dash = false;
			break;
		case sf::Key::Space:
			data.Key.Space = false;
			break;
		case sf::Key::Return:
			data.Key.Return = false;
			break;
		case sf::Key::Back:
			data.Key.Back = false;
			break;
		case sf::Key::Tab:
			data.Key.Tab = false;
			break;
		case sf::Key::PageUp:
			data.Key.PageUp = false;
			break;
		case sf::Key::PageDown:
			data.Key.PageDown = false;
			break;
		case sf::Key::End:
			data.Key.End = false;
			break;
		case sf::Key::Home:
			data.Key.Home = false;
			break;
		case sf::Key::Insert:
			data.Key.Insert = false;
			break;
		case sf::Key::Delete:
			data.Key.Delete = false;
			break;
		case sf::Key::Add:
			data.Key.Add = false;
			break;
		case sf::Key::Subtract:
			data.Key.Subtract = false;
			break;
		case sf::Key::Multiply:
			data.Key.Multiply = false;
			break;
		case sf::Key::Divide:
			data.Key.Divide = false;
			break;
		case sf::Key::Left:
			data.Key.Left = false;
			break;
		case sf::Key::Right:
			data.Key.Right = false;
			break;
		case sf::Key::Up:
			data.Key.Up = false;
			break;
		case sf::Key::Down:
			data.Key.Down = false;
			break;
		case sf::Key::Numpad0:
			data.Key.Numpad0 = false;
			break;
		case sf::Key::Numpad1:
			data.Key.Numpad1 = false;
			break;
		case sf::Key::Numpad2:
			data.Key.Numpad2 = false;
			break;
		case sf::Key::Numpad3:
			data.Key.Numpad3 = false;
			break;
		case sf::Key::Numpad4:
			data.Key.Numpad4 = false;
			break;
		case sf::Key::Numpad5:
			data.Key.Numpad5 = false;
			break;
		case sf::Key::Numpad6:
			data.Key.Numpad6 = false;
			break;
		case sf::Key::Numpad7:
			data.Key.Numpad7 = false;
			break;
		case sf::Key::Numpad8:
			data.Key.Numpad8 = false;
			break;
		case sf::Key::Numpad9:
			data.Key.Numpad9 = false;
			break;
		case sf::Key::F1:
			data.Key.F1 = false;
			break;
		case sf::Key::F2:
			data.Key.F2 = false;
			break;
		case sf::Key::F3:
			data.Key.F3 = false;
			break;
		case sf::Key::F4:
			data.Key.F4 = false;
			break;
		case sf::Key::F5:
			data.Key.F5 = false;
			break;
		case sf::Key::F6:
			data.Key.F6 = false;
			break;
		case sf::Key::F7:
			data.Key.F7 = false;
			break;
		case sf::Key::F8:
			data.Key.F8 = false;
			break;
		case sf::Key::F9:
			data.Key.F9 = false;
			break;
		case sf::Key::F10:
			data.Key.F10 = false;
			break;
		case sf::Key::F11:
			data.Key.F11 = false;
			break;
		case sf::Key::F12:
			data.Key.F12 = false;
			break;
		case sf::Key::F13:
			data.Key.F13 = false;
			break;
		case sf::Key::F14:
			data.Key.F14 = false;
			break;
		case sf::Key::F15:
			data.Key.F15 = false;
			break;
		case sf::Key::Pause:
			data.Key.Pause = false;
			break;
}
}

void Input::mousePress(sf::Event& input, sf::RenderWindow& mainWindow, DataStore& data)
{
	switch (input.MouseButton.Button)
	{
		case sf::Mouse::Left:
			data.Mouse.Left = true;
			break;
		case sf::Mouse::Right:
			data.Mouse.Right = true;
			break;
		case sf::Mouse::Middle:
			data.Mouse.Middle = true;
			break;
		case sf::Mouse::XButton1:
			data.Mouse.XButton1 = true;
			break;
		case sf::Mouse::XButton2:
			data.Mouse.XButton2 = true;
			break;
	}
}

void Input::mouseRelease(sf::Event& input, sf::RenderWindow& mainWindow, DataStore& data)
{
	switch (input.MouseButton.Button)
	{
		case sf::Mouse::Left:
			data.Mouse.Left = false;
			break;
		case sf::Mouse::Right:
			data.Mouse.Right = false;
			break;
		case sf::Mouse::Middle:
			data.Mouse.Middle = false;
			break;
		case sf::Mouse::XButton1:
			data.Mouse.XButton1 = false;
			break;
		case sf::Mouse::XButton2:
			data.Mouse.XButton2 = false;
			break;
	}
}