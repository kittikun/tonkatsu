// Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc.
//

#include "Lore.h"

#include <cstdlib>
#include <vector>

#include "Race.h"

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

		// PlayerDnDBasicRules_v0.2 p13 (Dwarven Names)
		const std::vector<std::string> DwarvenFemaleNames = {
			"Amber", "Artin", "Audhild", "Bardryn",
			"Dagnal", "Diesa", "Eldeth", "Falkrunn", "Finellen", "Gunnloda",
			"Gurdis", "Helja", "Hlin", "Kathra", "Kristryd", "Ilde", "Liftrasa",
			"Mardred", "Riswynn", "Sannl", "Torbera", "Torgga", "Vistra"
		};

		// PlayerDnDBasicRules_v0.2 p13 (Dwarven Names)
		const std::vector<std::string> DwarvenClanNames = {
			"Balderk", "Battlehammer", "Brawnanvil",
			"Dankil", "Fireforge", "Frostbeard", "Gorunn", "Holderhek",
			"Ironfist", "Loderr", "Lutgehr", "Rumnaheim", "Strakeln",
			"Torunn", "Ungart"
		};

		// PlayerDnDBasicRules_v0.2 p14 (Elf Names)
		const std::vector<std::string> ElfMaleNames = {
			"Adran", "Aelar", "Aramil", "Arannis",
			"Aust", "Beiro", "Berrian", "Carric", "Enialis", "Erdan", "Erevan",
			"Galinndan", "Hadarai", "Heian", "Himo", "Immeral", "Ivellios",
			"Laucian", "Mindartis", "Paelias", "Peren", "Quarion", "Riardon",
			"Rolen", "Soveliss", "Thamior", "Tharivol", "Theren", "Varis"
		};

		// PlayerDnDBasicRules_v0.2 p14 (Elf Names)
		const std::vector<std::string> ElfFemaleNames = {
			"Adrie", "Althaea", "Anastrianna",
			"Andraste", "Antinua", "Bethrynna", "Birel", "Caelynn",
			"Drusilia", "Enna", "Felosial", "Ielenia", "Jelenneth", "Keyleth",
			"Leshanna", "Lia", "Meriele", "Mialee", "Naivara", "Quelenna",
			"Quillathe", "Sariel", "Shanairra", "Shava", "Silaqui",
			"Theirastra", "Thia", "Vadania", "Valanthe", "Xanaphia"
		};

		// PlayerDnDBasicRules_v0.2 p15 (Elf Names)
		const std::vector<std::string> ElfFamilyNames = {
			"Amakiir (Gemflower)", "Amastacia(Starflower)", "Galanodel (Moonwhisper)",
			"Holimion(Diamonddew)", "Ilphelkiir (Gemblossom)", "Liadon(Silverfrond)",
			"Meliamne (Oakenheel)", "Naïlo(Nightbreeze)", "Siannodel (Moonbrook)",
			"Xiloscient(Goldpetal)"
		};

		// PlayerDnDBasicRules_v0.2 p16 (Halfling Names)
		const std::vector<std::string> HalflingMaleNames = {
			"Alton", "Ander", "Cade", "Corrin", "Eldon", "Errich",
			"Finnan", "Garret", "Lindal", "Lyle", "Merric", "Milo", "Osborn",
			"Perrin", "Reed", "Roscoe", "Wellby"
		};

		// PlayerDnDBasicRules_v0.2 p16 (Halfling Names)
		const std::vector<std::string> HalflingFemaleNames = {
			"Alton", "Ander", "Cade", "Corrin", "Eldon", "Errich",
			"Finnan", "Garret", "Lindal", "Lyle", "Merric", "Milo", "Osborn",
			"Perrin", "Reed", "Roscoe", "Wellby"
		};

		// PlayerDnDBasicRules_v0.2 p16 (Halfling Names)
		const std::vector<std::string> HalflingFamilyNames = {
			"Brushgather", "Goodbarrel", "Greenbottle",
			"High - hill", "Hilltopple", "Leagallow", "Tealeaf", "Thorngage",
			"Tosscobble", "Underbough"
		};

		// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
		const std::vector<std::string> HumanCalishiteMaleNames = {
			"Aseir", "Bardeid", "Haseid",
			"Khemed", "Mehmen", "Sudeiman", "Zasheir"
		};

		// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
		const std::vector<std::string> HumanCalishiteFemaleNames = {
			"Atala", "Ceidil", "Hama", "Jasmal", "Meilil", "Seipora", "Yasheira",
			"Zasheida"
		};

		// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
		const std::vector<std::string> HumanCalishiteFamilyNames = {
			"Basha", "Dumein", "Jassan", "Khalid",
			"Mostana", "Pashar", "Rein"
		};

		// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
		const std::vector<std::string> HumanChondathanMaleNames = {
			"Darvin", "Dorn", "Evendur",
			"Gorstag", "Grim", "Helm", "Malark", "Morn", "Randal",
			"Stedd"
		};

		// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
		const std::vector<std::string> HumanChondathanFemaleNames = {
			"Arveene", "Esvele", "Jhessail", "Kerri",
			"Lureene", "Miri", "Rowan", "Shandri", "Tessele"
		};

		// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
		const std::vector<std::string> HumanChondathanFamilyNames = {
			"Amblecrown", "Buckman", "Dundragon", "Evenwood",
			"Greycastle", "Tallstag"
		};

		// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
		const std::vector<std::string> HumanDamaranMaleNames = {
			"Bor", "Fodel", "Glar", "Grigor",
			"Igan", "Ivor", "Kosef", "Mival", "Orel", "Pavel", "Sergor"
		};

		// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
		const std::vector<std::string> HumanDamaranFemaleNames = {
			"Alethra", "Kara", "Katernin", "Mara", "Natali", "Olma", "Tana",
			"Zora"
		};

		// PlayerDnDBasicRules_v0.2 p18 (Human Names and Ethnicities)
		const std::vector<std::string> HumanDamaranFamilyNames = {
			"Bersk", "Chernin", "Dotsk", "Kulenov",
			"Marsk", "Nemetsk", "Shemov", "Starag"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanIlluskanMaleNames = {
			"Ander", "Blath", "Bran", "Frath",
			"Geth", "Lander", "Luth", "Malcer", "Stor", "Taman", "Urth"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanIlluskanFemaleNames = {
			"Amafrey", "Betha", "Cefrey", "Kethra", "Mara", "Olga",
			"Silifrey", "Westra"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanIlluskanFamilyNames = {
			"Brightwood", "Helder",
			"Hornraven", "Lackman", "Stormwind", "Windrivver"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanMulanMaleNames = {
			"Aoth", "Bareris", "Ehput - Ki",
			"Kethoth", "Mumed", "Ramas", "So - Kehur", "Thazar - De",
			"Urhur"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanMulanFemaleNames = {
			"Arizima", "Chathi", "Nephis", "Nulara",
			"Murithi", "Sefris", "Thola", "Umara", "Zolis"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanMulanFamilyNames = {
			"Ankhalab", "Anskuld", "Fezim", "Hahpet", "Nathandem",
			"Sepret", "Uuthrakt"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanRashemiMaleNames = {
			"Borivik", "Faurgar", "Jandar",
			"Kanithar", "Madislak", "Ralmevik", "Shaumar", "Vladislak"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanRashemiFemaleNames = {
			"Fyevarra", "Hulmarra", "Immith", "Imzel",
			"Navarra", "Shevarra", "Tammith", "Yuldra"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanRashemiFamilyNames = {
			"Chergoba", "Dyernina", "Iltazyara", "Murnyethara",
			"Stayanoga", "Ulmokina"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanShouMaleNames = {
			"An", "Chen", "Chi", "Fai", "Jiang", "Jun",
			"Lian", "Long", "Meng", "On", "Shan", "Shui", "Wen"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanShouFemaleNames = {
			"Bai", "Chao", "Jia", "Lei", "Mei", "Qiao", "Shui", "Tai"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanShouFamilyNames = {
			"Chien", "Huang", "Kao", "Kung", "Lao", "Ling", "Mei", "Pin", "Shin",
			"Sum", "Tan", "Wan"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanTuramiMaleNames = {
			"Anton", "Diero", "Marcon", "Pieron",
			"Rimardo", "Romero", "Salazar", "Umbero"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanTuramiFemaleNames = {
			"Balama", "Dona", "Faila", "Jalana", "Luisa", "Marta", "Quara",
			"Selise", "Vonda"
		};

		// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
		const std::vector<std::string> HumanTuramiFamilyNames = {
			"Agosto", "Astorio", "Calabra", "Domine",
			"Falone", "Marivaldi", "Pisacar", "Ramondo"
		};

		std::string RandomElement(const std::vector<std::string>& list)
		{
			// Previously used std::mt19937 here but performance was bad and rand() is more than enough for this case
			return list[rand() % list.size()];
		}

		std::string GenerateFirstName(const std::shared_ptr<IRace>& race, bool isMale)
		{
			std::string res;

			switch (race.get()->Race())
			{
			case ERace::Dwarf:
				res = (isMale) ? RandomElement(DwarvenMaleNames) : RandomElement(DwarvenFemaleNames);
				break;

			case ERace::Elf:
				res = (isMale) ? RandomElement(ElfMaleNames) : RandomElement(ElfFemaleNames);
				break;

			case ERace::Halfling:
				res = (isMale) ? RandomElement(HalflingMaleNames) : RandomElement(HalflingFemaleNames);
				break;

			case ERace::Human:
			{
				switch (static_cast<ESubRaceHuman>(race.get()->SubRace()))
				{
				case ESubRaceHuman::Human_Calishite:
					res = (isMale) ? RandomElement(HumanCalishiteMaleNames) : RandomElement(HumanCalishiteFemaleNames);
					break;

				case ESubRaceHuman::Human_Chondathan:
					res = (isMale) ? RandomElement(HumanChondathanMaleNames) : RandomElement(HumanChondathanFemaleNames);
					break;

				case ESubRaceHuman::Human_Damaran:
					res = (isMale) ? RandomElement(HumanDamaranMaleNames) : RandomElement(HumanDamaranFemaleNames);
					break;

				case ESubRaceHuman::Human_Illuskan:
					res = (isMale) ? RandomElement(HumanIlluskanMaleNames) : RandomElement(HumanIlluskanFemaleNames);
					break;

				case ESubRaceHuman::Human_Mulan:
					res = (isMale) ? RandomElement(HumanMulanMaleNames) : RandomElement(HumanMulanFemaleNames);
					break;

				case ESubRaceHuman::Human_Rashemi:
					res = (isMale) ? RandomElement(HumanRashemiMaleNames) : RandomElement(HumanRashemiFemaleNames);
					break;

				case ESubRaceHuman::Human_Shou:
					res = (isMale) ? RandomElement(HumanRashemiMaleNames) : RandomElement(HumanRashemiFemaleNames);
					break;

					// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
					// Tethyrians primarily use Chondathan names.
				case ESubRaceHuman::Human_Tethyrian:
					res = (isMale) ? RandomElement(HumanChondathanMaleNames) : RandomElement(HumanChondathanFemaleNames);
					break;

				case ESubRaceHuman::Human_Turami:
					res = (isMale) ? RandomElement(HumanTuramiMaleNames) : RandomElement(HumanTuramiFemaleNames);
					break;

				default:
					break;
				}

				break;
			}

			default:
				break;
			}

			return res;
		}

		std::string GenerateLastName(const std::shared_ptr<IRace>& race)
		{
			std::string res;

			switch (race.get()->Race())
			{
			case ERace::Dwarf:
				res = RandomElement(DwarvenClanNames);
				break;

			case ERace::Elf:
				res = RandomElement(ElfFamilyNames);
				break;

			case ERace::Halfling:
				res = RandomElement(HalflingFamilyNames);

			case ERace::Human:
			{
				switch (static_cast<ESubRaceHuman>(race.get()->SubRace()))
				{
				case ESubRaceHuman::Human_Calishite:
					res = RandomElement(HumanCalishiteFamilyNames);
					break;

				case ESubRaceHuman::Human_Chondathan:
					res = RandomElement(HumanChondathanFamilyNames);
					break;

				case ESubRaceHuman::Human_Damaran:
					res = RandomElement(HumanDamaranFamilyNames);
					break;

				case ESubRaceHuman::Human_Illuskan:
					res = RandomElement(HumanIlluskanFamilyNames);
					break;

				case ESubRaceHuman::Human_Mulan:
					res = RandomElement(HumanMulanFamilyNames);
					break;

				case ESubRaceHuman::Human_Rashemi:
					res = RandomElement(HumanRashemiFamilyNames);
					break;

				case ESubRaceHuman::Human_Shou:
					res = RandomElement(HumanShouFamilyNames);
					break;

					// PlayerDnDBasicRules_v0.2 p19 (Human Names and Ethnicities)
					// Tethyrians primarily use Chondathan names.
				case ESubRaceHuman::Human_Tethyrian:
					res = RandomElement(HumanChondathanFamilyNames);
					break;

				case ESubRaceHuman::Human_Turami:
					res = RandomElement(HumanTuramiFamilyNames);
					break;

				default:
					break;
				}

				break;
			}

			default:
				break;
			}

			return res;
		}
	} // namespace Lore
} // namespace DnD5