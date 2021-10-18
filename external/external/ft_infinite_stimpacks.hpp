#pragma once

#include "osmium/Cheat/Feature/feature.hpp"
#include <vector>

class ft_infinite_stimpacks : public feature
{

public:

	void on_first_activation() override;

	void on_enable() override;
	void on_disable() override;

	void tick() override;

private:
	std::vector< char > m_vecOriginalBytes;
};
