// Copyright(C) 2014 kittikun
//
// This program is free software : you can redistribute it and / or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.If not, see <http://www.gnu.org/licenses/>.
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#ifndef RACE_H
#define RACE_H

#include <cstdint>

namespace Dominion
{
	enum class ERace : uint8_t {
		Dwarf,
		Elf,
		Halfling,
		Human,
		Count
	};

	// PlayerDnDBasicRules_v0.2 p13 (Dwarf Traits)
	enum class ESubRaceDwarf : uint8_t {
		Dwarf_Hill,
		Dwarf_Mountain,
		Count
	};

	// PlayerDnDBasicRules_v0.2 p15 (Elf Traits)
	enum class ESubRaceElf : uint8_t {
		Elf_High,
		Elf_Wood,
		Elf_Dark,
		Count
	};

	// PlayerDnDBasicRules_v0.2 p17 (Halfling Traits)
	enum class ESubRaceHalfling : uint8_t {
		Halfling_Lightfoot,
		Halfling_Stout,
		Count
	};

	// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
	enum class ESubRaceHuman : uint8_t {
		Human_Calishite,
		Human_Chondathan,
		Human_Damaran,
		Human_Illuskan,
		Human_Mulan,
		Human_Rashemi,
		Human_Shou,
		Human_Tethyrian,
		Human_Turami,
		Count
	};

	class IRace
	{
	public:
		virtual ~IRace() {}
		virtual ERace Race() const = 0;
		virtual int8_t SubRace() const = 0;
	};

	template <ERace r, typename ESubRace>
	class SpecificRace final : public IRace
	{
	public:
		explicit SpecificRace(ESubRace s) : race(r), subRace(s) {}
		SpecificRace(const SpecificRace& other) : race(other.race), subRace(other.subRace) {}
		SpecificRace(SpecificRace&& other) : race(other.race), subRace(other.subRace) {}
		~SpecificRace() {}

		SpecificRace & operator=(const SpecificRace& other)
		{
			SpecificRace tmp(other);
			*this = std::move(tmp);
			return *this;
		}

		SpecificRace& operator= (SpecificRace&& other)
		{
			if (this != &other)
			{
				std::move(race, other.race);
				std::move(subRace, other.subRace);
				return *this;
			}
		}

		ERace Race() const { return race; }
		int8_t SubRace() const { return (int8_t)subRace; }

	private:
		const ERace race;
		const ESubRace subRace;
	};

	typedef SpecificRace<ERace::Dwarf, ESubRaceDwarf>  Dwarf;
	typedef SpecificRace<ERace::Elf, ESubRaceElf> Elf;
	typedef SpecificRace<ERace::Halfling, ESubRaceHalfling> Halfling;
	typedef SpecificRace<ERace::Human, ESubRaceHuman>  Human;
} // namespace Dominion

#endif // RACE_H
