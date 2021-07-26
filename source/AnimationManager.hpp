#pragma once

#include <SFML/Graphics.hpp>

#include <string_view>
#include <vector>
#include <map>

// Brief:
// 
// auto frames = AnimationManager::get("puppy_walk");
// float frames_per_sec = 12;
// 
// Animator animator(frames, frames_per_sec);
// 
// ..
// 
// Play it!
//

class AnimationManager
{
public:
	~AnimationManager() = default;

	// ����� �������� ���������� � ������� � ������� �������� �� ����� ����� ����������
	static const std::vector<sf::IntRect>* get(const std::string_view id);

private:
	AnimationManager();

	// ������ �������� �� ������, ������������� �� �������� ���������������
	// ���������: �������� ��������, ���������� ������
	void createAnimation(const std::string_view title, int duration);

	// ������ �������� �� ������, ������������� �� �������� ��������
	// ���������: �������� ��������, ���������� ������ � ������� � ������
	void createAnimation(const std::string_view title, int columns, int rows);

	std::map<std::string_view, std::vector<sf::IntRect>> m_storage;
};