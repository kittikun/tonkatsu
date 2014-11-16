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

#include "attributes.h"

#include <iterator>
#include <algorithm>
#include <numeric>

#include "../dice.h"

namespace Dominion
{
	class Attributes::AttributesImpl
	{
	public:
		AttributesImpl(AttributeArray a) :
			attributes_(a)
		{
		}

		AttributesImpl(const AttributesImpl&) = delete;
		AttributesImpl& operator=(const AttributesImpl&) = delete;

		const uint8_t Agility() const { return attributes_[EAttribute::Agility]; }
		const uint8_t Intuition() const { return attributes_[EAttribute::Intuition]; }
		const uint8_t Intellect() const { return attributes_[EAttribute::Intellect]; }
		const uint8_t Luck() const { return attributes_[EAttribute::Luck]; }
		const uint8_t Stamina() const { return attributes_[EAttribute::Stamina]; }
		const uint8_t Vigour() const { return attributes_[EAttribute::Vigour]; }

	private:
		AttributeArray attributes_;
	};

	//----------------------------------------------------------------------------------------------
	// ABILITIES
	//----------------------------------------------------------------------------------------------
	Attributes::Attributes(AttributeArray a) :
		impl_(new AttributesImpl(a))
	{
	}

	Attributes::~Attributes()
	{
	}

	AttributeArray Attributes::GetBaseAttributes()
	{
		AttributeArray attributes;

		attributes.fill(1);

		return attributes;
	}

	AttributePointsRemainder Attributes::GetAttributeRoll(const std::shared_ptr<Dice>& dice)
	{
		std::array < uint8_t, 3 >  res;

		res.fill(dice.get()->Roll());

		const uint8_t sum = std::accumulate(std::begin(res), std::end(res), uint8_t(0));

		return std::make_tuple(sum / 3, sum % 3);
	}
} // namespace Dominion