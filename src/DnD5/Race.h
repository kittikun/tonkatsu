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
        virtual ERace getRace() const = 0;
        virtual int8_t getSubRace() const = 0;
    };

    template <ERace r>
    class GeneralRace final : public IRace
    {
    public:
        explicit GeneralRace() : race(r) {}
        GeneralRace(const GeneralRace& other) : race(other.race) {}
        GeneralRace(GeneralRace&& other) : race(other.race) {}
        ~GeneralRace() {}

        GeneralRace & operator=(const GeneralRace& other)
        {
            GeneralRace tmp(other);
            *this = std::move(tmp);
            return *this;
        }

        GeneralRace& operator= (GeneralRace&& other)
        {
            if (this != &other)
            {
                std::move(race, other.race);
                return *this;
            }
        }

        virtual ERace getRace() const { return race; }
        virtual int8_t getSubRace() const override { return -1; }

    private:
        const ERace race;
    };

    template <ERace r, typename SubRace, SubRace s>
    class SpecificRace final : public IRace
    {
    public:
        explicit SpecificRace() : race(r), subRace(s) {}
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

        ERace getRace() const { return race; }
        int8_t getSubRace() const { return (int8_t)subRace; }

    private:
        const ERace race;
        const SubRace subRace;
    };

    typedef GeneralRace<ERace::Human>  Human;
    typedef SpecificRace<ERace::Dwarf, ESubRaceDwarf, ESubRaceDwarf::Dwarf_Hill>  HillDwarf;
    typedef SpecificRace<ERace::Dwarf, ESubRaceDwarf, ESubRaceDwarf::Dwarf_Mountain>  MountainDwarf;
    typedef SpecificRace<ERace::Elf, ESubRaceElf, ESubRaceElf::Elf_Dark> DarkElf;
    typedef SpecificRace<ERace::Elf, ESubRaceElf, ESubRaceElf::Elf_High> HighElf;
    typedef SpecificRace<ERace::Elf, ESubRaceElf, ESubRaceElf::Elf_Wood> WoodElf;
    typedef SpecificRace<ERace::Halfling, ESubRaceHalfling, ESubRaceHalfling::Halfling_Lightfoot> LightfootHalfling;
    typedef SpecificRace<ERace::Halfling, ESubRaceHalfling, ESubRaceHalfling::Halfling_Stout> StoutHalfling;
} // namespace DnD5

#endif // RACE_H
