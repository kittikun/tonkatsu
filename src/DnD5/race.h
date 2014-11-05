// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//
#ifndef RACE_H
#define RACE_H

namespace DnD5
{
	enum class ERace : uint8_t {
		Dwarf,
		Elf,
		Halfling,
		Human
	};

	enum class ESubRaceDwarf : uint8_t {
		Dwarf_Hill,
		Dwarf_Mountain
	};

	enum class ESubRaceElf : uint8_t {
		Elf_High,
		Elf_Wood,
		Elf_Dark
	};

	enum class ESubRaceHalfling : uint8_t {
		Halfling_Lightfoot,
		Halfling_Stout
	};

	class IRace
	{
	public:
		virtual ~IRace() {}
		virtual ERace getRace() = 0;
		virtual uint8_t getSubRace() = 0;
	};

	template <ERace Race, typename SubRace>
	class SpecificRace : public IRace
	{
	public:
		SpecificRace() : eRace(Race)
		{
		}

		ERace getRace() { return eRace; }
		uint8_t getSubRace() { return (uint8_t)eSubRace; }

	private:
		const ERace eRace;
		SubRace eSubRace;
	};

	typedef SpecificRace<ERace::Dwarf, ESubRaceDwarf>  Dwarf;
	typedef SpecificRace<ERace::Elf, ESubRaceElf > Elf;
	typedef SpecificRace<ERace::Halfling, ESubRaceHalfling > Halfling;
} // namespace DnD5

#endif RACE_H