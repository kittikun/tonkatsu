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

#include "perk.h"

#include <cereal/types/base_class.hpp>

#include "../data.h"

namespace Dominion
{
	class Perk::PerkImpl : public Data
	{
	public:
		PerkImpl(const PerkImpl&) = delete;
		PerkImpl& operator=(const PerkImpl&) = delete;

		PerkImpl()
		{

		}

		template <class Archive>
		void Serialize(Archive & ar)
		{
			ar(cereal::base_class<Data>(this), type);
		}

		template <class Archive>
		void Deserialize(Archive & ar)
		{
			// We pass this cast to the base type for each base type we
			// need to serialize.  Do this instead of calling serialize functions
			// directly
			ar(cereal::base_class<Data>(this), type);
		}


	private:
		EPerkType type_;
	};

	//----------------------------------------------------------------------------------------------
	// ABILITIES
	//----------------------------------------------------------------------------------------------
	Perk::Perk() :
		impl_(new PerkImpl())
	{
	}

	Perk::~Perk()
	{
	}

} // namespace Dominion