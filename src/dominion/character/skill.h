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

#ifndef Skill_H
#define Skill_H

#include <memory>
#include <string>
#include <boost/uuid/uuid.hpp>

#include "../definitions.h"
#include "../platform.h"

namespace Dominion
{
	class SkillImpl;

#ifdef _WIN32
	template class DOMINION_API std::unique_ptr < SkillImpl > ;
#endif

	// (DR3.1.1 p13, 4-4 SkillS)
	class DOMINION_API Skill
	{
		Skill(const Skill&) = delete;
		Skill& operator=(const Skill&) = delete;

	public:
		Skill();
		~Skill();

		const boost::uuids::uuid& guid() const;

		const EAttribute attribute() const;
		void set_attribute(EAttribute);

		const std::string& name() const;
		void set_name(std::string);

		template <class Archive>
		void serialize(Archive&);

	private:
		std::unique_ptr<SkillImpl> impl_;
	};
} // namespace Dominion

#endif // Skill_H