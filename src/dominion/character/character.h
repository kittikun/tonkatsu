// Copyright(C) 2014 kittikun
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <vector>

#include "../definitions.h"
#include "../platform.h"

namespace Dominion
{
	class CharacterImpl;
	class Perk;
	class Style;

#ifdef _WIN32
	template class DOMINION_API std::shared_ptr < CharacterImpl > ;
#endif

	class DOMINION_API Character
	{
		Character(const Character&) = delete;
		Character& operator=(const Character&) = delete;
		Character(Character&&) = delete;
		Character& operator=(Character&&) = delete;

	public:
		enum class ValidationResult : uint_fast8_t
		{
			// (DR3.1.1 p30, 4-6 STEP FOUR: DETERMINE COMPOSITE STATS
			// (If you are automatically entitled to Favourable Rounding, but your character already
			// got Favourable Rounding from the Character Generation Table, go back and reroll on that table.
			RerollPerk,
			Valid
		};

		Character(const std::shared_ptr<CharacterImpl>&);
		~Character();

		ValidationResult Validate();

		// (DR3.1.1 p26, 4-2 STEP ONE: THINK ABOUT YOUR CHARACTER)
		// What sort of creature do you want to play?
		const ERace race() const;
		void race(const ERace race);

		// (DR3.1.1 p26, 4-2 CHARACTER STYLES)
		// Once you have thought about these questions, you may want to consider
		// some classic RPG character styles.
		std::shared_ptr<Style> style() const;
		void style(const std::shared_ptr<Style>& style);

		// (DR3.1.1 p28, 4-4 STEP TWO: THE CHARACTER GENERATION TABLE)
		// Once you have determined who your character is, you must make a roll
		// on the Character Generation Table.This table give perks to starting characters.
		std::vector<std::shared_ptr<Perk>> perks() const;
		void perk(const uint_fast8_t roll);

	private:
		std::shared_ptr<CharacterImpl> impl_;
	};
} // namespace Dominion

#endif // CHARACTER_H
