// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#ifndef RACE_H
#define RACE_H

#include <cstdint>

namespace DnD5
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
} // namespace DnD5

#endif // RACE_H
