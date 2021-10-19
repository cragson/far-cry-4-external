#pragma once

#include "osmium/Cheat/Feature/feature.hpp"

class ft_norecoil : public feature
{

public:

	void on_first_activation() override;

	void on_enable() override;
	void on_disable() override;

	void tick() override;

private:

	float m_flOldVelocity;
};