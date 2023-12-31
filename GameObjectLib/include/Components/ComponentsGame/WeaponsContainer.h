#pragma once
#include "Component.h"
#include "Components/ComponentsGame/Weapon.h"

class WeaponsContainer : public Component
{
public:

	WeaponsContainer();

	void AddNewWeapon(GameObject* _weapon);
	GameObject* GetWeaponByIndex(const unsigned int& _index) const;
	GameObject* GetWeaponByName(const std::string& _name) const;

	void ChangeWeaponByName(const std::string& _name);
	void ChangeWeaponByIndex(const int& _index);
	void ChangeWeaponByIndex(const size_t& _index);
	void ChangeWeapon();

	inline GameObject* GetArme() { return weapon; }
	inline void SetArme(GameObject* _arme) { weapon = _arme; }

	inline size_t GetNumberWeapons() const { return weapons.size(); }
	inline size_t GetIndexActualWeapon() const { return actualWeaponIndex; }

private:
	std::vector<GameObject*> weapons;
	GameObject* weapon;
	size_t actualWeaponIndex = 0;
};

