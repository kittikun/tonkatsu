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

#include "../data.h"
#include "../impl/perk_impl.h"

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>

namespace Dominion
{
	Perk::Perk() :
		impl_(new PerkImpl())
	{
	}

	Perk::~Perk()
	{
	}

	const boost::uuids::uuid& Perk::guid() const
	{
		return impl_->guid();
	}

	EPerkType Perk::type() const
	{
		return impl_->type_;
	}

	void Perk::set_type(EPerkType type)
	{
		impl_->type_ = type;
	}

	template <class Archive>
	void Perk::serialize(Archive& ar)
	{
		ar(CEREAL_NVP(impl_));
	}

	template void DOMINION_API Perk::serialize(cereal::JSONOutputArchive&);
	template void DOMINION_API Perk::serialize(cereal::JSONInputArchive&);
} // namespace Dominion