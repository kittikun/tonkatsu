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

#include "skill.h"

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>

#include "../impl/skill_impl.h"

namespace Dominion
{
	Skill::Skill() :
		impl_(new SkillImpl())
	{
	}

	Skill::~Skill()
	{
	}

	const boost::uuids::uuid& Skill::guid() const
	{
		return impl_->guid();
	}

	const EAttribute Skill::attribute() const
	{
		return impl_->attribute_;
	}

	void Skill::set_attribute(EAttribute attribute)
	{
		impl_->attribute_ = attribute;
	}

	const std::string& Skill::name() const
	{
		return impl_->name_;
	}

	void Skill::set_name(std::string name)
	{
		impl_->name_ = name;
	}

	template <class Archive>
	void Skill::serialize(Archive& ar)
	{
		ar(CEREAL_NVP(impl_));
	}

	template void DOMINION_API Skill::serialize(cereal::JSONOutputArchive&);
	template void DOMINION_API Skill::serialize(cereal::JSONInputArchive&);
} // namespace Dominion