// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#include "Lore.h"

#include <random>
#include <vector>

namespace DnD5
{

    namespace Lore
    {
		// PlayerDnDBasicRules_v0.2 p13 (Dwarven Names)
        const std::vector<std::string> DwarvenMaleNames = {
            "Adrik", "Alberich", "Baern", "Barendd", "Brottor",
            "Bruenor", "Dain", "Darrak", "Delg", "Eberk", "Einkil", "Fargrim",
            "Flint", "Gardain", "Harbek", "Kildrak", "Morgran", "Orsik",
            "Oskar", "Rangrim", "Rurik", "Taklinn", "Thoradin", "Thorin",
            "Tordek", "Traubon", "Travok", "Ulfgar", "Veit", "Vondal"
        };

		const std::vector<std::string> DwarvenFemaleNames = {
			"Amber", "Artin", "Audhild", "Bardryn",
			"Dagnal", "Diesa", "Eldeth", "Falkrunn", "Finellen", "Gunnloda",
			"Gurdis", "Helja", "Hlin", "Kathra", "Kristryd", "Ilde", "Liftrasa",
			"Mardred", "Riswynn", "Sannl", "Torbera", "Torgga", "Vistra"
		};

		const std::vector<std::string> DwarvenClanNames = {
			"Balderk", "Battlehammer", "Brawnanvil",
			"Dankil", "Fireforge", "Frostbeard", "Gorunn", "Holderhek",
			"Ironfist", "Loderr", "Lutgehr", "Rumnaheim", "Strakeln",
			"Torunn", "Ungart"
		};

		std::string RandomElement(const std::vector<std::string>& list)
		{
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<> dist(0, (int)list.size() - 1);

			return list[dist(rng)];
		}

		std::string GenerateFirstName(ERace race, bool isMale)
		{
			std::string res;

			switch (race)
			{
				case ERace::Dwarf: {
					res = (isMale) ? RandomElement(DwarvenMaleNames) : RandomElement(DwarvenFemaleNames);
					break;
				}
			}

			return res;
		}

		std::string GenerateLastName(ERace race)
		{
			std::string res;

			switch (race)
			{
				case ERace::Dwarf: {
					res = RandomElement(DwarvenClanNames);
					break;
				}
			}

			return res;
		}
    } // namespace Lore
} // namespace DnD5